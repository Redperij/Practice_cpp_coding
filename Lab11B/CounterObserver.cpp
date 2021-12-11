#include "CounterObserver.h"

void CounterObserver::HandleLimitReached(Counter *ctr) {
	if (!strcmp(typeid(*ctr).name(), "class OverflowCounter")) //Haven't managed to make it via type id's. typeid(OverflowCounter) throws an error.
		std::cout << "Overflow occured. Counter value: " << *ctr << std::endl;
	else
		std::cout << "Limit reached. Counter value: " << *ctr << std::endl;
}