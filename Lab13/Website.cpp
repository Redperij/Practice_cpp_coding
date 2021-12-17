#include "Website.h"

Website::Website(const char *n) : name(n ? n : "www.cars" + std::to_string(rand() % 99 + 1) + ".com") {}

Website::~Website() {
	std::cout << name << " deleted" << std::endl;
}

void Website::advertise(Car *car) {
	listing.push_back(car);
}

void Website::print(std::ostream &out) {
	out << name << std::endl; for (auto car : listing) out << *car; out << name << " end of list" << std::endl;
}

void Website::remove(Car *car) {
	listing.erase(std::remove(listing.begin(), listing.end(), car), listing.end());
}