#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;



int main(){

    srand(time(NULL));

    int array[5];
    for(int i=0; i<5; i++)
        array[i]=rand()%6;


    int *ptr_array[5];
    for(int i=0; i<5; i++)
        ptr_array[i]=&array[i];

    for(int i=0; i<5; i++)
        cout<<*ptr_array[i]<<" : "<<&ptr_array[i]<<endl;


}
