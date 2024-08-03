#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int k=a;
    a=b;
    b=k;
}

void swap(double &a,double &b){
    double k=a;
    a=b;
    b=k;
}

int main() {
    double a,b;
    cout<<"Dwse arhithmo a,b:";
    cin>>a>>b;

    cout<<endl<<"a="<<a<<" b="<<b<<endl;
    swap(a,b);
    cout<<"a="<<a<<" b="<<b;

    return 0;
}
