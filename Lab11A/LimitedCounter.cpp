#include "LimitedCounter.h"

LimitedCounter::LimitedCounter(int init, int uplim) : counter(init), uplim(uplim) {}

void LimitedCounter::inc() {
	if (this->counter < this->uplim) this->counter++;
}

void LimitedCounter::dec() {
	if (this->counter > 0) this->counter--;
}

LimitedCounter::operator int() {
	return this->counter;
}