#pragma once
#ifndef COUNTEROBSERVER_H
#define COUNTEROBSERVER_H

#include <iostream>
#include <typeinfo>
#include "Counter.h"

class Counter;
class OverflowCounter;
class LimitedCounter;

class CounterObserver
{
public:
	virtual void HandleLimitReached(Counter *ctr);
};

#endif