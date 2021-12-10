#pragma once
#ifndef COUNTERUSER_H
#define COUNTERUSER_H

#include <iostream>
#include "OverflowCounter.h"
#include "Observer.h"

class CounterUser : public Observer
{
public:
	CounterUser(int lim = 0);
	virtual void HandleLimitReached() override;
	void IncrementBy(const int n);
private:
	OverflowCounter oc;
};

#endif