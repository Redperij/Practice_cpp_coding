#pragma once
#ifndef _DEALER_H
#define _DEALER_H

#include <iostream>
#include "Car.h"
#include "Website.h"

class Dealer {
	friend std::ostream &operator<<(std::ostream &out, const Dealer &dealer);
public:
	Dealer(const char *name_ = "John Doe");
	~Dealer();
	void buy();
	void sell();
	void add(Car *car);
	void add_site(Website *w);
private:
	std::string name;
	std::vector<Car *> cars;
	std::vector<Website *> sites;
};
#endif