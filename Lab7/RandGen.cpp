#include "RandGen.h"

RandGen::RandGen()  : min(0), max(10), numbers() { 
	srand(time(NULL)); 
}

RandGen::RandGen(const int min, const int max) : min(min), max(max), numbers() { 
	srand(time(NULL)); 
}

int RandGen::operator()() {
	int number;
	do {
		number = rand() % (max - min) + min + 1;
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}