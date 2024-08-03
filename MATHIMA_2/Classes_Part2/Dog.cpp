#include "Dog.h"
#include <iostream>
using namespace std;


void Dog::init(int in_mood){
    mood=in_mood;
}

void Dog::bark(){
    cout<<"Woof"<<endl;
}
void Dog::report_mood(){
    if(mood>10) {
        cout << "I am cool";
    }
    else{
        cout<<"I am furious";
    }
}