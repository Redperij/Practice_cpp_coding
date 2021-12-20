#pragma once
#ifndef _CAR_H
#define _CAR_H

#include <iostream>
#include <string>

class Dealer;

class Car {
	friend std::ostream &operator<<(std::ostream &out, const Car &car);
public:
	Car(const char *m = "Ford", const char *l = nullptr, int ml = 0, Dealer *dealer = nullptr);
	~Car();
	void SetDealer(Dealer *dealer);
	void Read();
	std::string GetLicense() const;
private:
	std::string model;
	std::string license;
	int mileage;
	Dealer *dealer;
};

#endif