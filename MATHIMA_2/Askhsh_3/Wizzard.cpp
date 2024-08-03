#include "Wizzard.h"
#include <iostream>
#include <cstring>

using namespace std;

Wizzard::Wizzard(int age, char *mousi){
    this->age=age;
    strcpy(this->mousi,mousi);
    mageia=100;
}

int Wizzard::getMageia() const {
    return mageia;
}

void Wizzard::setMageia(int mageia) {
    this->mageia = mageia;
}
void Wizzard::wait(){
    mageia+=10;
    cout<<"Wait "<<"Metrhths Mageias= "<<mageia<<endl;
}
void Wizzard::fire_ball_spell(){
    if(mageia>=30) {
        mageia -= 30;
        cout << "FireBall Spell " << "Metrhths Mageias= " << mageia << endl;
    }
    else{
        cout<<"Den exei arketo metrhth mageias gia na kanei FireBall Spell"<<endl;
    }
}
void Wizzard::lighting_spell() {
    if (mageia >= 90) {
        mageia -= 90;
        cout << "Lighting Spell " << "Metrhths Mageias= " << mageia << endl;
    } else {
        cout << "Den exei arketo metrhth mageias gia na kanei Lighting Spell" << endl;
    }
}
