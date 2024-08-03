#include <iostream>
using namespace std;

class life{
public:
    int x;
    life(int in_x);
    ~life();
};

life::life(int in_x) {
    x=in_x;
    cout<<"Constructing "<<x<<endl;
}

life::~life() {
    cout<<"Destructing "<<x<<endl;
}

int main() {

    static life obj(1);
    cout<<"Start Main"<<endl;
    //block sketous kwdika
    {
        life obj2(2);
    }

    life *obj3 = new life(3);
    delete obj3;
    cout<<"End Main"<<endl;

    return 0;
}
