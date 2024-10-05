#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>
#include <climits>
#include "test.hpp"
#define ll long long
#define N 10
#define FOR(a,b) for(int i=a; i<b; i++)
#define MAX(x,y) ((x)>(y) ? cout<<(x) : cout<<(y))
using namespace std;



class vec2 {
private:
	vector<int> v;
public:
	vec2() {
	}

	vec2(vector<int> v) { 
		this->v = v;
	}

	void print() const {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ", ";
		}
	}
	vec2 operator+(const vec2& p) const;
	friend ostream& operator<< (ostream& left, vec2& right);
};


vec2 vec2::operator+(const vec2& p) const {
	vec2 w;
	w.v.resize(v.size());  // Ensure w.v is properly resized

	for (int i = 0; i < v.size(); i++) {
		if (i < p.v.size()) {
			w.v[i] = p.v[i] + v[i];
		}
		else {
			w.v[i] = v[i]; // Handle if `p.v` has fewer elements
		}
	}
	return w;
}

ostream& operator<< (ostream& left, vec2& right) {
	for (int i = 0; i < right.v.size(); i++) {
		left << right.v[i] << ", ";
	}
	return left;
}





class Array {
private:
	float* buffer;
	int size;

public:
	Array(int items) {
		size = items; 
		buffer = new float[items];
	}
	Array() : size(0), buffer(nullptr) {}

	Array(const Array& obj) {
		if (buffer != nullptr)
			delete[] buffer;
		size = obj.size;
		buffer = new float[size];
		if (!buffer) {
			cout << "Error allocating memory!";
		}
	}

	~Array() {
		if (buffer) delete[] buffer;
	}
	float& operator[](int index) {
		if (index >= 0 && index < size) {
			return buffer[index];
		}
		else {
			cerr << "Index Error";
		}
	}

	Array& operator =(const Array& obj) {
		if (&obj == this) {
			return *this;
		}
		if (buffer != nullptr) {
			delete[] buffer;
		}

		size = obj.size;
		buffer = new float[size];
		memcpy(buffer, obj.buffer, size * sizeof(float));
		return *this;
	}
};



class Point {
private:
	int x, y;
public:
	void setX(int newX) { x = newX; }
	void setY(int newY) { y = newY; }
	int getX() const { return x; }
	int getY() const { return y; }
	void display() const { cout << "x: " << x << ", y: " << y << endl; }
	Point(int newX = 0, int newY = 0) : x(newX), y(newY) {}
	Point(const Point& original) : x(original.x), y(original.y) {}
};


class LabeledPoint : public Point {
	string label; // Πρόσθετη μεταβλητή-μέλος.
public: // Νέες μέθοδοι:
	void display() const;
	void setLabel(const string& newLabel) { label = newLabel; }
	string getLabel() const { return label; }
	LabeledPoint(int newX = 0, int newY = 0, const string& newLabel = "label");
};

LabeledPoint::LabeledPoint(int newX, int newY, const string& newLabel) : 
	Point(newX, newY), label(newLabel) {
}

void LabeledPoint::display() const {
	cout << "label: " << label << ", ";
	Point::display();
}


class Line {
	Point start, end;
	string label;
public:
	Line(int x1, int y1, int x2, int y2, const string& s) :
		start(x1, y1), end(x2, y2), label(s) {
	}
	void display() const {
		cout << label << endl; start.display(); end.display();
	}
};


class A
{
protected:
	char* buffer;
	int size;
public:
	int get_size() {
		return size;
	}
	
	A(const int size)
		: size(size) {
		buffer = new char[size];
	}
	A(const A& src)
		: size(src.size) {
		buffer = new char[size];
	}
	~A() { delete[] buffer; }
};


class B : public A
{
	char fill_char;
public:
	int get_size() {
		return size;
	}
	B(const int size, const char fill)
		: A(size), fill_char(fill) {
	}
	B(const B& src) : 
		fill_char(src.fill_char),A(src) {
	}
	~B() {}
};


class Person {
	string name;
public:
	Person(const string& nameIn) : name(nameIn) {}
	virtual void print() const { 
		cout << name << endl;
	}
};


class Student : public Person {
	string code;
public:
	Student(const string& nameIn, const string& codeIn) :
		Person(nameIn), code(codeIn) {}
	virtual void print() const {
		Person::print(); cout << code << endl; 
	}
};


int main() {
	Person p("Nikos"); 
	p.print(); // Τυπώνει «Νίκος».

	Student s("Giwrgos", "p30100"); 
	s.print(); // Τυπώνει «Γιώργοςp30100».
	Student* p_student = &s; // Δείκτης Student*
	Person* p_person = &s; // Δείκτης Person* που δείχνει σε ένα Student (το s). Επιτρέπεται γιατί η Student είναι παράγωγη της Person.

	p_person->print(); // Τυπώνει «Γιώργος». Χρησιμοποιεί την print της Person, παρ' όλο που ο δείκτης δείχνει σε αντικείμενο Student.
}