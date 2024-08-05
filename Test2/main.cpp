#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle(int doors, int wheels);
    virtual ~Vehicle();
    virtual void print();
protected:
    int doors;
    int wheels;
};

Vehicle::Vehicle(int doors, int wheels) {
    cout<<"Constructing Vehicle";
    this->doors=doors;
    this->wheels=wheels;
}

Vehicle::~Vehicle() {
    cout<<"Destructing Vehicle";
}

void Vehicle::print() {
    cout<<"This is a Car with doors and wheels";
}



class Car : public Vehicle{
    Car(int doors, int wheels);
    virtual ~Car();
    void print() const;
};

Car::Car(int doors, int wheels):Vehicle(doors,wheels) {
    cout<<"Constructing Car";
}

Car::~Car() {
    cout<<"Destructing Car";
}

void Car::print() const {
    cout<<"This is a Car with "<<doors<<" doors"<<" and "<<wheels<<" wheels";
}

class BMW : public Vehicle{
    BMW(int doors, int wheels);
    virtual ~BMW();
    void print() const;
};

BMW::BMW(int doors, int wheels):Vehicle(doors,wheels) {
    cout<<"Constructing BMW";
}

BMW::~BMW() {
    cout<<"Destructing BMW";
}

void BMW::print() const {
    cout<<"This is a BMW with "<<doors<<" doors"<<" and "<<wheels<<" wheels";
}

int main() {

    Vehicle *array[3];
    array[0]=new Car(4,4);
    array[1]=new BMW(2,4);
    array[2]=new Vehicle(0,0);

    for(int i=0; i<3; i++){
        array[i]->print();
    }

    for(int i=0; i<3; i++){
        delete array[i];
    }

    return 0;
}
