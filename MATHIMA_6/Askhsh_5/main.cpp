#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Wizzard{
private:
    int age;
    char mousi[80];
    int mageia;
    int health;
public:
    Wizzard(int age, char *mousi, int mageia, int health);
    int getMageia() const;
    void setMageia(int mageia);
    void wait();
    int fire_ball_spell();
    int lighting_spell();
    Wizzard &operator+= (int add_health);
    Wizzard &operator-= (int sub_health);
};


Wizzard::Wizzard(int age, char *mousi, int mageia, int health){
    this->age=age;
    strcpy(this->mousi,mousi);
    this->mageia=mageia;
    this->health=health;
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
int Wizzard::fire_ball_spell(){
    if(mageia>=90) {
        mageia -= 90;
        cout << "FireBall Spell " << "Metrhths Mageias= " << mageia << endl;
        return 50+rand()%21;
    }
    else{
        cout<<"Den exei arketo metrhth mageias gia na kanei FireBall Spell"<<endl;
        return 0;
    }
}
int Wizzard::lighting_spell() {
    if (mageia >= 30) {
        mageia -= 30;
        cout << "Lighting Spell " << "Metrhths Mageias= " << mageia << endl;
        return 10+rand()%11;
    } else {
        cout << "Den exei arketo metrhth mageias gia na kanei Lighting Spell" << endl;
        return 0;
    }
}

Wizzard &Wizzard::operator+= (int add_health){
    health+=add_health;
    if(health>100){
        health=100;
    }
    return *this;
}

Wizzard &Wizzard::operator-= (int sub_health){
    health-=sub_health;
    if(health<=0){
        cout<<"Wizzard Dead\n";
    }
    return *this;
}

int main() {
    int age=2019;
    char mousi[80]="Nikolas";
    Wizzard gandalf(age,mousi,100,100);
    int damage;

    //arxikopoihsh pragmatwn gia na xrhsimopoihsw thn random
    srand(time(0));

    //senario tou paixnidiou
    //gandalf-=100;
    damage=gandalf.lighting_spell();
    cout<<"Damage(lighting_spell)="<<damage<<endl;
    gandalf.wait();
    gandalf.fire_ball_spell();
    cout<<"Damage(fire_ball_spell)="<<damage<<endl;
    gandalf.wait();
    gandalf.wait();
    gandalf.lighting_spell();
    cout<<"Damage(lighting_spell)="<<damage<<endl;
    return 0;
}
