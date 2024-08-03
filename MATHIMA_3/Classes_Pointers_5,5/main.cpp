#include <iostream>
using namespace std;

int main() {


    int n=4,m=4;
    int **arr;

    //desmeush mnhmhs
    arr = new int * [n];
    if(!arr){
        cout<<"Error allocating memory";
    }

    for(int i=0; i<n; i++){
        arr[i]=new int [m];
        if(!arr[i]){
            cout<<"Error allocating memory";
        }
    }

    //kapoia doulia ston pinakda

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j]=i*j;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }


    //apodesmeush mnhmhs
    for(int i=0; i<n; i++) {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
