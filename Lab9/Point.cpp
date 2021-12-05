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
	std::cout << "Point (" << this->x << " ; " << this->y << ")" << std::endl;
}

double Point::area() const {
	return 0;
}

void Point::move (double deltax, double deltay) {
	this->x += deltax;
	this->y += deltay;
}

bool Point::operator<(const std::shared_ptr<Point> p) const {
	return this->area() < p->area();
}

bool sort_by_area(const std::shared_ptr<Point> p1, const std::shared_ptr<Point> p2) {
	return p1->area() < p2->area();
}