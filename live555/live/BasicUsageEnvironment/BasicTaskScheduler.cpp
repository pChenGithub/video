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


#include "BasicUsageEnvironment.hh"
#include "HandlerSet.hh"
#include <stdio.h>
#if defined(_QNX4)
#include <sys/select.h>
#include <unix.h>
#endif

////////// BasicTaskScheduler //////////

// maxSchedulerGranularity 单位 微秒,,,提交定时任务的参数
BasicTaskScheduler* BasicTaskScheduler::createNew(unsigned maxSchedulerGranularity) {
	// 创建新的 BasicTaskScheduler 对象
	return new BasicTaskScheduler(maxSchedulerGranularity);
}

BasicTaskScheduler::BasicTaskScheduler(unsigned maxSchedulerGranularity)
  : fMaxSchedulerGranularity(maxSchedulerGranularity), fMaxNumSockets(0)
#if defined(__WIN32__) || defined(_WIN32)
  , fDummySocketNum(-1)
#endif
{
	// 初始化 读,写,错误 多路复用监听
  FD_ZERO(&fReadSet);
  FD_ZERO(&fWriteSet);
  FD_ZERO(&fExceptionSet);

	// 时间大于 0 创建 调度任务
  if (maxSchedulerGranularity > 0) schedulerTickTask(); // ensures that we handle events frequently
}

BasicTaskScheduler::~BasicTaskScheduler() {
#if defined(__WIN32__) || defined(_WIN32)
  if (fDummySocketNum >= 0) closeSocket(fDummySocketNum);
#endif
}

void BasicTaskScheduler::schedulerTickTask(void* clientData) {
  ((BasicTaskScheduler*)clientData)->schedulerTickTask();
}

// 这个方法,每隔 fMaxSchedulerGranularity 会把自己放入 延时执行队列
void BasicTaskScheduler::schedulerTickTask() {
	// 父类继承的方法,会创建一个时间对象(fMaxSchedulerGranularity转化出来)
	// 和定时任务对象,然后将这个任务加入队列
	// 总结:提交一个fMaxSchedulerGranularity 后执行的回调函数 schedulerTickTask,

	// 返回定时任务的token
	// fMaxSchedulerGranularity 单位 微秒
	// schedulerTickTask, 回调函数
	// this 回调函数参数
  scheduleDelayedTask(fMaxSchedulerGranularity, schedulerTickTask, this);
}

#ifndef MILLION
#define MILLION 1000000
#endif

