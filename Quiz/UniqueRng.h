#pragma once
#ifndef _UniqueRng_h
#define _UniqueRng_h

#include <vector>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>

class UniqueRng {
public:
    UniqueRng(unsigned int min = 0, unsigned int max = 10);
    int operator()();
private:
    unsigned int lower;
    unsigned int upper;
    std::vector<int> numbers;
};

#endif