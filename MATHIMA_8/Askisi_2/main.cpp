#include <iostream>
using namespace std;

int Fibonacci(int n){
    static int pl=0;
    pl++;
    cout<<"pl="<<pl<<endl;
    if(n==1 || n==2){
        return 1;
    }
    else{
        return Fibonacci(n-1)+ Fibonacci(n-2);
    }
}

int main() {
    cout<<Fibonacci(17);


    return 0;
}
