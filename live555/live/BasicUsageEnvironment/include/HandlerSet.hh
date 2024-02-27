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

#ifndef _HANDLER_SET_HH
#define _HANDLER_SET_HH

#ifndef _BOOLEAN_HH
#include "Boolean.hh"
#endif

////////// HandlerSet (etc.) definition //////////

class HandlerDescriptor {
  HandlerDescriptor(HandlerDescriptor* nextHandler);
  virtual ~HandlerDescriptor();

public:
	// socket描述符
  int socketNum;
	// 条件变量
  int conditionSet;
	// 回调函数
  TaskScheduler::BackgroundHandlerProc* handlerProc;
	// 回调函数参数
  void* clientData;

private:
  // Descriptors are linked together in a doubly-linked list:
  friend class HandlerSet;
  friend class HandlerIterator;
	// 节点前后指针
  HandlerDescriptor* fNextHandler;
  HandlerDescriptor* fPrevHandler;
};

class HandlerSet {
public:
  HandlerSet();
  virtual ~HandlerSet();

// 集合的元素增删改操作
  void assignHandler(int socketNum, int conditionSet, TaskScheduler::BackgroundHandlerProc* handlerProc, void* clientData);
  void clearHandler(int socketNum);
  void moveHandler(int oldSocketNum, int newSocketNum);

private:
	// 查找出 指定socketNum的 HandlerDescriptor 返回
  HandlerDescriptor* lookupHandler(int socketNum);

private:
  friend class HandlerIterator;
	// HandlerDescriptor 的组合元素
	// 这个元素理解为链表头,,,集合内的元素都由这个链表头维护
  HandlerDescriptor fHandlers;
};

class HandlerIterator {
public:
	// 生成一个迭代器
  HandlerIterator(HandlerSet& handlerSet);
  virtual ~HandlerIterator();

  HandlerDescriptor* next(); // returns NULL if none
  void reset();

private:
	// 迭代器内的集合的引用
  HandlerSet& fOurSet;
  HandlerDescriptor* fNextPtr;
};

#endif
