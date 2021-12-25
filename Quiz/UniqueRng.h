#pragma once
#ifndef _UniqueRng_h
#define _UniqueRng_h

#include "main.h"
#include <ctime>

class UniqueRng {
public:
    UniqueRng(unsigned int min = 0, unsigned int max = 10);
    unsigned int operator()();
private:
    unsigned int lower;
    unsigned int upper;
    std::vector<int> numbers;
};

#endif