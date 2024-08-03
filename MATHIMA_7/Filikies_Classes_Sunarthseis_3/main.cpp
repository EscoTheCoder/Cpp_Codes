#include <iostream>
using namespace std;

class man{
public:
    friend void good_weather(man &obj);
    man(int in_mood);
    void report_mood() const;
private:
    int mood;
};

man::man(int in_mood) {
    mood=in_mood;
}

void man::report_mood() const {
    if(mood<10){
        cout<<"I am ok..."<<endl;
    }
    else{
        cout<<"I feel good!"<<endl;
    }
}

void good_weather(man &obj){
    obj.mood+=10;
}


int main() {

    man bob(5);

    bob.report_mood();
    good_weather(bob);
    bob.report_mood();

    return 0;
}
