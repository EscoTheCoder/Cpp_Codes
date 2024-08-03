#include <iostream>
#include <string>
using namespace std;

int get_Min(int numbers[], int size){
    int min=numbers[0];
    for(int i=1; i<size; i++){
        if(numbers[i]<min){
            min=numbers[i];
        }
    }
    return min;
}

int get_Max(const int numbers[], int size){
    int max=numbers[0];
    for(int i=1; i<size; i++){
        if(numbers[i]>max){
            max=numbers[i];
        }
    }
    return max;
}

void get_Min_Max(const int *numbers, int size,int *min, int *max){
    for(int i=1; i<size; i++){
        if(numbers[i]<*min){
            *min=numbers[i];
        }
        if(numbers[i]>*max){
            *max=numbers[i];
        }
    }
}



int main() {

    //Me ton classic tropo
    int numbers[]={5,4,-2,29,6};
    cout<<"Min= "<<get_Min(numbers,5)<<endl;
    cout<<"Max= "<<get_Max(numbers,5)<<endl;


    //Return multiple values from a function using pointers
    int min=numbers[0];
    int max=numbers[0];
    get_Min_Max(numbers,5,&min,&max);

    cout<<"Min= "<<min<<endl;
    cout<<"Max= "<<max<<endl;

    return 0;
}
