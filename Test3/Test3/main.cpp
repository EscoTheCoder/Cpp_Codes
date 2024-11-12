#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <fstream>
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

class ARRAY {
private:
	int* arr;
	int size;
public:
	ARRAY(int size);
	~ARRAY();
	void set_item(int pos, int value);
	int get_item(int pos);
	void print();
	ARRAY& operator= (const ARRAY& right) {
		if (this == &right) {
			return *this;
		}

		delete[] arr;

		size = right.size;

		if (right.arr) {
			arr = new int[size];

			for (int i = 0; i < size; i++) {
				arr[i] = right.arr[i];
			}
		}
		else {
			arr = nullptr;
		}

		return *this;
	}
};

ARRAY::ARRAY(int size) {
	this->size = size;
	arr = new int[size];
	if (!arr) {
		cout << "error allocating memory!";
	}
}

ARRAY::~ARRAY() {
	delete[] arr;
}

int ARRAY::get_item(int pos) {
	if (pos>=0 && pos<size) {
		return arr[pos];
	}
	else {
		cout << "out of bounds" << endl;
	}
}

void ARRAY::set_item(int pos, int value) {
	if (pos >= 0 && pos < size) {
		arr[pos] = value;
	}
	else {
		cout << "out of bounds" << endl;
	}
}

