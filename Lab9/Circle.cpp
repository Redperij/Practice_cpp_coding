#include "Circle.h"

Circle::Circle (double xcoord, double ycoord, double radius) : Point(xcoord, ycoord), radius(radius) {}

void Circle::input(const char *prompt) {
	bool fail = true;
	do {
		Point::input("Please, give x and y values for circle.\n");
		std::cout << prompt;
		if (std::cin >> this->radius) fail = false;
		if (fail) {
			std::cout << "Error while reading input. Please, try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
	} while (fail);
}

void Circle::output() const {
	std::cout << std::setw(8) << std::setprecision(2) << std::fixed << this->area() << " Circle with radius " << this->radius << " is at ";
	Point::output();
}

double Circle::area() const {
	return radius * radius * 3.14;
}

bool Circle::operator<(const std::shared_ptr<Point> p) const {
	return this->area() < p->area();
}