#pragma once
#include "Person.h"
#include "Barista.h"

class Waiter : virtual public Person{

public:
	Waiter();
	Waiter(string name, int salary);
	void serve(int customers, Barista& bar);

private:
	int customers_served;
};