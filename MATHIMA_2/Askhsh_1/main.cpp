#include <iostream>
using namespace std;

class Dummy{

private:
    int x;

public:
    Dummy(int x){
        this->x=x;
    }

    Dummy(){
        x=0;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    virtual ~Dummy() {
        cout<<"Katastrefetai to antikeimeno me thn timh x="<<getX()<<endl;
    }
};


int main() {

    Dummy dummy1(10);
    Dummy dummy2;

    return 0;
}
