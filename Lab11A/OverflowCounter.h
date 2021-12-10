#pragma once
#ifndef _OVERFLOWCOUNTER_H
#define _OVERFLOWCOUNTER_H

#include "Counter.h"
#include "Observer.h"

class OverflowCounter : public Counter {
public:
	//Constructor
	OverflowCounter(int init = 0, int uplim = 0, Observer *obs = nullptr);
	//Destructor
	virtual ~OverflowCounter() = default;
	//Functions
	virtual void inc() override;
	virtual void dec() override;
	void setObserver(Observer *obs);
	//Operators
	virtual operator int() override;
private:
	//Variables
	int counter;
	int uplim;
	Observer *obs;
	//Functions
	void Notify();
};

#endif