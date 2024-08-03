#include <iostream>
using namespace std;
#define N 5


class C{
    int y;
    public:
        int f();

};

//einai isodunamh me thn class C
//struct C{
//    int f();
//    private:
//        int y;
//};

class dummy{
private:
    int x;
public:
    dummy(int x){
        this->x=x;
    }
    int get_x() const{
        return x;
    }
    void set_x(int x){
        this->x=x;
    }
};

void f(const dummy *p){
    cout<<p->get_x();
    //p->set_x(2); //error
}

void f(const dummy &p){
    cout<<p.get_x();
    //p->set_x(2); //error
}


int main() {

//    const dummy obj(3);



    //deikths pros stathero antikeimeno
    //const dummy *ptr;
//    dummy ob(3);
//    f(&ob);

    //statheros deikths pros antikeimeno
    //dummy * const ptr;
    dummy ob(3);
    f(ob);

    //statheros deikths pros sthathero antikeimeno
    //const dummy *const ptr;

    return 0;
}
