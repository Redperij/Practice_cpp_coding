#pragma once
#ifndef RAND_GEN
#define RAND_GEN

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

class RandGen
{
public:
	RandGen();
	RandGen(const int min, const int max);
	int operator()();
private:
	std::vector<int> numbers;
	int min;
	int max;
};

#endif