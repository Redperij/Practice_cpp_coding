#pragma once
#ifndef _DEALER_H
#define _DEALER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Car.h"
#include "Website.h"

class Dealer {
	friend std::ostream &operator<<(std::ostream &out, const Dealer &dealer);
public:
	Dealer(const char *name_ = "John Doe");
	~Dealer();
	void buy();
	void sell();
	void add(std::shared_ptr<Car> car);
	void add_site(std::shared_ptr<Website> w);
private:
	std::string name;
	std::vector<std::shared_ptr<Car>> cars;
	std::vector<std::shared_ptr<Website>> sites;
};
#endif