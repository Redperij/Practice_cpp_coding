#include "Point.h"

Point::Point (double xcoord, double ycoord) : x(xcoord), y(ycoord) {}

void Point::input (const char *prompt) {
	bool fail = true;
	do {
		std::cout << prompt;
		if (std::cin >> this->x >> this->y) fail = false;
		if (fail) {
			std::cout << "Error while reading input. Please, try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
	} while (fail);
	
}

void Point::output() const {
	std::cout << "x = " << this->x << " y = " << this->y << std::endl;
}

double Point::area() const {
	return 0;
}

void Point::move (double deltax, double deltay) {

}