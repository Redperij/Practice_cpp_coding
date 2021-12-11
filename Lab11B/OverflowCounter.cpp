#include "OverflowCounter.h"

OverflowCounter::OverflowCounter(int init, int uplim) : counter(init), uplim(uplim) {}

void OverflowCounter::inc() {
	if (this->counter < this->uplim) {
		this->counter++;
	}
	else {
		this->counter = 0;
		Notify();
	}
}

void OverflowCounter::dec() {
	if (this->counter > 0) {
		this->counter--;
	}
	else {
		this->counter = this->uplim;
		Notify();
	}
}

void OverflowCounter::SetObserver(CounterObserver *cobs)
{
	observers.push_back(cobs);
}

OverflowCounter::operator int() {
	return this->counter;
}

void OverflowCounter::Notify() {
	for (auto obs : observers) obs->HandleLimitReached(this);
}