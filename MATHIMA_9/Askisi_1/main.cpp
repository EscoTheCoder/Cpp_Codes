#include <iostream>
#include <string>
#define N 5
using namespace std;

void swap(string &s1, string &s2){
    string k=s1;
    s1=s2;
    s2=k;
}

void insertion_sort(string *array){
    for(int i=0; i<N; i++){
        for(int j=i; j>=1; j--){
            if(array[j]<array[j-1]){
                swap(array[j],array[j-1]);
            }
        }
    }
}

void print(string *array){
    cout<<"[";
    for(int i=0; i<N-1; i++){
        cout<<array[i]<<", ";
    }
    cout<<array[N-1]<<"]"<<endl;
}

int main() {

    string array[N]={"abcd","adas","asdr","aqwe","qwetyy"};

    print(array);
    insertion_sort(array);
    print(array);

    return 0;
}
