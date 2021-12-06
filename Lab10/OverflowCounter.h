#pragma once
#ifndef _OVERFLOWCOUNTER_H
#define _OVERFLOWCOUNTER_H

#include "Counter.h"
class OverflowCounter : public Counter {
public:
	//Constructor
	OverflowCounter(int init = 0, int uplim = 0);
	//Destructor
	virtual ~OverflowCounter() = default;
	//Functions
	virtual void inc() override;
	virtual void dec() override;
	virtual operator int() override;
private:
	int counter;
	int uplim;
};

#endif