#include <iostream>
using namespace std;

int main() {

    int size;
    cout<<"Dwse size:";
    cin>>size;

    int *myArray = new int [size];
    if(!myArray){
        cout<<"Error allocating memory";
    }

    for(int i=0; i<size; i++){
        cout<<"Array["<<i<<"] :";
        cin>>myArray[i];
    }

    for(int i=0; i<size; i++){
        cout<<myArray[i]<<" ";
    }

    delete [] myArray



    return 0;
}
