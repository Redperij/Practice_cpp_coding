#include <iostream>
#include "Counter.h"
#include "LimitedCounter.h"
#include "OverflowCounter.h"
#include "CounterUser.h"

using namespace std;

void UseCounter(Counter &ctr, int num);

void main() {
	CounterUser cu(5);
	cu.IncrementBy(12); //OUTPUT: two times "Limit has been reached"
	CounterUser cu2(9);
	cu2.IncrementBy(9);
	cout << "Just passing time" << endl;
	cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"
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