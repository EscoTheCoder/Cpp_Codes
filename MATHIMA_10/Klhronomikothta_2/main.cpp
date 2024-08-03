#include <iostream>
using namespace std;

class B{
public:
    int pub;
    void f();
protected:
    int pro;
private:
    int pri;
};

class D:public B{
public:
    void g();
};

void B::f() {
    pub=1;
    pro=1;
    pri=1;
}

void D::g() {
    pub=1;
    pro=1;
    //pri=1;  no access
}


int main() {

    B b;
    b.pub=1;
    //b.pro=1;  no access
    //b.pri=1;  no access

    D d;
    d.pub=1;
    //d.pro=1;  no access
    //d.pri=1;  no access
    return 0;
}
