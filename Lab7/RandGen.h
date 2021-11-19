#pragma once
#ifndef RAND_GEN
#define RAND_GEN

#include <iostream>
#include <vector>
#include <algorithm>

class RandGen
{
public:
	RandGen() : min(0), max(10), numbers() { srand(time(NULL)); }
	RandGen(const int min, const int max) : min(min), max(max), numbers() { srand(time(NULL)); }
	int operator()();
private:
	std::vector<int> numbers;
	int min;
	int max;
};

#endif