#!/bin/bash

#################################################
# 	Board Config
#################################################

# Target CHIP
export RK_CHIP=rv1106

# app config
export RK_APP_TYPE=RKIPC_RV1103

# Config CMA size in environment
export RK_BOOTARGS_CMA_SIZE="24M"

# Kernel dts
export RK_KERNEL_DTS=rv1103g-luckfox-pico-mini-b.dts

#################################################
#	BOOT_MEDIUM
#################################################

# Target boot medium: emmc/spi_nor/spi_nand
export RK_BOOT_MEDIUM=spi_nand

# Uboot defconfig fragment
export RK_UBOOT_DEFCONFIG_FRAGMENT=rk-sfc.config

# specify post.sh for delete/overlay files
# export RK_PRE_BUILD_OEM_SCRIPT=rv1103-spi_nor-post.sh

# config partition in environment
# RK_PARTITION_CMD_IN_ENV format:
#     <partdef>[,<partdef>]
#       <partdef> := <size>[@<offset>](part-name)
# Note:
#   If the first partition offset is not 0x0, it must be added. Otherwise, it needn't adding.
export RK_PARTITION_CMD_IN_ENV="256K(env),256K@256K(idblock),512K(uboot),4M(boot),30M(oem),10M(userdata),80M(rootfs)"

# config partition's filesystem type (squashfs is readonly)
# emmc:    squashfs/ext4
# nand:    squashfs/ubifs
# spi nor: squashfs/jffs2
# RK_PARTITION_FS_TYPE_CFG format:
#     AAAA:/BBBB/CCCC@ext4
#         AAAA ----------> partition name
#         /BBBB/CCCC ----> partition mount point
#         ext4 ----------> partition filesystem type
export RK_PARTITION_FS_TYPE_CFG=rootfs@IGNORE@ubifs,oem@/oem@ubifs,userdata@/userdata@ubifs

# config filesystem compress (Just for squashfs or ubifs)
# squashfs: lz4/lzo/lzma/xz/gzip, default xz
# ubifs:    lzo/zlib, default lzo
# export RK_SQUASHFS_COMP=xz
# export RK_UBIFS_COMP=lzo

#################################################
#	TARGET_ROOTFS
#################################################

# Target rootfs : ubuntu(only emmc)/buildroot/busybox
export LF_TARGET_ROOTFS=buildroot

# Buildroot defconfig
export RK_BUILDROOT_DEFCONFIG=luckfox_pico_defconfig

#################################################
# 	Defconfig
#################################################

# Target arch
export RK_ARCH=arm

# Target Toolchain Cross Compile
export RK_TOOLCHAIN_CROSS=arm-rockchip830-linux-uclibcgnueabihf

#misc image
export RK_MISC=wipe_all-misc.img

# Uboot defconfig
export RK_UBOOT_DEFCONFIG=rv1106_defconfig

# Kernel defconfig
export RK_KERNEL_DEFCONFIG=luckfox_rv1106_linux_defconfig

# Config sensor IQ files
# RK_CAMERA_SENSOR_IQFILES format:
#     "iqfile1 iqfile2 iqfile3 ..."
# ./build.sh media and copy <SDK root dir>/output/out/media_out/isp_iqfiles/$RK_CAMERA_SENSOR_IQFILES
export RK_CAMERA_SENSOR_IQFILES="sc4336_OT01_40IRC_F16.json sc3336_CMK-OT2119-PC1_30IRC-F16.json"
#export RK_CAMERA_SENSOR_IQFILES="sc4336_OT01_40IRC_F16.json sc3336_CMK-OT2119-PC1_30IRC-F16.json sc530ai_CMK-OT2115-PC1_30IRC-F16.json"

# Config sensor lens CAC calibrattion bin files
export RK_CAMERA_SENSOR_CAC_BIN="CAC_sc4336_OT01_40IRC_F16"
#export RK_CAMERA_SENSOR_CAC_BIN="CAC_sc4336_OT01_40IRC_F16 CAC_sc530ai_CMK-OT2115-PC1_30IRC-F16"

# build ipc web backend
# export RK_APP_IPCWEB_BACKEND=y

# enable install app to oem partition
export RK_BUILD_APP_TO_OEM_PARTITION=y

# enable rockchip test
export RK_ENABLE_ROCKCHIP_TEST=y
