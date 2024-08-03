#include <iostream>
using namespace std;

class Dog{
public:
    Dog(int mood) {
    this->mood=mood;
    }

    int getMood() const {
        return mood;
    }

    void setMood(int mood) {
        this->mood = mood;
    }



private:
    int mood;
};


int main() {
    Dog max(10);
    max.setMood(11);
    cout<<max.getMood();

    return 0;
}
