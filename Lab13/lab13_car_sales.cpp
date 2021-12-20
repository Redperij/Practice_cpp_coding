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
#include <thread>
#include <chrono>

#include "Car.h"
#include "Website.h"
#include "Dealer.h"

void car_sales();
int get_user_choice();

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
	else {
		std::cout << std::endl << "No memory leaks." << std::endl;
	}

	return 0;
}

void car_sales() {
	std::vector<std::thread> threads;
	std::cout << "Car sales started" << std::endl;
	std::shared_ptr<Website> wa = std::make_shared<Website>("www.autos.com");
	std::shared_ptr<Website> wb = std::make_shared<Website>("www.bilar.com");
	std::shared_ptr<Website> wc = std::make_shared<Website>("www.cars.com");
	Dealer *a = new Dealer("Alan Aldis"); // Turned to simple pointers to manage memory manually. (In order to stop threads)
	Dealer *b = new Dealer("Bill Munny");

	std::cout << std::endl << "Memory test for Basic and First Extra excercises. (Smart pointers)" << std::endl;
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
	}

	//It looks horrible in the console, but I haven't bothered fixing it. Requiremets are a little bit vague and I wasn't sure if it is required.

	std::cout << std::endl << "Second Extra exercise. Threads" << std::endl;
	threads.push_back(std::thread(&Website::run, wa));
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); //For printing one by one. (not consistent)
	threads.push_back(std::thread(&Website::run, wb));
	std::this_thread::sleep_for(std::chrono::milliseconds(100)); //For printing one by one. (not consistent)
	threads.push_back(std::thread(&Website::run, wc));

	bool exit_flag = false;
	while (!exit_flag) {
		std::cout << "Please, choose dealer to buy a car from:" << std::endl << "1. " << a->get_name() << std::endl << "2. " << b->get_name() << std::endl << "3. Exit" << std::endl;
		switch (get_user_choice())
		{
		case 1:
			a->sell();
			break;
		case 2:
			b->sell();
			break;
		case 3:
			exit_flag = true;
			break;
		default:
			std::cout << "Wait... How did this happen?" << std::endl;
			exit_flag = true;
			break;
		}
	}

	delete a; //Delete dealers in order to stop threads.
	delete b;
	for (std::thread &thr : threads) {
		thr.join();
	}

	std::cout << "Car sales ended" << std::endl;
}

int get_user_choice() {
	int choice = -1;
	std::cout << "Input: ";
	while ((!(std::cin >> choice)) || (choice != 1 && choice != 2 && choice != 3)) {	
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "It must be a number from the list." << std::endl;
		std::cout << "Input: ";
	}
	return choice;
}