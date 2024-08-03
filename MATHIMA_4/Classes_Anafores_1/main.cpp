#include <iostream>
using namespace std;

int main() {

    int x=5;
    int &ref = x;  //&ref = sunwnumo

    cout<<"x="<<x<<" "<<"ref="<<ref<<endl;

    x=4;
    cout<<"x="<<x<<" "<<"ref="<<ref<<endl;

    ref=5;
    cout<<"x="<<x<<" "<<"ref="<<ref<<endl;

    return 0;
}
