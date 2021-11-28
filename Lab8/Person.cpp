#include "Person.h"

Person::Person(const char *name) : name(name) {}

void Person::identity() const {
	if (name != "nobody") {
		std::cout << "My name is: " << this->name << std::endl;
	}
}

void Person::interrogate() {}