#pragma once
#ifndef _OVERFLOWCOUNTER_H
#define _OVERFLOWCOUNTER_H

#include "Counter.h"
#include <memory>
#include <vector>
#include <iterator>
#include <algorithm>

class OverflowCounter : public Counter {
public:
	//Constructor
	OverflowCounter(int init = 0, int uplim = 0);
	//Destructor
	virtual ~OverflowCounter() = default;
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