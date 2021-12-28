#include "UniqueRng.h"

UniqueRng::UniqueRng(unsigned int min, unsigned int max) : lower(min), upper(max) { srand(time(NULL)); }

//Gives unique random numbers in specified for the object range.
unsigned int UniqueRng::operator()() {
	if (numbers.size() <= this->upper - this->lower && this->upper != 0) { //The same as: "numbers.size() < this->upper - this->lower + 1"
		unsigned int number;
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