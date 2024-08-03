#include <iostream>
#include <string>
using namespace std;

template <typename T>
void print_number(T* ptr){
    cout<<*ptr<<endl;
}

void print(void *ptr, char type){

    switch (type) {
        case 'i':
            cout<<*((int* )ptr)<<endl;
            break;
        case 'c':
            cout<<*((char *)ptr)<<endl;
            break;
        case 's':
            cout<<*((string*)ptr)<<endl;
            break;
        case 'f':
            cout<<*((float *)ptr)<<endl;
            break;
        case 'd':
            cout<<*((double *)ptr)<<endl;
            break;
    }
}

int main() {

    int number=5;
    char letter='a';

    //lush me template <typename T> (generics)
    print_number<>(&number);
    print_number(&letter);

    //lush me void pointer
    print(&letter,'i');
    print(&letter,'c');


    return 0;
}
