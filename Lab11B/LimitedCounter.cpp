#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int init, int uplim) : counter(init), uplim(uplim) {}

void LimitedCounter::inc() {
	if (this->counter < this->uplim) this->counter++;
	else Notify();
}

void LimitedCounter::dec() {
	if (this->counter > 0) this->counter--;
	else Notify();
}

void LimitedCounter::SetObserver(CounterObserver *cobs)
{
	observers.push_back(cobs);
}

LimitedCounter::operator int() {
	return this->counter;
}

void LimitedCounter::Notify() {
	for (auto obs : observers) obs->HandleLimitReached(this);
}