#include <iostream>
#include "Counter.h"
#include "LimitedCounter.h"
#include "OverflowCounter.h"

using namespace std;

void UseCounter(Counter &ctr, int num);

int main(int argc, char** argv) {
	LimitedCounter lc(0, 5);
	OverflowCounter oc(5, 9);

	CounterObserver obs1, obs2, obs3;
	lc.SetObserver(&obs1);
	oc.SetObserver(&obs2);
	lc.SetObserver(&obs3);
	oc.SetObserver(&obs3);

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