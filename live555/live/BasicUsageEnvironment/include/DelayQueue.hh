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
 // Copyright (c) 1996-2024, Live Networks, Inc.  All rights reserved
// Delay queue
// C++ header

#ifndef _DELAY_QUEUE_HH
#define _DELAY_QUEUE_HH

#ifndef _NET_COMMON_H
#include "NetCommon.h"
#endif

#ifdef TIME_BASE
typedef TIME_BASE time_base_seconds;
#else
typedef long time_base_seconds;
#endif

///// A "Timeval" can be either an absolute time, or a time interval /////

class Timeval {
public:
  time_base_seconds seconds() const {
    return fTv.tv_sec;
  }
  time_base_seconds seconds() {
    return fTv.tv_sec;
  }
  time_base_seconds useconds() const {
    return fTv.tv_usec;
  }
  time_base_seconds useconds() {
    return fTv.tv_usec;
  }

  int operator>=(Timeval const& arg2) const;
  int operator<=(Timeval const& arg2) const {
    return arg2 >= *this;
  }
  int operator<(Timeval const& arg2) const {
    return !(*this >= arg2);
  }
  int operator>(Timeval const& arg2) const {
    return arg2 < *this;
  }
  int operator==(Timeval const& arg2) const {
    return *this >= arg2 && arg2 >= *this;
  }
  int operator!=(Timeval const& arg2) const {
    return !(*this == arg2);
  }

  void operator+=(class DelayInterval const& arg2);
  void operator-=(class DelayInterval const& arg2);
  // returns ZERO iff arg2 >= arg1

protected:
  Timeval(time_base_seconds seconds, time_base_seconds useconds) {
    fTv.tv_sec = seconds; fTv.tv_usec = useconds;
  }

private:
  time_base_seconds& secs() {
    return (time_base_seconds&)fTv.tv_sec;
  }
  time_base_seconds& usecs() {
    return (time_base_seconds&)fTv.tv_usec;
  }

  struct timeval fTv;
};

#ifndef max
inline Timeval max(Timeval const& arg1, Timeval const& arg2) {
  return arg1 >= arg2 ? arg1 : arg2;
}
#endif
#ifndef min
inline Timeval min(Timeval const& arg1, Timeval const& arg2) {
  return arg1 <= arg2 ? arg1 : arg2;
}
#endif

class DelayInterval operator-(Timeval const& arg1, Timeval const& arg2);
// returns ZERO iff arg2 >= arg1


///// DelayInterval /////

// Timeval 里面有一个属性 struct timeval,,,实际就是把时间用秒和微妙表示,,,DelayInterval也一样
class DelayInterval: public Timeval {
public:
  DelayInterval(time_base_seconds seconds, time_base_seconds useconds)
    : Timeval(seconds, useconds) {}
};

DelayInterval operator*(short arg1, DelayInterval const& arg2);

extern DelayInterval const DELAY_ZERO;
extern DelayInterval const DELAY_SECOND;
extern DelayInterval const DELAY_MINUTE;
extern DelayInterval const DELAY_HOUR;
extern DelayInterval const DELAY_DAY;

///// _EventTime /////

class _EventTime: public Timeval {
public:
  _EventTime(unsigned secondsSinceEpoch = 0,
	    unsigned usecondsSinceEpoch = 0)
    // We use the Unix standard epoch: January 1, 1970
    : Timeval(secondsSinceEpoch, usecondsSinceEpoch) {}
};

_EventTime TimeNow();

extern _EventTime const THE_END_OF_TIME;


///// DelayQueueEntry /////

// 这是一个队列节点类,
// 内含,定时时间,token,节点指针
class DelayQueueEntry {
public:
  virtual ~DelayQueueEntry();

	// 返回token
  intptr_t token() {
    return fToken;
  }

protected: // abstract base class
	// 延时任务队列节点,实例化参数,,,延时时间,,,token
  DelayQueueEntry(DelayInterval delay, intptr_t token);

	// 执行时间到达后执行的方法,,是一个虚函数,可能被子类重写
  virtual void handleTimeout();

private:
	// 友元 子类 DelayQueue 可以访问 DelayQueueEntry 的私有数据
  friend class DelayQueue;
	// 双向循环队列的前指和后指
  DelayQueueEntry* fNext;
  DelayQueueEntry* fPrev;
	// 定时时间,,, 用秒和微秒表示的时间
	// 以前一个节点为基准,跟前一个节点相差的时间
  DelayInterval fDeltaTimeRemaining;

	// token 是一个数字
  intptr_t fToken;
};

///// DelayQueue /////

// 这个类实现一个队列头,,,队列头内也含有一个节点,,,并且是 节点父类的友元
// 实现队列节点的添加,删除,更新
// 实现一个定时器,检查队列上的节点,到时执行
class DelayQueue: public DelayQueueEntry {
public:
  DelayQueue();
  virtual ~DelayQueue();

	// 节点操作,增删改查
  void addEntry(DelayQueueEntry* newEntry); // returns a token for the entry
  void updateEntry(DelayQueueEntry* entry, DelayInterval newDelay);
  void updateEntry(intptr_t tokenToFind, DelayInterval newDelay);
  void removeEntry(DelayQueueEntry* entry); // but doesn't delete it
  DelayQueueEntry* removeEntry(intptr_t tokenToFind); // but doesn't delete it

	// 下一次节点时间到达时间,,,为0表示已经触发
  DelayInterval const& timeToNextAlarm();
	// 获取一个已经触发的节点,执行节点的 handleTimeout 方法
  void handleAlarm();

private:
	// 获取下一个节点,对于队列头来说,,,即是第一个有效节点
  DelayQueueEntry* head() { return fNext; }
  DelayQueueEntry* findEntryByToken(intptr_t token);
	// 更队列时间,,,因为时间一直会往前走,,这个方法就是以当前时间为基准,,,,
	// 标记队列中已经触发的节点,,,以及更新时间基准
  void synchronize(); // bring the 'time remaining' fields up-to-date

	// 上次同步的时间,,,队列标记触发,,,队列任务的时间更新都是以这个时间为基准的
  _EventTime fLastSyncTime;
};

#endif
