#include <iostream>
using namespace std;

int main() {


    int n;
    cout<<"Dwse length tou pinaka:";
    cin>>n;
    int *arr;

    //desmeush mnhmhs
    arr = new int [n];
    if(!arr) {
        cout << "Error allocating memory";
    }

    //kapoia douleia ston pinaka
    for(int i=0; i<n; i++){
        arr[i]=i*i;
    }

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    //apodesmeush mnhmhs
    delete [] arr;

    return 0;
}
