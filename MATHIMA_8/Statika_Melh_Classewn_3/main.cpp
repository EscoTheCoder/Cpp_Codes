#include <iostream>
using namespace std;

void func(){
    int y=0;
    static int x=0; //h timh tou "x" paramenei kai me to telos ths sunarthseis

    x=x+1;
    y=y+1;
    cout<<endl<<"x="<<x<<", y="<<y;
}

int main() {

    for(int i=0; i<10; i++){
        func();
    }

    return 0;
}