void ARRAY::print() {
	cout << "[";
	for (int i = 0; i < size-1; i++) {
		cout << arr[i]<<", ";
	}
	cout << arr[size - 1];
	cout << "]";
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

//void twoSum(int* arr, int sum) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 1; j < N; j++) {
//			if (arr[i] + arr[j] == sum) {
//				cout << arr[i] << " " << arr[j] << endl;
//				return;
//			}
//		}
//	}
//}

//void g(const string& arg) { // Υπόσχεται να μην αλλάξει το όρισμα.
//	cout << arg;
//}
//
//void incr(int* arg, int size) { // Το arg δείχνει στην πρώτη θέση
//	// του myArray της main.
//	cout << "*" << " " << *arg << " " << "*";
//	for (int i = 0; i < size; i++) {
//		arg[i]++; // Αλλάζει τον πίνακα της main.
//	} // Χρειάζεται να περνάμε το μέγεθος
//	cout << endl;
//}
//
//template <typename T>
//void print(T &arg) {
//	cout << arg<<endl;
//}

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

	/*string test = "HelloWorld";

	string token = "";

	auto revereseString = [&]() {
		for (int i = test.length(); i >= 0; i--) {
			token += test[i];
		}
	};

	revereseString();
	cout << token;*/

	/*int num = 5;
	int *x = new int;
	cout << x<<" "<<&x<<endl;
	x = &num;
	cout << num << " " << &num<<endl;

	cout << x << " " << &x<<" "<<*x << endl;*/

	/*int** arr;
	arr = new  int* [3];

	for (int i = 0; i < 3; i++) {
		arr[i] = new int[4];
		if (!arr) {
			cout << "Error allocating memory!";
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = i * j;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete [] arr[i];
	}
	delete [] arr;*/

	/*int x;
	cout << "Dwse timh:";
	cin >> x;
	cout << x << " " << &x<<endl;

	int* p = &x;
	cout << p << " " << &p << endl;
	cout << *p << endl;

	int** pp = &p;
	cout << pp << " " << &pp << endl;
	cout << **pp << endl;
	cout << *pp << endl;*/

	/*ARRAY array(10);
	ARRAY array2(10);

	for (int i = 0; i < 10; i++) {
		array.set_item(i, i * i);
	}

	for (int i = 0; i < 10; i++) {
		array2.set_item(i, i * i * i);
	}

	array = array2;

	array.print();
	array2.print();*/

	/*vector<char> name = { 'n','i','k','o','l','a','s' };
	vector<int> a(20);

	for (int i = 0; i < a.size(); i++) {
		cout << a[i]<<" ";
	}*/

	//int myArray[5] = { 1,2,3,4,5 };

	//incr(myArray, 5);

	//for (int i = 0; i < 5; i++) {
	//	cout << myArray[i] << " "; // Τυπώνει «2, 3, 4 ».
	//}


	//fstream file;
	//file.open("test.txt", ios::out);
	//
	//string word;
	//
	//if (file.is_open()) {
	//	for (int i = 0; i < 10; i++) {
	//		cout << "Dwse lejh :";
	//		cin >> word;
	//		file << word << endl;
	//	}
	//	file.close();
	//}
	//
	//vector<string> lst;
	//
	//file.open("test.txt", ios::in);
	//
	//if (file.is_open()) {
	//	while (getline(file, word)) {
	//		lst.push_back(word);
	//	}
	//
	//	for (const auto& i : lst) {
	//		cout << i << " ";
	//	}
	//	file.close();
	//}

class complex {
public:
	complex();
	complex(double real, double imag);
	void set_real(double in_real);
	void set_imag(double in_imag);
	double get_real() const;
	double get_imag() const;
	complex operator+ (const complex& right) const; //operator +    uperfwrtwsh tou telesth +
	complex operator+ (int i) const; //operator +    uperfwrtwsh tou telesth + (prosthiki arithmou)
	complex operator-(const complex& right) const; //operator -    uperfwrtwsh tou telesth -
	complex operator++ (int right); //operator +    uperfwrtwsh tou telesth ++ -------> x++
	complex& operator++ (); //operator +    uperfwrtwsh tou telesth ++  -----> ++x
	complex& operator= (const complex& right); //operator +    uperfwrtwsh tou telesth =
	//int &operator[] (int i);
	friend complex operator+ (int left, complex& right); //operator +    uperfwrtwsh tou telesth +
	friend ostream& operator<<(ostream& left, const complex& right);
	//friend istream &operator>>(istream &left, STRING &obj);
private:
	double real;
	double imag;
};

complex::complex() {
}

complex::complex(double real, double imag) {
	this->real = real;
	this->imag = imag;
}

void complex::set_real(double in_real)
{
	real = in_real;
}

void complex::set_imag(double in_imag)
{
	imag = in_imag;
}

double complex::get_real() const
{
	return real;
}

double complex::get_imag() const
{
	return imag;
}

complex complex::operator+ (const complex& right) const {
	return complex(real + right.real, imag + right.imag);
}

complex complex::operator+ (int i) const {
	return complex(real + i, imag + i);
}

complex complex::operator- (const complex& right) const {
	return complex(real - right.real, imag - right.imag);
}

complex complex::operator++ (int right) { //METATHEMATIKOS TELESTHS

	return complex(real++, imag++);
}

complex& complex::operator++ () { //PROTHEMATIKOS TELESTHS

	++real;
	++imag;
	return *this; //*this  = left stoixeio
}

complex& complex::operator= (const complex& right) {

	if (this == &right) {
		return *this; //*this  = left stoixeio
	}

	real = right.real;
	imag = right.imag;
	return *this;
}

complex operator+ (int left, complex& right) {
	complex result;

	result.real = left + right.real;
	result.imag = left + right.imag;
	
	return result;
}

ostream& operator<<(ostream& left, const complex& right) {
	left << "(" << right.real << ", " << right.imag << ")";
	return left;
}


class point {
private:
	int x, y;
public:
	point(int in_x, int in_y);
	void set_x(int in_x);
	int get_x() const;
	void set_y(int in_y);
	int get_y() const;
	friend ostream& operator<<(ostream& left, const point& right);
};



class board {
private:
	int N;
	char** p;
public:
	board(int in_N);
	board(const board& obj);
	~board();
	board& operator= (const board& obj);
	char get_elem(int i, int j) const;
	friend ostream& operator<<(ostream& left, const board& right);
	void insert_point(point& obj);
	void print();
	void clear();
};

point::point(int in_x, int in_y) {
	if (in_x < 0 || in_x>59) {
		cout << "Lathos timh tou x" << endl;
		x = 0;
	}
	else {
		x = in_x;
	}
	if (in_y < 0 || in_y>59) {
		cout << "Lathos timh tou y" << endl;
		y = 0;
	}
	else {
		y = in_y;
	}
}

void point::set_x(int in_x) {
	x = in_x;
}

int point::get_x() const {
	return x;
}

void point::set_y(int in_y) {
	y = in_y;
}

int point::get_y() const {
	return y;
}

ostream& operator<<(ostream& left, const point& right) {
	left << "(" << right.x << ", " << right.y << ")";
	return left;
}

board::board(int in_N) {
	N = in_N;
	p = new char* [N];
	if (!p) {
		cout << "Error Allocating Memory";
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		p[i] = new char[N];
		if (!p[i]) {
			cout << "Error Allocating Memory";
			exit(0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			p[i][j] = '.';
		}
	}
}

board::~board() {
	for (int i = 0; i < N; i++) {
		delete[] p[i];
	}
	delete[] p;
}

board::board(const board& obj) {
	N = obj.N;
	p = new char* [N];
	if (!p) {
		cout << "Error Allocating Memory";
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		p[i] = new char[N];
		if (!p[i]) {
			cout << "Error Allocating Memory";
			exit(0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			p[i][j] = obj.p[i][j];
		}
	}
}

board& board::operator=(const board& obj) {
	if (p != NULL) {
		for (int i = 0; i < N; i++) {
			delete[] p[i];
		}
		delete[] p;
	}
	N = obj.N;
	p = new char* [N];
	if (!p) {
		cout << "Error Allocating Memory";
		exit(0);
	}
	for (int i = 0; i < N; i++) {
		p[i] = new char[N];
		if (!p[i]) {
			cout << "Error Allocating Memory";
			exit(0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			p[i][j] = obj.p[i][j];
		}
	}
}

char board::get_elem(int i, int j) const {
	return p[i][j];
}

ostream& operator<<(ostream& left, const board& right) {
	for (int i = 0; i<right.N; i++) {
		for (int j = 0; j < right.N; j++) {
			left << right.p[i][j] << " ";
		}
		left << endl;
	}
	return left;
}

void board::insert_point(point& obj) {
	if (obj.get_x() >= 0 && obj.get_x() < N && obj.get_y() >= 0 && obj.get_y() < N) {
		p[obj.get_x()][obj.get_y()] = 'O';
	}

}

void board::print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<<p[i][j]<<" ";
		}
		cout << endl;
	}
}

void board::clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p[i][j] != '.') {
				p[i][j] = '.';
			}
		}
	}
}

int main() {

	board b(30);
	point temp_point(0, 0);
	int choice;
	int x, y;
	while (true) {
		cout << "MENU" << endl;
		cout << "1) Na eisagei ena kainourio shmeio" << endl;
		cout << "2) Na ektupwsei to plaisio" << endl;
		cout << "3) Na katharisei to plasio" << endl;
		cout << "4) Na ginei ejodos apo to programma" << endl;
		cout << ">";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Dwse x, y: ";
			cin >> x >> y;
			temp_point.set_x(x);
			temp_point.set_y(y);
			b.insert_point(temp_point);
			break;
		case 2:
			cout << endl << b; //diaforetika the borousa b.print() mias kai thn exw ulopoihsei kai authn
			break;
		case 3:
			b.clear();
			break;
		case 4:
			cout << "Bye Bye!!!";
			exit(0);
		default:
			cout << "Lathos EISODOS...";
		}
	}
}

