#include "Website.h"

Website::Website(const char *n) : name(n ? n : "www.cars" + std::to_string(rand() % 99 + 1) + ".com") {}

Website::~Website() {
	std::cout << name << " deleted" << std::endl;
}

void Website::advertise(std::shared_ptr<Car> car) {
	listing.push_back(car);
}

void Website::print(std::ostream &out) {

	out << name << std::endl;
	for (int i = 0; i < listing.size(); i++) {
		std::shared_ptr<Car> spcar = listing[i].lock();
		if (spcar != nullptr) {
			out << *spcar;
		}
		else { //Erase entry in case car has been sold.
			listing.erase(listing.begin() + i);
			i--;
		}
	}

	out << name << " end of list" << std::endl;
}