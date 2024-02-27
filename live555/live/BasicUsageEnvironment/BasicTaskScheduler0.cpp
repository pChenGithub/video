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
// Implementation

#include "BasicUsageEnvironment0.hh"
#include "HandlerSet.hh"

////////// A subclass of DelayQueueEntry,
//////////     used to implement BasicTaskScheduler0::scheduleDelayedTask()

// 一个定时处理任务的类
class AlarmHandler: public DelayQueueEntry {
public:
	// proc, clientData, 回调函数和回调函数参数
	// DelayInterval 定时时间
	// token
  AlarmHandler(TaskFunc* proc, void* clientData, DelayInterval timeToDelay, intptr_t token)
	// 延时时间和token处理延时队列节点,,,,,回调函数和参数是 定时任务的扩展
    : DelayQueueEntry(timeToDelay, token), fProc(proc), fClientData(clientData) {
  }

private: // redefined virtual functions
	// 定时到达,会执行这个重载方法
  virtual void handleTimeout() {
	// 调用回调函数
    (*fProc)(fClientData);
	// 调用父类的 handleTimeout 会销毁自己
    DelayQueueEntry::handleTimeout();
  }

private:
	// 定时到达,回调函数
  TaskFunc* fProc;
	// 回调函数参数
  void* fClientData;
};


////////// BasicTaskScheduler0 //////////

BasicTaskScheduler0::BasicTaskScheduler0()
  : fTokenCounter(0), fLastHandledSocketNum(-1),
    fLastUsedTriggerMask(1), fLastUsedTriggerNum(MAX_NUM_EVENT_TRIGGERS-1),
    fEventTriggersAreBeingUsed(False) {
	// 
  fHandlers = new HandlerSet;
	// 对 MAX_NUM_EVENT_TRIGGERS 个触发器进行初始化
	// 都设置为空
  for (unsigned i = 0; i < MAX_NUM_EVENT_TRIGGERS; ++i) {
#ifndef NO_STD_LIB
    fTriggersAwaitingHandling[i].clear();
#else
    fTriggersAwaitingHandling[i] = False;
#endif
    fTriggeredEventHandlers[i] = NULL;
    fTriggeredEventClientDatas[i] = NULL;
  }
}

BasicTaskScheduler0::~BasicTaskScheduler0() {
  delete fHandlers;
}

// BasicTaskScheduler0 是 BasicTaskScheduler 的父类
// 这个接口会提交一个microseconds秒后执行的任务到 队列中
TaskToken BasicTaskScheduler0::scheduleDelayedTask(int64_t microseconds,
						   TaskFunc* proc,
						   void* clientData) {
	// 保证microseconds 为大于0
  if (microseconds < 0) microseconds = 0;
	// 实例化给的参数好像没有用到???
	// microseconds 微秒,, 转成秒 和 小数
  DelayInterval timeToDelay((long)(microseconds/1000000), (long)(microseconds%1000000));
  AlarmHandler* alarmHandler = new AlarmHandler(proc, clientData, timeToDelay, ++fTokenCounter);
	// fDelayQueue 是 BasicTaskScheduler0的属性,用来保存定时任务的队列
  fDelayQueue.addEntry(alarmHandler);

  return (void*)(alarmHandler->token());
}

void BasicTaskScheduler0::unscheduleDelayedTask(TaskToken& prevTask) {
  DelayQueueEntry* alarmHandler = fDelayQueue.removeEntry((intptr_t)prevTask);
  prevTask = NULL;
  delete alarmHandler;
}

// 事件循环处理
// 这是一个死循环
// 这个函数在 main 中被调用
void BasicTaskScheduler0::doEventLoop(char volatile* watchVariable) {
  // Repeatedly loop, handling readble sockets and timed events:
  while (1) {
	// 退出条件,,,满足条件退出
    if (watchVariable != NULL && *watchVariable != 0) break;
    SingleStep();
  }
}

// 直译:创建一个事件触发器
EventTriggerId BasicTaskScheduler0::createEventTrigger(TaskFunc* eventHandlerProc) {
  unsigned i = fLastUsedTriggerNum;
  u_int32_t mask = fLastUsedTriggerMask;

  do {
    i = (i+1)%MAX_NUM_EVENT_TRIGGERS;
    mask >>= 1;
    if (mask == 0) mask = EVENT_TRIGGER_ID_HIGH_BIT;

    if (fTriggeredEventHandlers[i] == NULL) {
      // This trigger number is free; use it:
      fTriggeredEventHandlers[i] = eventHandlerProc;
      fTriggeredEventClientDatas[i] = NULL; // sanity

      fLastUsedTriggerMask = mask;
      fLastUsedTriggerNum = i;
      fEventTriggersAreBeingUsed = True;

      return mask;
    }
  } while (i != fLastUsedTriggerNum);

  // All available event triggers are allocated; return 0 instead:
  return 0;
}

