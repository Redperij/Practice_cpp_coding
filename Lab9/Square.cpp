#include "Square.h"

Square::Square(double xcoord, double ycoord, double width, double height) : Point(xcoord, ycoord), width(width), height(height) {}

void Square::input(const char *prompt) {
	bool fail = true;
	do {
		Point::input("Please, give x and y values for square.\n");
		std::cout << prompt;
		if (std::cin >> this->width >> this->height) fail = false;
		if (fail) {
			std::cout << "Error while reading input. Please, try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
	} while (fail);
}

void Square::output() const {
	std::cout << std::setw(8) << std::setprecision(2) << std::fixed << this->area() << " Square with width " << this->width << " and height " << this->height << " is at ";
	Point::output();
}

double Square::area() const {
	return width * height;
}	

bool Square::operator<(const std::shared_ptr<Point> p) const {
	return this->area() < p->area();
}