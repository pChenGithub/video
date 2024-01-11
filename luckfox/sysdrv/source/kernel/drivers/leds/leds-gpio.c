// SPDX-License-Identifier: GPL-2.0-only
/*
 * LEDs driver for GPIOs
 *
 * Copyright (C) 2007 8D Technologies inc.
 * Raphael Assenat <raph@8d.com>
 * Copyright (C) 2008 Freescale Semiconductor, Inc.
 */
#include <linux/err.h>
#include <linux/gpio.h>
#include <linux/gpio/consumer.h>
#include <linux/kernel.h>
#include <linux/leds.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/property.h>
#include <linux/slab.h>

struct gpio_led_data {
	struct led_classdev cdev;
	struct gpio_desc *gpiod;
	u8 can_sleep;
	u8 blinking;
	gpio_blink_set_t platform_gpio_blink_set;
};

static inline struct gpio_led_data *
			cdev_to_gpio_led_data(struct led_classdev *led_cdev)
{
	return container_of(led_cdev, struct gpio_led_data, cdev);
}

static void gpio_led_set(struct led_classdev *led_cdev,
	enum led_brightness value)
{
	struct gpio_led_data *led_dat = cdev_to_gpio_led_data(led_cdev);
	int level;

	if (value == LED_OFF)
		level = 0;
	else
		level = 1;

	if (led_dat->blinking) {
		led_dat->platform_gpio_blink_set(led_dat->gpiod, level,
						 NULL, NULL);
		led_dat->blinking = 0;
	} else {
		if (led_dat->can_sleep)
			gpiod_set_value_cansleep(led_dat->gpiod, level);
		else
			gpiod_set_value(led_dat->gpiod, level);
	}
}

static int gpio_led_set_blocking(struct led_classdev *led_cdev,
	enum led_brightness value)
{
	gpio_led_set(led_cdev, value);
	return 0;
}

static int gpio_blink_set(struct led_classdev *led_cdev,
	unsigned long *delay_on, unsigned long *delay_off)
{
	struct gpio_led_data *led_dat = cdev_to_gpio_led_data(led_cdev);

	led_dat->blinking = 1;
	return led_dat->platform_gpio_blink_set(led_dat->gpiod, GPIO_LED_BLINK,
						delay_on, delay_off);
}

// blink_set 是 NULL
static int create_gpio_led(const struct gpio_led *template,
	struct gpio_led_data *led_dat, struct device *parent,
	struct fwnode_handle *fwnode, gpio_blink_set_t blink_set)
{
	struct led_init_data init_data = {};
	int ret, state;

    // 之前从设备数读取的参数放在 template,
    // 这里将这些参数,初始化到每个灯的字符设备参数
    // 触发方式
	led_dat->cdev.default_trigger = template->default_trigger;
    // 
	led_dat->can_sleep = gpiod_cansleep(led_dat->gpiod);
	if (!led_dat->can_sleep)
		led_dat->cdev.brightness_set = gpio_led_set;
	else
		led_dat->cdev.brightness_set_blocking = gpio_led_set_blocking;
	led_dat->blinking = 0;
    // blink_set 是 NULL
	if (blink_set) {
		led_dat->platform_gpio_blink_set = blink_set;
		led_dat->cdev.blink_set = gpio_blink_set;
	}
	if (template->default_state == LEDS_GPIO_DEFSTATE_KEEP) {
		state = gpiod_get_value_cansleep(led_dat->gpiod);
		if (state < 0)
			return state;
	} else {
		state = (template->default_state == LEDS_GPIO_DEFSTATE_ON);
	}
	led_dat->cdev.brightness = state ? LED_FULL : LED_OFF;
	if (!template->retain_state_suspended)
		led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
	if (template->panic_indicator)
		led_dat->cdev.flags |= LED_PANIC_INDICATOR;
	if (template->retain_state_shutdown)
		led_dat->cdev.flags |= LED_RETAIN_AT_SHUTDOWN;

    // 设置 gpio 输出,,,根据状态输出高低电平
	ret = gpiod_direction_output(led_dat->gpiod, state);
	if (ret < 0)
		return ret;

    // 如果 平台设备 数据里面有 name ,
	if (template->name) {
        // 使用 平台设备数据 的 name
		led_dat->cdev.name = template->name;
        // 这个最终还是调用 devm_led_classdev_register_ext,,,  
        // init_data 参数为 NULL
		ret = devm_led_classdev_register(parent, &led_dat->cdev);
	} else {
        // 这里是用 fwnode ,替换了 name 的作用
		init_data.fwnode = fwnode;
		ret = devm_led_classdev_register_ext(parent, &led_dat->cdev,
						     &init_data);
	}

	return ret;
}

struct gpio_leds_priv {
	int num_leds;
	struct gpio_led_data leds[];
};

