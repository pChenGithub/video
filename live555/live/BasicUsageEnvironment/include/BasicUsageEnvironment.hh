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

#ifndef _BASIC_USAGE_ENVIRONMENT_HH
#define _BASIC_USAGE_ENVIRONMENT_HH

#ifndef _BASIC_USAGE_ENVIRONMENT0_HH
#include "BasicUsageEnvironment0.hh"
#endif

// 这个类里面的内容比较简单,就一个构造方法,和静态构造方法,
// 获取错误码接口,,,<< 操作符重写,,,
class BasicUsageEnvironment: public BasicUsageEnvironment0 {
public:
	// 静态方法,创建 BasicUsageEnvironment 实例
  static BasicUsageEnvironment* createNew(TaskScheduler& taskScheduler);

  // redefined virtual functions:
	// 返回错误码 errno
  virtual int getErrno() const;

  virtual UsageEnvironment& operator<<(char const* str);
  virtual UsageEnvironment& operator<<(int i);
  virtual UsageEnvironment& operator<<(unsigned u);
  virtual UsageEnvironment& operator<<(double d);
  virtual UsageEnvironment& operator<<(void* p);

protected:
	// 构造函数没有公开,不能直接new这个对象
  BasicUsageEnvironment(TaskScheduler& taskScheduler);
      // called only by "createNew()" (or subclass constructors)
  virtual ~BasicUsageEnvironment();
};


class BasicTaskScheduler: public BasicTaskScheduler0 {
public:
	// 定义了一个静态方法实例化对象
  static BasicTaskScheduler* createNew(unsigned maxSchedulerGranularity = 10000/*microseconds*/);
    // "maxSchedulerGranularity" (default value: 10 ms) specifies the maximum time that we wait (in "select()") before
    // returning to the event loop to handle non-socket or non-timer-based events, such as 'triggered events'.
    // You can change this is you wish (but only if you know what you're doing!), or set it to 0, to specify no such maximum time.
    // (You should set it to 0 only if you know that you will not be using 'event triggers'.)
  virtual ~BasicTaskScheduler();

protected:
	// 构造方法,没有公开,不能直接用new创建对象
  BasicTaskScheduler(unsigned maxSchedulerGranularity);
      // called only by "createNew()"

	// 这2个函数配合,结果是 schedulerTickTask 会定时执行
	// 静态方法,传入参数是 BasicTaskScheduler 实例,,,最终调用 schedulerTickTask()方法
  static void schedulerTickTask(void* clientData);
	// 
  void schedulerTickTask();

protected:
  // Redefined virtual functions:
	// 来自父类的虚函数,,,这个函数在事件循环中被调用
	// 在最终子类 BasicTaskScheduler 实现
	// 这个函数主要,处理
	// 1 监听 socket
	// 2 监听触发器
	// 3 轮询定时任务
  virtual void SingleStep(unsigned maxDelayTime);

  virtual void setBackgroundHandling(int socketNum, int conditionSet, BackgroundHandlerProc* handlerProc, void* clientData);
  virtual void moveSocketHandling(int oldSocketNum, int newSocketNum);

protected:
	// 定时任务延时时间
  unsigned fMaxSchedulerGranularity;

  // To implement background operations:
	// 最大socket数量
  int fMaxNumSockets;
	// select 使用的读,写,错误监听
  fd_set fReadSet;
  fd_set fWriteSet;
  fd_set fExceptionSet;

private:
#if defined(__WIN32__) || defined(_WIN32)
  // Hack to work around a bug in Windows' "select()" implementation:
  int fDummySocketNum;
#endif
};

#endif
