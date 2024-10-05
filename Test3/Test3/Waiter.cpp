#include "Waiter.h"

Waiter::Waiter(string name, int salary) :
	Person(name, salary) {
	customers_served = 0;
}

Waiter::Waiter() {
}

void Waiter::serve(int customers, Barista& bar)
{
	bar.prepare();
	customers_served += customers;
}