// 创建 设备驱动 私有数据,
// 遍历设备树配置的 leds ,,,读取设备树配置参数
// 对每个 led , 创建 create_gpio_led
static struct gpio_leds_priv *gpio_leds_create(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct fwnode_handle *child;
	struct gpio_leds_priv *priv;
	int count, ret;

    // 统计设备 dev 子节点的数量
	count = device_get_child_node_count(dev);
	if (!count)
		return ERR_PTR(-ENODEV);

    // 分配设备驱动私有数据
	priv = devm_kzalloc(dev, struct_size(priv, leds, count), GFP_KERNEL);
	if (!priv)
		return ERR_PTR(-ENOMEM);

    // 遍历设备 dev 子节点,,, 由 child 返回
    // dev 的子节点 ???
	device_for_each_child_node(dev, child) {
        // 取出一个 led 数据处理, gpio_led_data 是模块内定义的数据结构
		struct gpio_led_data *led_dat = &priv->leds[priv->num_leds];
		struct gpio_led led = {};
		const char *state = NULL;

		/*
		 * Acquire gpiod from DT with uninitialized label, which
		 * will be updated after LED class device is registered,
		 * Only then the final LED name is known.
		 */
        // 从 child 获取到 gpio_desc 编号
        // 但是这里是直接返回了一个错误
		led.gpiod = devm_fwnode_get_gpiod_from_child(dev, NULL, child,
							     GPIOD_ASIS,
							     NULL);
		if (IS_ERR(led.gpiod)) {
            // 所以会走这里
            // 这个 put 最终调用到 of_fwnode_put,,,释放???
	    fwnode_handle_put(child);
	    return ERR_CAST(led.gpiod);
		}

		led_dat->gpiod = led.gpiod;

        // fwnode 函数族最终是调用 of 函数族
        // 参考 https://blog.csdn.net/qq_23174771/article/details/130166675
        // 这里读了设备树中参数,默认状态 default-state="on"
		if (!fwnode_property_read_string(child, "default-state",
						 &state)) {
			if (!strcmp(state, "keep"))
				led.default_state = LEDS_GPIO_DEFSTATE_KEEP;
			else if (!strcmp(state, "on"))
                // 设置为点亮
				led.default_state = LEDS_GPIO_DEFSTATE_ON;
			else
				led.default_state = LEDS_GPIO_DEFSTATE_OFF;
		}

        // 这些 rv1106-luckfox-pico-pro-max-ipc.dtsi 没有指定
		if (fwnode_property_present(child, "retain-state-suspended"))
			led.retain_state_suspended = 1;
		if (fwnode_property_present(child, "retain-state-shutdown"))
			led.retain_state_shutdown = 1;
		if (fwnode_property_present(child, "panic-indicator"))
			led.panic_indicator = 1;

		ret = create_gpio_led(&led, led_dat, dev, child, NULL);
		if (ret < 0) {
			fwnode_handle_put(child);
			return ERR_PTR(ret);
		}
		/* Set gpiod label to match the corresponding LED name. */
        // 将 gpio 的 label 替换成字符设备的名称
		gpiod_set_consumer_name(led_dat->gpiod,
					led_dat->cdev.dev->kobj.name);
        // 序号自增
		priv->num_leds++;
	}

    // 返回设备驱动私有数据
	return priv;
}

//  定义了平台驱动匹配设备树 compatible
static const struct of_device_id of_gpio_leds_match[] = {
	{ .compatible = "gpio-leds", },
	{},
};

MODULE_DEVICE_TABLE(of, of_gpio_leds_match);

static struct gpio_desc *gpio_led_get_gpiod(struct device *dev, int idx,
					    const struct gpio_led *template)
{
	struct gpio_desc *gpiod;
	unsigned long flags = GPIOF_OUT_INIT_LOW;
	int ret;

	/*
	 * This means the LED does not come from the device tree
	 * or ACPI, so let's try just getting it by index from the
	 * device, this will hit the board file, if any and get
	 * the GPIO from there.
	 */
    // 再次获取 gpio 描述,,,如果成功了 直接返回
	gpiod = devm_gpiod_get_index(dev, NULL, idx, GPIOD_OUT_LOW);
	if (!IS_ERR(gpiod)) {
		gpiod_set_consumer_name(gpiod, template->name);
		return gpiod;
	}
	if (PTR_ERR(gpiod) != -ENOENT)
		return gpiod;

	/*
	 * This is the legacy code path for platform code that
	 * still uses GPIO numbers. Ultimately we would like to get
	 * rid of this block completely.
	 */

    // 如果还是没有获取到 gpio 描述,,,,那么根据 gpio 编号获取
	/* skip leds that aren't available */
	if (!gpio_is_valid(template->gpio))
		return ERR_PTR(-ENOENT);

	if (template->active_low)
		flags |= GPIOF_ACTIVE_LOW;

    // 申请一个 gpio 资源
	ret = devm_gpio_request_one(dev, template->gpio, flags,
				    template->name);
	if (ret < 0)
		return ERR_PTR(ret);

    // gpio 编号 转 描述
	gpiod = gpio_to_desc(template->gpio);
	if (!gpiod)
		return ERR_PTR(-EINVAL);

	return gpiod;
}

