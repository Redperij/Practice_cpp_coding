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
	std::shared_ptr<Website> wa = std::make_shared<Website>("www.autos.com");
	std::shared_ptr<Website> wb = std::make_shared<Website>("www.bilar.com");
	std::shared_ptr<Website> wc = std::make_shared<Website>("www.cars.com");
	std::shared_ptr<Dealer> a = std::make_shared<Dealer>("Alan Aldis");
	std::shared_ptr<Dealer> b = std::make_shared<Dealer>("Bill Munny");
	{
		std::shared_ptr<Dealer> c = std::make_shared<Dealer>("Casey Ball");
		std::shared_ptr<Car> ca = std::make_shared<Car>();
		std::shared_ptr<Car> cb = std::make_shared<Car>();

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