void BasicTaskScheduler0::deleteEventTrigger(EventTriggerId eventTriggerId) {
  // "eventTriggerId" should have just one bit set.
  // However, we do the reasonable thing if the user happened to 'or' together two or more "EventTriggerId"s:
  EventTriggerId mask = EVENT_TRIGGER_ID_HIGH_BIT;
  Boolean eventTriggersAreBeingUsed = False;

  for (unsigned i = 0; i < MAX_NUM_EVENT_TRIGGERS; ++i) {
    if ((eventTriggerId&mask) != 0) {
#ifndef NO_STD_LIB
      fTriggersAwaitingHandling[i].clear();
#else
      fTriggersAwaitingHandling[i] = False;
#endif
      fTriggeredEventHandlers[i] = NULL;
      fTriggeredEventClientDatas[i] = NULL;
    } else if (fTriggeredEventHandlers[i] != NULL) {
      eventTriggersAreBeingUsed = True;
    }
    mask >>= 1;
  }

  fEventTriggersAreBeingUsed = eventTriggersAreBeingUsed;
}

void BasicTaskScheduler0::triggerEvent(EventTriggerId eventTriggerId, void* clientData) {
  // First, record the "clientData".  (Note that we allow "eventTriggerId" to be a combination of bits for multiple events.)
  EventTriggerId mask = EVENT_TRIGGER_ID_HIGH_BIT;
  for (unsigned i = 0; i < MAX_NUM_EVENT_TRIGGERS; ++i) {
    if ((eventTriggerId&mask) != 0) {
      fTriggeredEventClientDatas[i] = clientData;
#ifndef NO_STD_LIB
      (void)fTriggersAwaitingHandling[i].test_and_set();
#else
      fTriggersAwaitingHandling[i] = True;
#endif
    }
    mask >>= 1;
  }
}


////////// HandlerSet (etc.) implementation //////////

// 这个元素自己就是链表节点
// 新建元素和销毁元素,自己会插入或移除链表
HandlerDescriptor::HandlerDescriptor(HandlerDescriptor* nextHandler)
  : conditionSet(0), handlerProc(NULL) {
  // Link this descriptor into a doubly-linked list:
  if (nextHandler == this) { // initialization
    fNextHandler = fPrevHandler = this;
  } else {
    fNextHandler = nextHandler;
    fPrevHandler = nextHandler->fPrevHandler;
    nextHandler->fPrevHandler = this;
    fPrevHandler->fNextHandler = this;
  }
}

HandlerDescriptor::~HandlerDescriptor() {
  // Unlink this descriptor from a doubly-linked list:
  fNextHandler->fPrevHandler = fPrevHandler;
  fPrevHandler->fNextHandler = fNextHandler;
}

HandlerSet::HandlerSet()
	// 双向循环链表,,,为空时自己指向自己
  : fHandlers(&fHandlers) {
  fHandlers.socketNum = -1; // shouldn't ever get looked at, but in case...
}

HandlerSet::~HandlerSet() {
  // Delete each handler descriptor:
  while (fHandlers.fNextHandler != &fHandlers) {
    delete fHandlers.fNextHandler; // changes fHandlers->fNextHandler
  }
}

// 插入一个元素,如果存在,修改元素属性,,,如果不存在,,,新建元素插入
void HandlerSet
::assignHandler(int socketNum, int conditionSet, TaskScheduler::BackgroundHandlerProc* handlerProc, void* clientData) {
  // First, see if there's already a handler for this socket:
  HandlerDescriptor* handler = lookupHandler(socketNum);
  if (handler == NULL) { // No existing handler, so create a new descr:
    handler = new HandlerDescriptor(fHandlers.fNextHandler);
    handler->socketNum = socketNum;
  }

  handler->conditionSet = conditionSet;
  handler->handlerProc = handlerProc;
  handler->clientData = clientData;
}

// 删除集合内的一个元素
void HandlerSet::clearHandler(int socketNum) {
  HandlerDescriptor* handler = lookupHandler(socketNum);
  delete handler;
}

// 修改一个元素的 oldSocketNum, 为 newSocketNum,,,如果有这个元素存在的话
void HandlerSet::moveHandler(int oldSocketNum, int newSocketNum) {
  HandlerDescriptor* handler = lookupHandler(oldSocketNum);
  if (handler != NULL) {
    handler->socketNum = newSocketNum;
  }
}

// 
HandlerDescriptor* HandlerSet::lookupHandler(int socketNum) {
  HandlerDescriptor* handler;
	// 创建 集合 HandlerSet 的迭代器
	// 这个集合内部的元素是 HandlerDescriptor
  HandlerIterator iter(*this);
	// 遍历集合内不元素,,,找到 socketNun 匹配的元素,跳出
  while ((handler = iter.next()) != NULL) {
    if (handler->socketNum == socketNum) break;
  }
	// 返回找到元素,或者为NULL
  return handler;
}

HandlerIterator::HandlerIterator(HandlerSet& handlerSet)
	// 指定迭代器的集合对象
  : fOurSet(handlerSet) {
	// 复位迭代器指针
  reset();
}

HandlerIterator::~HandlerIterator() {
}

// 迭代器指针复位,,,即指针指到集合内的第一个元素
void HandlerIterator::reset() {
  fNextPtr = fOurSet.fHandlers.fNextHandler;
}

// 迭代器获取下一个元素
HandlerDescriptor* HandlerIterator::next() {
  HandlerDescriptor* result = fNextPtr;
	// 如果下一个元素已经是链表头了,,,说明已经是最后一个,没有最后一个了
	// 否则返回迭代器指针后移
  if (result == &fOurSet.fHandlers) { // no more
    result = NULL;
  } else {
    fNextPtr = fNextPtr->fNextHandler;
  }

  return result;
}
