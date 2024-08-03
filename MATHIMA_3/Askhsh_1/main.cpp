#include <iostream>
using namespace std;

int main() {

    int x=5;
    cout<<x<<" "<<&x<<endl;

    int *p;
    p=&x;
    cout<<p<<" "<<&p<<endl;
    cout<<*p<<endl;

    int **pp;
    pp=&p;
    cout<<pp<<" "<<&pp<<endl;
    cout<<**pp<<endl;
    cout<<*pp<<endl;



    return 0;
}
