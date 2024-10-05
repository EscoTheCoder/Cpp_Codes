#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <vector>
#define N 6
using namespace std;


class Person {
public:
	Person();
	Person(string name, int salary);
private:
	string name;
	int salary;
};


class Barista : virtual public Person {
public:
	Barista();
	Barista(string name, int salary);
	void prepare();
};

class Waiter : virtual public Person {
public:
	Waiter();
	Waiter(string name, int salary);
	void serve(int customers, Barista& bar);
	void print();
private:
	int customers_served;
};

class Owner : public Waiter, public Barista {
public:
	Owner(string name, int salary);
private:

};


Person::Person() {

}

Person::Person(string name, int salary)
{
	this->name = name;
	this->salary = salary;
}


Barista::Barista() {
}

Barista::Barista(string name, int salary) :
	Person(name, salary) {
}

void Barista::prepare() {
}


Waiter::Waiter() {
	customers_served = 0;
}

Waiter::Waiter(string name, int salary) :
	Person(name, salary) {
	customers_served = 0;
}


void Waiter::print() {
	cout << customers_served<<endl;
}

void Waiter::serve(int customers, Barista& bar) {
	bar.prepare();
	customers_served += customers;
}


Owner::Owner(string name, int salary) :
	Person(name, salary) {

}

//class Test {
//
//public:
//	Test(string name);
//	friend ostream& operator<< (ostream& left, const Test& right);
//private:
//	string name;
//};

//Test::Test(string name) {
//	this->name = name;
//}
//
//ostream& operator<< (ostream& left, const Test& right) {
//	left << right.name;
//	return left;
//}

void twoSum(int* arr, int sum) {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (arr[i] + arr[j] == sum) {
				cout << arr[i] << " " << arr[j] << endl;
				return;
			}
		}
	}
}


int main() {

	//int clients, waiter_to_serve, barista_to_serve;
	//Owner *o = new Owner("babis", 1000);
	//Waiter *e = new Waiter("elpida", 700);
	//Waiter *m = new Waiter("maria", 700);
	//Barista *n = new Barista("nikos", 650);

	//Waiter* waiters[3] = {o,e,m};
	//Barista* baristas[2] = {o,n};

	//srand(time(NULL));
	//for (int i = 0; i < 100; i++) {
	//	clients = 1 + rand() % 5; //tuxaios arithmos 1+(0-4)
	//	waiter_to_serve = rand() % 3; //tuxaios arithmos (0-2)
	//	barista_to_serve = rand() % 2; //tuxaios arithmos (0-1)
	//	waiters[waiter_to_serve]->serve(clients, *baristas[barista_to_serve]);
	//}

	//for (int i = 0; i < 3; i++) {
	//	waiters[i]->print();
	//}

	//delete o;
	//delete e;
	//delete m;
	//delete n;


	/*vector<int> v = { 1,2,3,1 };
	map<int, int> m;

	for (int i = 0; i < v.size(); i++) {
		cout << m[i]<<endl;
		m[v[i]]++;
	}


	for (auto& pair : m) {
		if (pair.second > 1) {
			return true;
		}
	}*/

	/*vector<int> data = { 1,2,4,4 };

	int sum;
	cout << "Dwse sum gia elegxo: ";
	cin >> sum;

	for (int i = 0; i < data.size(); i++) {
		for (int j = i+1; j < data.size(); j++) {
			if (data[i] + data[j] == sum) {
				cout << "VRETHIKE " << i << " " << j;
				break;
			}
		}
	}*/

	/*vector<int> data = { 1,2,3,4,5 };
	int sum = 1;

	for (int i = 0; i < data.size(); i++) {
		sum *= data[i];
	}
	cout << sum;*/

	/*int arr[3][3] = {{1,2,3}, {4,5}, {6}};
	int arr2[6];

	int k = -1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] != 0) {
				k++;
				arr2[k] = arr[i][j];
			}

		}
	}

	for (int i = 0; i < 6; i++) {
		cout << arr2[i] << " ";
	}*/

	/*int nums[7] = { 1,2,2,3,1,4,2 };

	map<int, int> m;

	for (int i = 0; i < 7; i++) {
		m[nums[i]]++;
	}

	int max = 0;
	int max_num = 0;
	int counter = 0;
	int num;

	for (auto &val : m) {
		if (val.second > max) {
			max_num = val.first;
			max = val.second;
		}
	}

	for (auto &val : m) {
		if (val.second == max) {
			counter++;
		}
	}

	if (counter == 1) {

		for (auto val : m) {
			if (val.second == max) {
				cout<<val.first * val.second<<endl;
			}
		}
	}
	cout<<max;*/

	//string name = "2080-02-29";

	//string year = name.substr(0, 4);  // Correct: start at index 0, take 4 characters
	//string month = name.substr(5, 2); // Correct: start at index 5, take 2 characters (for month)
	//string day = name.substr(8, 2);   // Correct: start at index 8, take 2 characters (for day)

	//cout << year << endl << month << endl << day << endl;

	//int year_int = stoi(year);
	//int month_int = stoi(month);
	//int day_int = stoi(day);

	//// Array to store binary number
	//string sum;
	//vector<int> v;

	//// Year binary conversion
	//while (year_int > 0) {
	//	v.push_back(year_int % 2);
	//	year_int = year_int / 2;
	//}

	//// Reading binary representation of year (in reverse order)
	//for (int i = v.size() - 1; i >= 0; i--) {
	//	sum += to_string(v[i]);
	//}

	//sum += "-";

	//v.clear();  // Clear vector for next use

	//// Month binary conversion
	//while (month_int > 0) {
	//	v.push_back(month_int % 2);
	//	month_int = month_int / 2;
	//}

	//// Reading binary representation of month (in reverse order)
	//for (int i = v.size() - 1; i >= 0; i--) {
	//	sum += to_string(v[i]);
	//}

	//sum += "-";

	//v.clear();  // Clear vector for next use

	//// Day binary conversion
	//while (day_int > 0) {
	//	v.push_back(day_int % 2);
	//	day_int = day_int / 2;
	//}

	//// Reading binary representation of day (in reverse order)
	//for (int i = v.size() - 1; i >= 0; i--) {
	//	sum += to_string(v[i]);
	//}

	//cout << sum;
	
	
	//Lambdas
	
	/*int x = 10;
	int y = 20;

	auto add = [] (int x, int y) { return x + y; };

	int result = add(x,y);
	cout << result<<endl;*/

	string test = "HelloWorld";
	
	string token = "";

	auto revereseString = [&]() {
		for (int i = test.length(); i >= 0; i--) {
			token += test[i];
		}
	};

	revereseString();
	cout << token;




	return 0;	
}
