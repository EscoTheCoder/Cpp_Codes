#include <iostream>
#include <cstring>
#include "Wizzard.h"

using namespace std;


int main() {
    int age=2019;
    char mousi[80]="Nikolas";
    Wizzard gandalf(age,mousi);
    gandalf.fire_ball_spell();
    gandalf.wait();
    gandalf.lighting_spell();
    gandalf.wait();
    gandalf.wait();
    gandalf.fire_ball_spell();
    return 0;
}
