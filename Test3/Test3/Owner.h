#pragma once
#include "Waiter.h"
#include "Barista.h"


class Owner : public Waiter, public Barista{
public:
	Owner(string name, int salary);

};