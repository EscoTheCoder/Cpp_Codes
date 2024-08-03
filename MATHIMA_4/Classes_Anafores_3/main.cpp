#include <iostream>
using namespace std;

class dummy{
public:
    dummy(){
        cout<<"Constructing..."<<endl;
        x=0;
    }

    dummy(const dummy &obj){
        cout<<"Copy constructor..."<<endl;
        x=obj.x;
    }

    ~dummy(){
        cout<<"Destructing..."<<endl;
    }
    int x;
};

void f(dummy obj){
    cout<<"In function..."<<endl;

}

int main() {
    dummy d;

    cout<<"Main Before calling f"<<endl;
    f(d);
    cout<<"Main After calling f"<<endl;

    return 0;
}
