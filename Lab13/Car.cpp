#include "Car.h"

Car::Car(const char *m, const char *l, int ml) : model(m), license(l ? l : (rand() % 2 ? "FOO-" : "BAR-") + std::to_string(rand() % 999 + 1)), mileage(ml ? ml : rand() % 10000) {}

Car::~Car() {
	std::cout << model << " " << license << " deleted" << std::endl; 
}

void Car::Read()
{
	//std::cout << "Enter car information" << std::endl;
	// replace the following with your own code
	model = "Seat";
	license = (rand() % 2 ? "ZAP-" : "ZIP-") + std::to_string(rand() % 999 + 1);
	mileage = 10000 + rand() % 10000;
}

std::string Car::GetLicense() const {
	return license;
}

std::ostream &operator<<(std::ostream &out, const Car &car)
{
	std::cout << "Model: " << car.model << std::endl << "License: " << car.license << std::endl << "Mileage: " << car.mileage << std::endl;

	return out;
}