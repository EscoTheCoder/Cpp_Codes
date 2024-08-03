#include <iostream>
using namespace std;

class dummy{
public:
    dummy(int x){
        this->x=x;
        cout<<"Constructing..."<<endl;
    }
    ~dummy(){
        cout<<"Destructing..."<<endl;
    }
private:
    int x;
};


int main() {
//    dummy obj;
//    dummy *ptr=&obj;
//    //ptr=new dummy;
//    if(!ptr){
//        cout<<"Error allocating memory";
//    }
//    obj.x=6;
//    cout <<obj.x<<" "<<ptr->x<<" "<<(*ptr).x<<endl;
//    //delete ptr;

    dummy *ptr=NULL;
    ptr = new dummy(10); //Constructing

    if(!ptr){
        cout<<"Error allocating memory";
    }
    delete ptr; //Destructing

    return 0;
}
