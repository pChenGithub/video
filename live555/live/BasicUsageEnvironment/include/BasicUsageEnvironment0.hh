/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// Copyright (c) 1996-2024 Live Networks, Inc.  All rights reserved.
// Basic Usage Environment: for a simple, non-scripted, console application
// C++ header

#ifndef _BASIC_USAGE_ENVIRONMENT0_HH
#define _BASIC_USAGE_ENVIRONMENT0_HH

#ifndef _BASICUSAGEENVIRONMENT_VERSION_HH
#include "BasicUsageEnvironment_version.hh"
#endif

#ifndef _USAGE_ENVIRONMENT_HH
#include "UsageEnvironment.hh"
#endif

#ifndef _DELAY_QUEUE_HH
#include "DelayQueue.hh"
#endif

#ifndef NO_STD_LIB
#ifndef _LIBCPP_ATOMIC
#include <atomic>
#endif
#endif

#define RESULT_MSG_BUFFER_MAX 1000

// An abstract base class, useful for subclassing
// (e.g., to redefine the implementation of "operator<<")
// BasicUsageEnvironment0 定义了一个缓存,和一些操作缓存的方法,
// 写缓存,返回缓存地址,输出缓存内容到标准错误
class BasicUsageEnvironment0: public UsageEnvironment {
public:
  // redefined virtual functions:
	// 获取消息,实际是返回缓存首地址
  virtual MsgString getResultMsg() const;

	// 设置消息的一组函数,作用是向缓存内添加内容
  virtual void setResultMsg(MsgString msg);
  virtual void setResultMsg(MsgString msg1,
		    MsgString msg2);
  virtual void setResultMsg(MsgString msg1,
		    MsgString msg2,
		    MsgString msg3);
  virtual void setResultErrMsg(MsgString msg, int err = 0);
  virtual void appendToResultMsg(MsgString msg);

	// 向标准错误输出缓存内容
  virtual void reportBackgroundError();

protected:
	// 构造函数
  BasicUsageEnvironment0(TaskScheduler& taskScheduler);
  virtual ~BasicUsageEnvironment0();

private:
	// 清空缓存
  void reset();

	// 缓存
  char fResultMsgBuffer[RESULT_MSG_BUFFER_MAX];
	// 当前缓存大小,缓存内存在数据大小
  unsigned fCurBufferSize;
	// 最大缓存大小
  unsigned fBufferMaxSize;
};

class HandlerSet; // forward

// Note: You may redefine MAX_NUM_EVENT_TRIGGERS,
// but it must be <= the number of bits in an "EventTriggerId"
#ifndef MAX_NUM_EVENT_TRIGGERS
#define MAX_NUM_EVENT_TRIGGERS 32
#endif
#define EVENT_TRIGGER_ID_HIGH_BIT (1 << (MAX_NUM_EVENT_TRIGGERS-1))

// An abstract base class, useful for subclassing
// (e.g., to redefine the implementation of socket event handling)
// TaskScheduler 父类的构造函数没有做任何事情
class BasicTaskScheduler0: public TaskScheduler {
public:
  virtual ~BasicTaskScheduler0();

	// 全虚函数
  virtual void SingleStep(unsigned maxDelayTime = 0) = 0;
      // "maxDelayTime" is in microseconds.  It allows a subclass to impose a limit
      // on how long "select()" can delay, in case it wants to also do polling.
      // 0 (the default value) means: There's no maximum; just look at the delay queue

public:
  // Redefined virtual functions:
	// 提交一个延时任务接口
  virtual TaskToken scheduleDelayedTask(int64_t microseconds, TaskFunc* proc,
				void* clientData);
	// 取消一个延时任务接口
  virtual void unscheduleDelayedTask(TaskToken& prevTask);

	// 实现了 TaskScheduler 中定义的全虚函数,,,这个函数在 main中被调用,,来处理事件循环
	// 在 BasicTaskScheduler0 中实现,,,调用了 SingleStep
  virtual void doEventLoop(char volatile* watchVariable);

  virtual EventTriggerId createEventTrigger(TaskFunc* eventHandlerProc);
  virtual void deleteEventTrigger(EventTriggerId eventTriggerId);
  virtual void triggerEvent(EventTriggerId eventTriggerId, void* clientData = NULL);

protected:
	// 构造函数会被子类继承,子类能访问到
  BasicTaskScheduler0();

protected:
  // To implement delayed operations:
  intptr_t fTokenCounter;
	// 任务队列,任务队列的实例化是,在 BasicTaskScheduler0 类中完成的
	// 这里维护了一些延时任务
	// 队列头实例化,只更新了以下基准时间
  DelayQueue fDelayQueue;

  // To implement background reads:
	// 一个集合对象指针,,,这额集合里面方的是 socket描述符,以及回调函数
  HandlerSet* fHandlers;
	// 最后一个socketNum,,,最大描述符???
	// 初始化为 -1
  int fLastHandledSocketNum;

  // To implement event triggers:
#ifndef NO_STD_LIB
  std::atomic_flag fTriggersAwaitingHandling[MAX_NUM_EVENT_TRIGGERS];
#else
  Boolean volatile fTriggersAwaitingHandling[MAX_NUM_EVENT_TRIGGERS];
#endif
	// 标记哪个触发器在使用???,最多32个
  u_int32_t fLastUsedTriggerMask; // implemented as a 32-bit bitmap
	// 触发器的回调函数
  TaskFunc* fTriggeredEventHandlers[MAX_NUM_EVENT_TRIGGERS];
	// 触发器的回调函数参数
  void* fTriggeredEventClientDatas[MAX_NUM_EVENT_TRIGGERS];
	// 最后一个触发器下标
  unsigned fLastUsedTriggerNum; // in the range [0,MAX_NUM_EVENT_TRIGGERS)
  Boolean fEventTriggersAreBeingUsed;
};

#endif
