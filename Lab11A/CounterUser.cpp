#include "CounterUser.h"

CounterUser::CounterUser(int lim) : oc(0, lim) {
	oc.setObserver(this);
}

void CounterUser::HandleLimitReached() {
	std::cout << "Limit has been reached" << std::endl;
}

void CounterUser::IncrementBy(const int n) {
	for (int i = 0; i < n; i++) {
		oc.inc();
	}
}