static int gpio_led_probe(struct platform_device *pdev)
{
    // struct platform_device 是 struct device	dev 的子类
    // 这里有一组有一组获取 struct device 的数据的函数组
    /**
     * static inline void *dev_get_platdata(const struct device *dev)
     * int dev_set_drvdata(struct device *dev, void *data)
     * void *dev_get_drvdata(const struct device *dev)
     * static inline void *platform_get_drvdata(const struct platform_device *pdev)
     * static inline void platform_set_drvdata(struct platform_device *pdev, void *data)
     * 说明:只能给 driver_data 赋值,,, platform_data 可能是设备树模块给赋值的???
     * platform_data 姑且理解和设备数配置关联
     */
    // 获取平台设备私有数据
	struct gpio_led_platform_data *pdata = dev_get_platdata(&pdev->dev);
    // 这个数据i结构将会作为设备o 驱动私有数据
	struct gpio_leds_priv *priv;
	int i, ret = 0;

    // 判断是否有平台数据,或者平台数据是否配置了 led
    // 这里是设备树是配置了
	if (pdata && pdata->num_leds) {
        // 处理单个led,设备树可能会 配置多个
        // 分配私有数据,根据led数量
        // gpio_leds_priv 是模块定义数据结构,参数包括,led个数,和一个数组描述每个led
		priv = devm_kzalloc(&pdev->dev, struct_size(priv, leds, pdata->num_leds),
				    GFP_KERNEL);
		if (!priv)
			return -ENOMEM;

        // led 灯的个数
		priv->num_leds = pdata->num_leds;
		for (i = 0; i < priv->num_leds; i++) {
            // 对每个 led 初始化私有数据,,, driver_data
            // 获取平台设备一个 led 参数
			const struct gpio_led *template = &pdata->leds[i];
            // 获取设备驱动数据的 led 表示
			struct gpio_led_data *led_dat = &priv->leds[i];

            // 如果平台设备数据 gpio 描述不为空,,,把这个描述赋值到 驱动设备 私有数据
            // 如果为空,,,,使用 gpio 的编号,来获取 描述
			if (template->gpiod)
				led_dat->gpiod = template->gpiod;
			else
				led_dat->gpiod =
					gpio_led_get_gpiod(&pdev->dev,
							   i, template);
            // 如果 描述 错误,,,跳过 这条 数据
            // 否则,创建 led 的 设备
			if (IS_ERR(led_dat->gpiod)) {
				dev_info(&pdev->dev, "Skipping unavailable LED gpio %d (%s)\n",
					 template->gpio, template->name);
				continue;
			}

            // 创建 led 设备  device_create
			ret = create_gpio_led(template, led_dat,
					      &pdev->dev, NULL,
					      pdata->gpio_blink_set);
			if (ret < 0)
				return ret;
		}
	} else {
        // 没有 led 信息
		priv = gpio_leds_create(pdev);
		if (IS_ERR(priv))
			return PTR_ERR(priv);
	}

    // 私有数据设置到 driver_data
	platform_set_drvdata(pdev, priv);

	return 0;
}

static void gpio_led_shutdown(struct platform_device *pdev)
{
	struct gpio_leds_priv *priv = platform_get_drvdata(pdev);
	int i;

	for (i = 0; i < priv->num_leds; i++) {
		struct gpio_led_data *led = &priv->leds[i];

		if (!(led->cdev.flags & LED_RETAIN_AT_SHUTDOWN))
			gpio_led_set(&led->cdev, LED_OFF);
	}
}

// 定义了一个平台驱动和设备数匹配,匹配后执行 probe
static struct platform_driver gpio_led_driver = {
	.probe		= gpio_led_probe,
	.shutdown	= gpio_led_shutdown,
	.driver		= {
		.name	= "leds-gpio",
		.of_match_table = of_gpio_leds_match,
	},
};

// 典型的平台驱动模块
module_platform_driver(gpio_led_driver);

MODULE_AUTHOR("Raphael Assenat <raph@8d.com>, Trent Piepho <tpiepho@freescale.com>");
MODULE_DESCRIPTION("GPIO LED driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:leds-gpio");

// linux驱动leds子系统梳理
// https://www.jianshu.com/p/22f86df17c90
// 主要文件
// /driver/leds/led-class.c
// /driver/leds/led-core.c
// /driver/leds/led-triggers.c
// /include/linux/leds.h
// /driver/leds/leds-gpio.c （驱动）
/**
 * 这个文件是 leds 的驱动文件,,,
 * 其他 触发器 调用 led-triggers.c 的接口注册了触发器,,,在 led-triggers.c 模块中维护
 * 这个驱动文件调用 led-triggers.c 设置触发器
 * led-class.c 有 init 段,,,会创建一个类 leds,,,,
 * 这个驱动文件调用 led-class.c 的接口在 类 leds 中创建设备
 * 
 * leds 模块没有创建字符设备???
 * sysfs 和字符设备是分开的概念???
 */


