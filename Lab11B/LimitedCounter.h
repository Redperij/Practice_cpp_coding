#pragma once
#ifndef _LIMITEDCOUNTER_H
#define _LIMITEDCOUNTER_H

#include "Counter.h"
#include <memory>
#include <vector>
#include <iterator>
#include <algorithm>

class LimitedCounter : public Counter {
public:
	//Constructor
	LimitedCounter(int init = 0, int uplim = 0);
	//Destructor
	virtual ~LimitedCounter() = default;
	//Functions
	virtual void inc() override;
	virtual void dec() override;
	virtual void SetObserver(CounterObserver *cobs) override;
	//Operators
	virtual operator int() override;
private:
	//Variables
	int counter;
	int uplim;
	std::vector<CounterObserver*> observers;
	//Functions
	void Notify();
};

#endif