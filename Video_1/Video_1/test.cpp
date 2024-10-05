#include "test.hpp"

test::test(string name) {
	this->name = name;
}

ostream& operator<< (ostream& left, test& right) {
	left << right.name;
	return left;
}