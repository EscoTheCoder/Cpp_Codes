#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Dummy
{
public:
    Dummy(string name, int age);
    ~Dummy();
private:
    string name;
    int age;
};

Dummy::Dummy(string name, int age)
{
    cout << "Constructing..."<<endl;
    this->name = name;
    this->age = age;
}

Dummy::~Dummy()
{
    cout << "Destructing..."<<endl;
}



int main(){

    /*srand(time(NULL));

    int array[5];
    for(int i=0; i<5; i++)
        array[i]=rand()%6;


    int *ptr_array[5];
    for(int i=0; i<5; i++)
        ptr_array[i]=&array[i];

    for(int i=0; i<5; i++)
        cout<<*ptr_array[i]<<" : "<<&ptr_array[i]<<endl;*/
    Dummy s("nikolas", 19);
    Dummy s1("hlias", 20);


    return 0;
}


