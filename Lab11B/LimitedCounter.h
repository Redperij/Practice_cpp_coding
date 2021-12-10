#pragma once
#ifndef _LIMITEDCOUNTER_H
#define _LIMITEDCOUNTER_H

#include "Counter.h"
class LimitedCounter : public Counter {
public:
	//Constructor
	LimitedCounter(int init = 0, int uplim = 0);
	//Destructor
	virtual ~LimitedCounter() = default;
	//Functions
	virtual void inc() override;
	virtual void dec() override;
	virtual operator int() override;
private:
	int counter;
	int uplim;
};

#endif