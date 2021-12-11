#include "UniqueRng.h"

UniqueRng::UniqueRng(unsigned int min, unsigned int max) : lower(min), upper(max) { srand(time(NULL)); }

int UniqueRng::operator()() {
	if (numbers.size() <= this->upper - this->lower) { //The same as: "numbers.size() < this->upper - this->lower + 1"
		int number;
		do {
			number = rand() % (this->upper - this->lower + 1) + this->lower;
		} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
		numbers.push_back(number);
		return number;
	}
	else {
		throw std::runtime_error("Exception: Unable to produce unique random number");
		return -1;
	}
}