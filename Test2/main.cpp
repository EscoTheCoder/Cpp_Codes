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
    cout<<"Constructing Vehicle"<<endl;
    this->doors=doors;
    this->wheels=wheels;
}

Vehicle::~Vehicle() {
    cout<<"Destructing Vehicle"<<endl;
}

void Vehicle::print() {
    cout<<"This is a Car with doors and wheels"<<endl;
}



class Car : public Vehicle{
public:
    Car(int doors, int wheels);
    virtual ~Car();
    void print();
};

Car::Car(int doors, int wheels):Vehicle(doors,wheels) {
    cout<<"Constructing Car"<<endl;
}

Car::~Car() {
    cout<<"Destructing Car"<<endl;
}

void Car::print(){
    cout<<"This is a Car with "<<doors<<" doors"<<" and "<<wheels<<" wheels"<<endl;
}

class BMW : public Vehicle{
public:
    BMW(int doors, int wheels);
    virtual ~BMW();
    void print();
};

BMW::BMW(int doors, int wheels):Vehicle(doors,wheels) {
    cout<<"Constructing BMW"<<endl;
}

BMW::~BMW() {
    cout<<"Destructing BMW"<<endl;
}

void BMW::print(){
    cout<<"This is a BMW with "<<doors<<" doors"<<" and "<<wheels<<" wheels"<<endl;
}

int main() {

    Vehicle *array[3];
    array[2]=new Vehicle(0,0);
    array[0]=new Car(4,4);
    array[1]=new BMW(2,4);

    for(int i=0; i<3; i++){
        array[i]->print();
    }

    for(int i=0; i<3; i++){
        delete array[i];
    }

    return 0;
}
