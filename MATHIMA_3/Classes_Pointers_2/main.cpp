#include <iostream>
using namespace std;

int main() {
//    int x=5;
//    int *ptr=NULL;
//    ptr=&x;
//    cout<<"x="<<x<<" (address: "<<&x<<")"<<endl;
//    cout<<"*ptr="<<*ptr<<" (address: "<<ptr<<")"<<endl;
//    cout<<&x<<endl;

    int x;
    int *ptr;

    ptr= new int;
    if(!ptr){
        cout<<"ERROR ALLOCATING MEMORY";
    }
    x=1;
    *ptr=5;
    cout<<"x="<<x<<" (address: "<<&x<<")"<<endl;
    cout<<"*ptr="<<*ptr<<" (address: "<<ptr<<")"<<endl;

    delete ptr;


    return 0;
}
