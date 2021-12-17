#pragma once
#ifndef _CAR_H
#define _CAR_H

#include <iostream>
#include <string>

class Car {
	friend std::ostream &operator<<(std::ostream &out, const Car &car);
public:
	Car(const char *m = "Ford", const char *l = nullptr, int ml = 0);
	~Car();
	void Read();
	std::string GetLicense() const;
private:
	std::string model;
	std::string license;
	int mileage;
};

#endif