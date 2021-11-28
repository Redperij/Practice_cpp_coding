#include "Spy.h"

Spy::Spy (const std::string name, const std::string alias, int resistance) : name(name), alias(alias), resistance(resistance) {}

void Spy::set_identity(const char *alias) {
	this->alias = alias;
}

void Spy::identity() const {
	if (this->resistance > 0 && alias != "nobody") {
		std::cout << "My name is: " << this->alias << std::endl;
	}
	else {
		std::cout << "My name is: " << this->name << std::endl;
		std::cout << "My alias is: " << this->alias << std::endl;
	}
}

void Spy::interrogate() {
	if (this->resistance > 0) this->resistance--;
}