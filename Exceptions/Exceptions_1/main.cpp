#include <iostream>
#include <string>
using namespace std;

template <typename T>
T divide(T x, T y){
    if(y==0){
        throw 0; //epilegoume tuxaio noumero
    }
    else {
        return x/y;
    }

}

int main() {

    double x;
    double y;

    cin>>x>>y;


    try {
        cout<<divide<double>(x,y)<<endl;
    }
    catch (int e){
        if(e==0){
            cout<<"Division by zero is undefined"<<endl;
        }
        else {
            cerr << "Error" << endl;
        }
    }
    cout<<"Final message..";

    return 0;
}
