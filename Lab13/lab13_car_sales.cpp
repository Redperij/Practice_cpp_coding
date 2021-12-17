#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>

#include "Car.h"
#include "Website.h"
#include "Dealer.h"

void car_sales() {
	std::cout << "Car sales started" << std::endl;
	Website *wa = new Website("www.autos.com");
	Website *wb = new Website("www.bilar.com");
	Website *wc = new Website("www.cars.com");
	Dealer *a = new Dealer("Alan Aldis");
	Dealer *b = new Dealer("Bill Munny");
	{
		Dealer *c = new Dealer("Casey Ball");
		Car *ca = new Car;
		Car *cb = new Car;

		a->add_site(wa);
		a->add_site(wb);
		b->add_site(wb);
		b->add_site(wc);
		c->add_site(wa);
		c->add_site(wb);
		c->add_site(wc);

		a->buy();
		a->buy();
		a->buy();
		a->buy();

		b->buy();
		b->buy();
		b->buy();

		c->buy();
		c->buy();
		c->add(ca);
		c->add(cb);

		wa->print();
		wb->print();
		wc->print();

		std::cout << *a << *b << *c << std::endl;

		a->sell();

		std::cout << *a << *b << *c << std::endl;

		wa->print();
		wb->print();
		wc->print();
	}

	wa->print();
	wb->print();
	wc->print();

	std::cout << "Car sales ended" << std::endl;
}

int main(int argc, char **argv) {
	_CrtMemState s1;
	_CrtMemCheckpoint(&s1);

	srand(time(NULL));

	car_sales();

	_CrtMemState s2,s3;
	_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s1, &s2)) {
		_CrtDumpMemoryLeaks();
		_CrtMemDumpStatistics(&s3);
	}

	return 0;
}


