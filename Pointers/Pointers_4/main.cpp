#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    public:
        Vehicle(string color, int doors, int wheels);
        string getColor() const;
        void setColor(string color);
        int getDoors() const;
        void setDoors(int doors);
        int getWheels() const;
        void setWheels(int wheels);
        virtual void tax()=0;
    private:
        string color;
        int doors;
        int wheels;
};

Vehicle::Vehicle(string color, int doors, int wheels) :
    color(color), doors(doors), wheels(wheels) {
}

string Vehicle::getColor() const {
    return color;
}

void Vehicle::setColor(string color) {
    Vehicle::color = color;
}

int Vehicle::getDoors() const {
    return doors;
}

void Vehicle::setDoors(int doors) {
    Vehicle::doors = doors;
}

int Vehicle::getWheels() const {
    return wheels;
}

void Vehicle::setWheels(int wheels) {
    Vehicle::wheels = wheels;
}

class Car : public Vehicle{
public:
    Car(string color, int doors, int wheels);
    void tax();
};

Car::Car(string color, int doors, int wheels) :
    Vehicle(color, doors, wheels) {
}

void Car::tax() {
    cout<<"You have to pay A LOT OF TAX to get me"<<endl;
}

class Moto : public Vehicle{
public:
    Moto(string color, int doors, int wheels);
    void tax();
};

Moto::Moto(string color, int doors, int wheels) :
        Vehicle(color, doors, wheels) {
}

void Moto::tax() {
    cout<<"You have to pay LESS TAX to get me"<<endl;
}

int main() {

    Vehicle *list[4] = {new Car("black",4,4),
                        new Car("white",2,4),
                        new  Moto("white",0,2),
                        new Moto("purple",0,2)};


    for(auto i: list) {
        i->tax();
    }

    for(auto i: list) {
        delete i;
    }

    return 0;
}
