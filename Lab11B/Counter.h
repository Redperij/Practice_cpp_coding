#pragma once
#ifndef _COUNTER_H
#define _COUNTER_H

#include "CounterObserver.h"

class CounterObserver;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual void SetObserver(CounterObserver *cobs) = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

#endif