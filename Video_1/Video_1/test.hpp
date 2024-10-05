#pragma once
#include <iostream>
#include <string>
using namespace std;

class test {

public:
	test(string name);
	friend ostream& operator<< (ostream& left, test& right);
private:
	string name;

};