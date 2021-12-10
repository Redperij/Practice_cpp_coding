#include "OverflowCounter.h"

OverflowCounter::OverflowCounter(int init, int uplim, Observer *obs) : counter(init), uplim(uplim), obs(obs) {}

void OverflowCounter::inc() {
	if (this->counter < this->uplim) {
		this->counter++;
	}
	else {
		this->counter = 0;
		this->Notify();
	}
}

void OverflowCounter::dec() {
	if (this->counter > 0) {
		this->counter--;
	}
	else {
		this->counter = this->uplim;
	}
}

void OverflowCounter::setObserver(Observer *obs) {
	this->obs = obs;
}

OverflowCounter::operator int() {
	return this->counter;
}

void OverflowCounter::Notify() {
	this->obs->HandleLimitReached();
}