// 时间循环调用这个函数,没有给参数,,,默认参数 maxDelayTime=0
void BasicTaskScheduler::SingleStep(unsigned maxDelayTime) {
  fd_set readSet = fReadSet; // make a copy for this select() call
  fd_set writeSet = fWriteSet; // ditto
  fd_set exceptionSet = fExceptionSet; // ditto

	// 获取还有多久有事件会被触发
	// 返回已经被触发了(DELAY_ZERO),或者第一个事件将要被触发的时间
  DelayInterval const& timeToDelay = fDelayQueue.timeToNextAlarm();
  struct timeval tv_timeToDelay;
  tv_timeToDelay.tv_sec = timeToDelay.seconds();
  tv_timeToDelay.tv_usec = timeToDelay.useconds();
	// 校验时间,避免 select 错误返回
	// 时间最大不超过 1000000 秒
  // Very large "tv_sec" values cause select() to fail.
  // Don't make it any larger than 1 million seconds (11.5 days)
// static const int MILLION = 1000000;
  const long MAX_TV_SEC = MILLION;
  if (tv_timeToDelay.tv_sec > MAX_TV_SEC) {
    tv_timeToDelay.tv_sec = MAX_TV_SEC;
  }
 // maxDelayTime=0 这里不执行
  // Also check our "maxDelayTime" parameter (if it's > 0):
  if (maxDelayTime > 0 &&
      (tv_timeToDelay.tv_sec > (long)maxDelayTime/MILLION ||
       (tv_timeToDelay.tv_sec == (long)maxDelayTime/MILLION &&
	tv_timeToDelay.tv_usec > (long)maxDelayTime%MILLION))) {
    tv_timeToDelay.tv_sec = maxDelayTime/MILLION;
    tv_timeToDelay.tv_usec = maxDelayTime%MILLION;
  }

// 这里会等待直到第一个事件时间到了,,,否则超时返回
  int selectResult = select(fMaxNumSockets, &readSet, &writeSet, &exceptionSet, &tv_timeToDelay);
  if (selectResult < 0) {
#if defined(__WIN32__) || defined(_WIN32)
    int err = WSAGetLastError();
    // For some unknown reason, select() in Windoze sometimes fails with WSAEINVAL if
    // it was called with no entries set in "readSet".  If this happens, ignore it:
    if (err == WSAEINVAL && readSet.fd_count == 0) {
      err = EINTR;
      // To stop this from happening again, create a dummy socket:
      if (fDummySocketNum >= 0) closeSocket(fDummySocketNum);
      fDummySocketNum = socket(AF_INET, SOCK_DGRAM, 0);
      FD_SET((unsigned)fDummySocketNum, &fReadSet);
    }
    if (err != EINTR) {
#else
    if (errno != EINTR && errno != EAGAIN) {
#endif
	// Unexpected error - treat this as fatal:
#if !defined(_WIN32_WCE)
	perror("BasicTaskScheduler::SingleStep(): select() fails");
	// Because this failure is often "Bad file descriptor" - which is caused by an invalid socket number (i.e., a socket number
	// that had already been closed) being used in "select()" - we print out the sockets that were being used in "select()",
	// to assist in debugging:
	fprintf(stderr, "socket numbers used in the select() call:");
// select 出错处理,,,检查文件描述符 0-10000,,,打印错误的文件描述符
	for (int i = 0; i < 10000; ++i) {
	  if (FD_ISSET(i, &fReadSet) || FD_ISSET(i, &fWriteSet) || FD_ISSET(i, &fExceptionSet)) {
	    fprintf(stderr, " %d(", i);
	    if (FD_ISSET(i, &fReadSet)) fprintf(stderr, "r");
	    if (FD_ISSET(i, &fWriteSet)) fprintf(stderr, "w");
	    if (FD_ISSET(i, &fExceptionSet)) fprintf(stderr, "e");
	    fprintf(stderr, ")");
	  }
	}
	fprintf(stderr, "\n");
#endif
	// 错误退出程序,,,abord
	internalError();
      }
  }

// 下面是select正常返回处理
  // Call the handler function for one readable socket:
	// 创建迭代器,,,集合是放了一堆的socket描述符
  HandlerIterator iter(*fHandlers);
	// 定义元素指针
  HandlerDescriptor* handler;
  // To ensure forward progress through the handlers, begin past the last
  // socket number that we handled:
	// 有元素,有socket
	// 找socket描述符最大的元素
  if (fLastHandledSocketNum >= 0) {
    while ((handler = iter.next()) != NULL) {
      if (handler->socketNum == fLastHandledSocketNum) break;
    }
	// 如果没找到,,,fLastHandledSocketNum赋值为 -1
    if (handler == NULL) {
      fLastHandledSocketNum = -1;
      iter.reset(); // start from the beginning instead
    }
  }
	// 遍历集合
  while ((handler = iter.next()) != NULL) {
    int sock = handler->socketNum; // alias
    int resultConditionSet = 0;
	// 如果select监听到 可读,可写,错误,,,分别标记起来
    if (FD_ISSET(sock, &readSet) && FD_ISSET(sock, &fReadSet)/*sanity check*/) resultConditionSet |= SOCKET_READABLE;
    if (FD_ISSET(sock, &writeSet) && FD_ISSET(sock, &fWriteSet)/*sanity check*/) resultConditionSet |= SOCKET_WRITABLE;
    if (FD_ISSET(sock, &exceptionSet) && FD_ISSET(sock, &fExceptionSet)/*sanity check*/) resultConditionSet |= SOCKET_EXCEPTION;
	// 如果socket可操作,且允许操作,,,调用回调函数处理
    if ((resultConditionSet&handler->conditionSet) != 0 && handler->handlerProc != NULL) {
	// 集合内的socket有排序???
      fLastHandledSocketNum = sock;
          // Note: we set "fLastHandledSocketNum" before calling the handler,
          // in case the handler calls "doEventLoop()" reentrantly.
	// 调用回调函数处理,可读,可写或错误数据
      (*handler->handlerProc)(handler->clientData, resultConditionSet);
	// 然后跳出循环
      break;
    }
  }
// 如果上面每有找到可操作的元素,,,,这里再找一遍
  if (handler == NULL && fLastHandledSocketNum >= 0) {
    // We didn't call a handler, but we didn't get to check all of them,
    // so try again from the beginning:
    iter.reset();
    while ((handler = iter.next()) != NULL) {
      int sock = handler->socketNum; // alias
      int resultConditionSet = 0;
      if (FD_ISSET(sock, &readSet) && FD_ISSET(sock, &fReadSet)/*sanity check*/) resultConditionSet |= SOCKET_READABLE;
      if (FD_ISSET(sock, &writeSet) && FD_ISSET(sock, &fWriteSet)/*sanity check*/) resultConditionSet |= SOCKET_WRITABLE;
      if (FD_ISSET(sock, &exceptionSet) && FD_ISSET(sock, &fExceptionSet)/*sanity check*/) resultConditionSet |= SOCKET_EXCEPTION;
      if ((resultConditionSet&handler->conditionSet) != 0 && handler->handlerProc != NULL) {
	fLastHandledSocketNum = sock;
	    // Note: we set "fLastHandledSocketNum" before calling the handler,
            // in case the handler calls "doEventLoop()" reentrantly.
	(*handler->handlerProc)(handler->clientData, resultConditionSet);
	break;
      }
    }
// 还是没找到,,,是真的没找到
    if (handler == NULL) fLastHandledSocketNum = -1;//because we didn't call a handler
  }

  // Also handle any newly-triggered event (Note that we do this *after* calling a socket handler,
  // in case the triggered event handler modifies The set of readable sockets.)
  if (fEventTriggersAreBeingUsed) {
    // Look for an event trigger that needs handling (making sure that we make forward progress through all possible triggers):
    unsigned i = fLastUsedTriggerNum;
    EventTriggerId mask = fLastUsedTriggerMask;

    do {
      i = (i+1)%MAX_NUM_EVENT_TRIGGERS;
      mask >>= 1;
      if (mask == 0) mask = EVENT_TRIGGER_ID_HIGH_BIT;

#ifndef NO_STD_LIB
      if (fTriggersAwaitingHandling[i].test()) {
	fTriggersAwaitingHandling[i].clear();
#else
      if (fTriggersAwaitingHandling[i]) {
	fTriggersAwaitingHandling[i] = False;
#endif
	if (fTriggeredEventHandlers[i] != NULL) {
	  (*fTriggeredEventHandlers[i])(fTriggeredEventClientDatas[i]);
	}

	fLastUsedTriggerMask = mask;
	fLastUsedTriggerNum = i;
	break;
      }
    } while (i != fLastUsedTriggerNum);
  }

// 从队列里面获取第一个已经触发的任务,,,
// 执行定时任务 AlarmHandler 的 handleTimeout方法,,,这个方法会执行 AlarmHandler 中的回调函数
// 所以,提交定时任务在事件循环中会检查,到达时间后执行
  // Also handle any delayed event that may have come due.
  fDelayQueue.handleAlarm();
}

void BasicTaskScheduler
  ::setBackgroundHandling(int socketNum, int conditionSet, BackgroundHandlerProc* handlerProc, void* clientData) {
  if (socketNum < 0) return;
#if !defined(__WIN32__) && !defined(_WIN32) && defined(FD_SETSIZE)
  if (socketNum >= (int)(FD_SETSIZE)) return;
#endif
  FD_CLR((unsigned)socketNum, &fReadSet);
  FD_CLR((unsigned)socketNum, &fWriteSet);
  FD_CLR((unsigned)socketNum, &fExceptionSet);
  if (conditionSet == 0) {
    fHandlers->clearHandler(socketNum);
    if (socketNum+1 == fMaxNumSockets) {
      --fMaxNumSockets;
    }
  } else {
    fHandlers->assignHandler(socketNum, conditionSet, handlerProc, clientData);
    if (socketNum+1 > fMaxNumSockets) {
      fMaxNumSockets = socketNum+1;
    }
    if (conditionSet&SOCKET_READABLE) FD_SET((unsigned)socketNum, &fReadSet);
    if (conditionSet&SOCKET_WRITABLE) FD_SET((unsigned)socketNum, &fWriteSet);
    if (conditionSet&SOCKET_EXCEPTION) FD_SET((unsigned)socketNum, &fExceptionSet);
  }
}

void BasicTaskScheduler::moveSocketHandling(int oldSocketNum, int newSocketNum) {
  if (oldSocketNum < 0 || newSocketNum < 0) return; // sanity check
#if !defined(__WIN32__) && !defined(_WIN32) && defined(FD_SETSIZE)
  if (oldSocketNum >= (int)(FD_SETSIZE) || newSocketNum >= (int)(FD_SETSIZE)) return; // sanity check
#endif
  if (FD_ISSET(oldSocketNum, &fReadSet)) {FD_CLR((unsigned)oldSocketNum, &fReadSet); FD_SET((unsigned)newSocketNum, &fReadSet);}
  if (FD_ISSET(oldSocketNum, &fWriteSet)) {FD_CLR((unsigned)oldSocketNum, &fWriteSet); FD_SET((unsigned)newSocketNum, &fWriteSet);}
  if (FD_ISSET(oldSocketNum, &fExceptionSet)) {FD_CLR((unsigned)oldSocketNum, &fExceptionSet); FD_SET((unsigned)newSocketNum, &fExceptionSet);}
  fHandlers->moveHandler(oldSocketNum, newSocketNum);

  if (oldSocketNum+1 == fMaxNumSockets) {
    --fMaxNumSockets;
  }
  if (newSocketNum+1 > fMaxNumSockets) {
    fMaxNumSockets = newSocketNum+1;
  }
}
