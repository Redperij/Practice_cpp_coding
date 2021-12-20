#include "Car.h"
#include "Dealer.h"

Car::Car(const char *m, const char *l, int ml, Dealer *dealer) : model(m), license(l ? l : (rand() % 2 ? "FOO-" : "BAR-") + std::to_string(rand() % 999 + 1)), mileage(ml ? ml : rand() % 10000), dealer(dealer) {}

Car::~Car() {
	this->dealer = nullptr;
	std::cout << model << " " << license << " deleted" << std::endl; 
}

void Car::SetDealer(Dealer *dealer) {
	this->dealer = dealer;
}

void Car::Read()
{
	//std::cout << "Enter car information" << std::endl;
	// replace the following with your own code (Edit: It works fine, even generating repeating licenses)
	model = "Seat";
	license = (rand() % 2 ? "ZAP-" : "ZIP-") + std::to_string(rand() % 999 + 1);
	mileage = 10000 + rand() % 10000;
}

std::string Car::GetLicense() const {
	return license;
}

std::ostream &operator<<(std::ostream &out, const Car &car)
{
	if (car.dealer != nullptr)
		std::cout << "Dealer: " << car.dealer->get_name() << std::endl << "Model: " << car.model << std::endl << "License: " << car.license << std::endl << "Mileage: " << car.mileage << std::endl;
	else
		std::cout << "Car has no dealer." << std::endl << "Model: " << car.model << std::endl << "License: " << car.license << std::endl << "Mileage: " << car.mileage << std::endl;
	return out;
}