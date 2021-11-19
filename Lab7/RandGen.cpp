#include "RandGen.h"

int RandGen::operator()() {
	int number;
	do {
		number = rand() % (max - min) + min + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}