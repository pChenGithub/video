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
//	Help by Carlo Bonamico to get working for Windows
// Delay queue
// Implementation

#include "DelayQueue.hh"
#include "GroupsockHelper.hh"

static const int MILLION = 1000000;

///// Timeval /////

int Timeval::operator>=(const Timeval& arg2) const {
  return seconds() > arg2.seconds()
    || (seconds() == arg2.seconds()
	&& useconds() >= arg2.useconds());
}

void Timeval::operator+=(const DelayInterval& arg2) {
  secs() += arg2.seconds(); usecs() += arg2.useconds();
  if (useconds() >= MILLION) {
    usecs() -= MILLION;
    ++secs();
  }
}

void Timeval::operator-=(const DelayInterval& arg2) {
  secs() -= arg2.seconds(); usecs() -= arg2.useconds();
  if ((int)useconds() < 0) {
    usecs() += MILLION;
    --secs();
  }
  if ((int)seconds() < 0)
    secs() = usecs() = 0;

}

DelayInterval operator-(const Timeval& arg1, const Timeval& arg2) {
  time_base_seconds secs = arg1.seconds() - arg2.seconds();
  time_base_seconds usecs = arg1.useconds() - arg2.useconds();

  if ((int)usecs < 0) {
    usecs += MILLION;
    --secs;
  }
  if ((int)secs < 0)
    return DELAY_ZERO;
  else
    return DelayInterval(secs, usecs);
}


///// DelayInterval /////

DelayInterval operator*(short arg1, const DelayInterval& arg2) {
  time_base_seconds result_seconds = arg1*arg2.seconds();
  time_base_seconds result_useconds = arg1*arg2.useconds();

  time_base_seconds carry = result_useconds/MILLION;
  result_useconds -= carry*MILLION;
  result_seconds += carry;

  return DelayInterval(result_seconds, result_useconds);
}

#ifndef INT_MAX
#define INT_MAX	0x7FFFFFFF
#endif
const DelayInterval DELAY_ZERO(0, 0);
const DelayInterval DELAY_SECOND(1, 0);
const DelayInterval DELAY_MINUTE = 60*DELAY_SECOND;
const DelayInterval DELAY_HOUR = 60*DELAY_MINUTE;
const DelayInterval DELAY_DAY = 24*DELAY_HOUR;
const DelayInterval ETERNITY(INT_MAX, MILLION-1);
// used internally to make the implementation work


///// DelayQueueEntry /////

// 实例化一个定时队列,
// delay, 定时时间
// token token目前不知道作用???
DelayQueueEntry::DelayQueueEntry(DelayInterval delay, intptr_t token)
  : fDeltaTimeRemaining(delay), fToken(token) {
  fNext = fPrev = this;
}

DelayQueueEntry::~DelayQueueEntry() {
}

// 是指该节点代表的任务时间到了,,,基类实现,自销毁
void DelayQueueEntry::handleTimeout() {
  delete this;
}


///// DelayQueue /////

DelayQueue::DelayQueue()
	// 延时任务队列头创建,,,给的最大,固定的时间,token为0,,,说明永远不会被执行到
  : DelayQueueEntry(ETERNITY, 0) {
	// 创建之后记录一下时间
  fLastSyncTime = TimeNow();
}

DelayQueue::~DelayQueue() {
  while (fNext != this) {
    DelayQueueEntry* entryToRemove = fNext;
    removeEntry(entryToRemove);
    delete entryToRemove;
  }
}

// 队列添加一个节点
void DelayQueue::addEntry(DelayQueueEntry* newEntry) {
  synchronize();

	// 获取第一个有效节点
  DelayQueueEntry* cur = head();
	// 如果插入的节点 超时 时间比第一个后面,,
	// 重复检查第二个,,一直找到,第一个在, 新节点后面的节点
	// 总结,,这个延时队列是按照超时时间来的,越后面的是发生越晚
	// 而且,每个节点的超时时间都是,,,前一个节点超时后,,,过多久
  while (newEntry->fDeltaTimeRemaining >= cur->fDeltaTimeRemaining) {
	// 新节点的延时时间,,,要减去,,之前执行的时间
    newEntry->fDeltaTimeRemaining -= cur->fDeltaTimeRemaining;
    cur = cur->fNext;
  }

	// 新节点,插入的后一个节点要减去,,插入节点的执行时间,,,,再后面的就不用管了,时间没变
  cur->fDeltaTimeRemaining -= newEntry->fDeltaTimeRemaining;

  // Add "newEntry" to the queue, just before "cur":
	// 新节点 进入队列
  newEntry->fNext = cur;
  newEntry->fPrev = cur->fPrev;
  cur->fPrev = newEntry->fPrev->fNext = newEntry;
}

// 更新指定节点的执行时间
void DelayQueue::updateEntry(DelayQueueEntry* entry, DelayInterval newDelay) {
  if (entry == NULL) return;

	// 先移出来,,修改时间后,再加入
  removeEntry(entry);
  entry->fDeltaTimeRemaining = newDelay;
  addEntry(entry);
}

