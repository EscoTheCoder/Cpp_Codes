#pragma once
#include "Person.h"


class Barista : virtual public Person{

public:
	Barista();
	Barista(string name, int salary);
	void prepare();


};