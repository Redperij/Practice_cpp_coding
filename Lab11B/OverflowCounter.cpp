#include "OverflowCounter.h"

OverflowCounter::OverflowCounter(int init, int uplim) : counter(init), uplim(uplim) {}

void OverflowCounter::inc() {
	if (this->counter < this->uplim) this->counter++;
	else this->counter = 0;
}

void OverflowCounter::dec() {
	if (this->counter > 0) this->counter--;
	else this->counter = this->uplim;
}

OverflowCounter::operator int() {
	return this->counter;
}