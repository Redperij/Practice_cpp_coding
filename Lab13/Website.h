#pragma once
#ifndef _WEBSITE_H
#define _WEBSITE_H

#include <iostream>
#include <vector>
#include "Car.h"

class Website {
public:
	Website(const char *n = nullptr);
	~Website();
	void advertise(Car *car);
	void print(std::ostream &out = std::cout);
	void remove(Car *car);
private:
	std::vector<Car *> listing;
	std::string name;
};

#endif