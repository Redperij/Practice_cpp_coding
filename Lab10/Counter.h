#pragma once
#ifndef _COUNTER_H
#define _COUNTER_H

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

#endif