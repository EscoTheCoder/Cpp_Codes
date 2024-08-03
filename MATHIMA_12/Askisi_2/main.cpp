#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class person{
public:
    person();
    person(string name, double salary);
private:
    string name;
    double salary;
};

class barista : virtual public person{
public:
    barista();
    barista(string name, double salary);
    void prepare();
private:
};

class waiter : virtual public person{
public:
    waiter();
    waiter(string name, double salary);
    void serve(int customers, barista &b);
    void print();
private:
    int customers_served;
};

class owner : public barista, public waiter{
public:
    owner(string name, double salary);
private:

};



person::person() {
}

person::person(string name, double salary) :
        name(name), salary(salary) {
}

waiter::waiter() {
    customers_served=0;
}

waiter::waiter(string name, double salary) :
    person(name, salary) {
    customers_served=0;
}

void waiter::serve(int customers, barista &b) {
    b.prepare();
    customers_served+=customers;
}

void waiter::print() {
    cout<<customers_served<<endl;
}

barista::barista() {
}

barista::barista(string name, double salary) :
    person(name, salary) {
}

void barista::prepare() {
    //cout<<........
}

owner::owner(string name, double salary):
    person(name, salary) {
    }


int main() {

    srand(time(NULL));

    int clients , waiter_to_serve , barista_to_serve;
    owner *o = new owner("Joe",500);
    waiter *w1 = new waiter("Jack",700);
    waiter *w2 = new waiter("Suzy",1000);
    barista *b = new barista("Bob",400);

    waiter *waiters[3]={o,w1,w2};
    barista *baristas[2]={o,b};

    for(int i=0; i<100; i++){
        clients=1+rand()%5;
        waiter_to_serve=rand()%3; //(0 h 1 h 2)
        barista_to_serve=rand()%2;

        waiters[waiter_to_serve]->serve(clients,*baristas[barista_to_serve]);
    }

    for(int i=0; i<3; i++){
        waiters[i]->print();
    }


    delete o;
    delete w1;
    delete w2;
    delete b;


    return 0;
}
