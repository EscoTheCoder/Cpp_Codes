#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person {
public:
	Person();
	Person(string name, int salary);
private:
	string name;
	int salary;
};