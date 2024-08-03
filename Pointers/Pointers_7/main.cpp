#include <iostream>
using namespace std;

int main() {

    int rows,columns;
    cout<<"rows, columns";
    cin>>rows>>columns;

    int **table=new int *[rows];
    for(int i=0; i<rows; i++){
        table[i]=new int [columns];
    }
    table[1][2]=88;

    for(int i=0; i<rows; i++){
        delete [] table[i];
    }

    return 0;
}
