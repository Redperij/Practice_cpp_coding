#pragma once
#ifndef _WEBSITE_H
#define _WEBSITE_H

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <mutex>
#include "Car.h"

class Website {
public:
	Website(const char *n = nullptr);
	~Website();
	void advertise(std::shared_ptr<Car> car);
	void print(std::ostream &out = std::cout);
	void run();
private:
	std::vector<std::weak_ptr<Car>> listing;
	std::string name;
	std::mutex m;
};

#endif