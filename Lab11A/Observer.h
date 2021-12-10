#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
	virtual void HandleLimitReached() = 0;
};

#endif