#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Cow{
    public:
        int weight;
        void setHunger(int hunger) {
            this->hunger = hunger;
        }
        void express(){
            if(hunger>10){
            cout<<"MmmmmmMMMmmM";
            }
        }
    private:
        int hunger;
};

class Dog{
public:
    void init(int in_mood){
        mood=in_mood;
    }

    void bark(){
        cout<<"Woof"<<endl;
    }
    void report_mood(){
        if(mood>10) {
            cout << "I am cool";
        }
        else{
            cout<<"I am furious";
        }
    }
private:
    int mood;
};

int main() {
//    Cow molly;
//    molly.weight=500;
//    molly.setHunger(49);
//    molly.express();
    Dog bruno;
    bruno.init(11);
    bruno.report_mood();

    return 0;
}
