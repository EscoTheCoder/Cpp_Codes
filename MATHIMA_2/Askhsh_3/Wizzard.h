#include <iostream>
using namespace std;

class Wizzard{
private:
    int age;
    char mousi[80];
    int mageia;
public:
    Wizzard(int age, char *mousi);
    int getMageia() const;
    void setMageia(int mageia);
    void wait();
    void fire_ball_spell();
    void lighting_spell();

};