#include <iostream>
#include "Counter.h"
#include "LimitedCounter.h"
#include "OverflowCounter.h"

using namespace std;

void UseCounter(Counter &ctr, int num);

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	cout << "Overflow counter" << endl;
	cout << oc << endl; // should display 5
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << "Limited counter" << endl;
	cout << lc << endl; // should display 0
	lc.inc();
	cout << lc << endl; // should display 1
	lc.dec();
	cout << lc << endl; // should display 0
	for(int i = 0; i < 10; ++i) lc.inc(); 
	cout << lc << endl; // should display 5
	UseCounter(lc, -9); 
	cout << lc << endl; // should display 0

	cout << "Funny overflow counter." << endl;
	oc = OverflowCounter(1, 0);
	cout << oc << endl; // should display 1
	UseCounter(oc, 20);
	cout << oc << endl; // should display 0
	UseCounter(oc, -18);
	cout << oc << endl; // should display 0
	oc = OverflowCounter(1, 1);
	cout << oc << endl; // should display 1
	UseCounter(oc, 19);
	cout << oc << endl; // should display 0
	UseCounter(oc, -15);
	cout << oc << endl; // should display 1

	return 0;
}

void UseCounter(Counter &ctr, int num) {
	//Positive num increments counter.
	while (num > 0) {
		ctr.inc();
		num--;
	}
	//Negative num decrements counter.
	while (num < 0) {
		ctr.dec();
		num++;
	}
}