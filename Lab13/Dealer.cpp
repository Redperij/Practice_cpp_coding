#include "Dealer.h"

Dealer::Dealer(const char *name_) : name(name_) {};

Dealer::~Dealer() {
	std::cout << name << " deleted" << std::endl;
}

void Dealer::buy()
{
	Car *car = new Car;
	car->Read();
	add(car);
}

void Dealer::sell()
{
	std::cout << *this; // print my list of cars
	std::cout << "Enter license of car you want to buy" << std::endl;

	std::string license;
	std::cin >> license;
	auto ci = std::find_if(cars.begin(), cars.end(), [&license](Car *c) {
		return license == c->GetLicense();
		});
	if (ci != cars.end()) {
		for (auto site : sites) site->remove(*ci); // modify code wso that this is not needed
		cars.erase(ci);
	}
}

void Dealer::add(Car *car) {
	cars.push_back(car);
	for (auto site : sites) site->advertise(car);
}
void Dealer::add_site(Website *w) {
	sites.push_back(w);
}

std::ostream &operator<<(std::ostream &out, const Dealer &dealer)
{
	std::cout << dealer.name << "'s cars for sale" << std::endl;
	for (auto car : dealer.cars) std::cout << *car;
	std::cout << "End of " << dealer.name << "'s cars listing" << std::endl;
	return out;
}