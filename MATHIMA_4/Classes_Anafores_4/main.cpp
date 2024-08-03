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

dummy f(){
    dummy obj;
    cout<<"In function..."<<endl;
    return obj;
}

int main() {
//    cout<<"Main Before calling f"<<endl;
//    f();
//    cout<<"Main After calling f"<<endl;

    dummy obj1;
    dummy obj2=obj1; //alliws mporw na to grapsw kai etsi dummy obj2(obj1) kaleitai o copy constractor;


    return 0;
}
