#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Humanoid{
private:
    int health;
public:
    Humanoid();
    Humanoid &operator-= (int sub_health);
    int get_health() const;
    int attack();
    bool check_dead();
};

Humanoid::Humanoid(){
    health=100;
}
Humanoid &Humanoid::operator-= (int sub_health){
    health-=sub_health;
    if(health<=0){
        cout<<"Humanoid Dead\n";
    }
    return *this;
}
int Humanoid::get_health() const{
    return health;
}
int Humanoid::attack(){
    return 1+rand()%5;
}
bool Humanoid::check_dead(){
    if(health<=0){
        return true;
    }
    return false;
}



class Wizzard : public Humanoid{
private:
    int age;
    string mousi;
    int mageia;
    int health;
public:
    Wizzard(int age, string mousi, int mageia, int health);
    int getMageia() const;
    void setMageia(int mageia);
    void wait();
    int fire_ball_spell();
    int lighting_spell();
    int attack();
    Wizzard &operator+= (int add_health);
    Wizzard &operator-= (int sub_health);
};


Wizzard::Wizzard(int age, string mousi, int mageia, int health){
    this->age=age;
    this->mousi=mousi;
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

int Wizzard::attack() {
    return 20+rand()%11;
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

    Wizzard gandalf(2019,"Nikolas",100,100);
    int damage;
    int r;
    Humanoid h;

    //arxikopoihsh pragmatwn gia na xrhsimopoihsw thn random
    srand(time(0));

    //senario tou paixnidiou
    r=1;
    while(true){
        cout<<"============================\n";
        cout<<"Round "<<r<<endl;

        //paizei o magos
        damage=gandalf.attack();
        h-=damage;

        if(rand()%2==0) { // elegxos gia 0 h 1 ean einai 1 lighting
            damage=gandalf.lighting_spell();
            h-=damage;
        }
        else{ // fireball
            damage=gandalf.fire_ball_spell();
            h-=damage;
        }

        //elegxos an to humanoid pethane
        if(h.check_dead()){
            cout<<"To humanoid ):";
            break;
        }

        //paizei to humanoid
        damage=h.attack();
        gandalf-=damage;

        //elegxos an o magos pethane
        if(gandalf.check_dead()){
            cout<<"O magos ):";
            break;
        }

        //ektupwsh health
        cout<<"Wizzard(health): "<<gandalf.get_health()<<endl;
        cout<<"Humanoid(health): "<<h.get_health()<<endl;

        //Aujish twn girwn
        gandalf.wait(); // gia na pernei mana o magos
        r++;

    }
    return 0;
}
