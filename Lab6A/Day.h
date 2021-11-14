#pragma once
#ifndef DAY_H
#define DAY_H

#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <sstream>
#include <algorithm>
#include "Time.h"

class Day {
    friend std::ostream &operator<<(std::ostream &out, const Day &day);
    friend std::istream &operator>>(std::istream &in, Day &day);
public:
    //Constructors
    Day();
    //Logic
    bool from_str(const std::string &s);
    std::string to_str();
    void dst(int offset);
    //Overloads
private:
    int day;
    std::string month;
    std::vector<Time> list;
};

#endif