// 按token修改 指定节点的时间
void DelayQueue::updateEntry(intptr_t tokenToFind, DelayInterval newDelay) {
	// 按token找到节点,然后调用修改
  DelayQueueEntry* entry = findEntryByToken(tokenToFind);
  updateEntry(entry, newDelay);
}

// 删除一个节点
void DelayQueue::removeEntry(DelayQueueEntry* entry) {
  if (entry == NULL || entry->fNext == NULL) return;

	// 节点后面的一个节点,时间需要加回来
  entry->fNext->fDeltaTimeRemaining += entry->fDeltaTimeRemaining;
	// 节点移除队列
  entry->fPrev->fNext = entry->fNext;
  entry->fNext->fPrev = entry->fPrev;
  entry->fNext = entry->fPrev = NULL;
  // in case we should try to remove it again
}

// 按token查找移除
DelayQueueEntry* DelayQueue::removeEntry(intptr_t tokenToFind) {
  DelayQueueEntry* entry = findEntryByToken(tokenToFind);
  removeEntry(entry);
  return entry;
}

// 还有多长时间下一个 定时器
DelayInterval const& DelayQueue::timeToNextAlarm() {
	// 0秒,,已经有触发了
  if (head()->fDeltaTimeRemaining == DELAY_ZERO) return DELAY_ZERO; // a common case

	// 如果没有触发的,更新时间,然后返回第一个节点的时间,,,
	// 更新时间后,,也有可能变成 DELAY_ZERO
  synchronize();
  return head()->fDeltaTimeRemaining;
}

void DelayQueue::handleAlarm() {
	// 第一个节点时间还没到,,更新时间
  if (head()->fDeltaTimeRemaining != DELAY_ZERO) synchronize();

  if (head()->fDeltaTimeRemaining == DELAY_ZERO) {
    // This event is due to be handled:
	// 第一个节点获取,,然后移出,,,再执行节点的 handleTimeout
    DelayQueueEntry* toRemove = head();
    removeEntry(toRemove); // do this first, in case handler accesses queue

	// handleTimeout 是基类 DelayQueueEntry 实现的方法,,,销毁自己
	// handleTimeout 是虚函数,,如果子类中重载了,那么是执行的子类方法
    toRemove->handleTimeout();
  }
}

DelayQueueEntry* DelayQueue::findEntryByToken(intptr_t tokenToFind) {
  DelayQueueEntry* cur = head();
  while (cur != this) {
    if (cur->token() == tokenToFind) return cur;
    cur = cur->fNext;
  }

  return NULL;
}

// 这个函数会检查当前节点是否已经时间到达
// 并且更新新的首节点的时间
// 总结为重新定位时间0点,,,超时的标记过期
void DelayQueue::synchronize() {
  // First, figure out how much time has elapsed since the last sync:
	// 获取当前时间
  _EventTime timeNow = TimeNow();
	// 当前时间在上次同步的时间的前面了,,,重置同步时间,,结束这次检查
  if (timeNow < fLastSyncTime) {
    // The system clock has apparently gone back in time; reset our sync time and return:
    fLastSyncTime  = timeNow;
    return;
  }
	// 计算当前时间和上次同步时间的时间差,然后更新同步时间
	// timeSinceLastSync 是 距离上次同步时间过了多久了
	// 理解:所有的节点时间都是以 fLastSyncTime 时间为0点
	// 节点的时间是指,,前面的节点后过多久
	// 第一个节点是fLastSyncTime 后过多久
	// 
  DelayInterval timeSinceLastSync = timeNow - fLastSyncTime;
	// 修改同步时间到,当前
  fLastSyncTime = timeNow;

  // Then, adjust the delay queue for any entries whose time is up:
	// 初始化指针,,待会儿要遍历队列
  DelayQueueEntry* curEntry = head();
	// 如果这个节点的定时时间 小于 时间差, 代表时间已经到了
  while (timeSinceLastSync >= curEntry->fDeltaTimeRemaining) {
	// 每次判断一个节点后,要以这个节点为0点,,,所以,,,过了多久这个变量,,也要从这个节点开始计算
    timeSinceLastSync -= curEntry->fDeltaTimeRemaining;
	// 当前节点的定时时间置成0, 应该是标记为时间已经到了
    curEntry->fDeltaTimeRemaining = DELAY_ZERO;
	// 处理下一个节点
    curEntry = curEntry->fNext;
  }
	// 前面的已经超时的节点,包括刚好超时的节点,都标记为时间到了
	// 后面的都是还没到时间的节点,,都在 最新的 timeSinceLastSync 后面,,,
	// 后面第一个节点,要减掉这个 以 最后一个时间到达,为0的时间差
  curEntry->fDeltaTimeRemaining -= timeSinceLastSync;
}


///// _EventTime /////

// 获取当前时间
_EventTime TimeNow() {
  struct timeval tvNow;

  gettimeofday(&tvNow, NULL);

  return _EventTime(tvNow.tv_sec, tvNow.tv_usec);
}

const _EventTime THE_END_OF_TIME(INT_MAX);
