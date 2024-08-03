#include <iostream>
#include <string>
using namespace std;

class card{
public:
    card(string name, string color, string rarity);
    friend ostream &operator<< (ostream &left, const card &right);
protected:
    string color;
    string rarity; //spaniothta = (common,uncommon,rare)
    string name;
};

class creature : public card{
public:
    creature(string name, string color, string rarity, int attack, int defense, string kind);
    friend ostream &operator<< (ostream &left, const creature &right);
private:
    int attack;
    int defense;
    string kind; //eidos

};

class land : public card{
public:
    land(string name, string color, string rarity,int mana, string description,bool tap);
    friend ostream &operator<< (ostream &left, const land &right);
private:
    int mana;
    string description;
    bool tap;
};

card::card(string name, string color, string rarity){
    this->name=name;
    this->color=color;
    this->rarity=rarity;
}

ostream &operator<< (ostream &left, const card &right){

    left<<"("<<right.name<<", "<<right.color<<", "<<right.rarity<<")"<<endl;
    return left;
}

creature::creature(string name, string color, string rarity, int attack, int defense, string kind):
    card(name,color,rarity)
    {
    this->attack=attack;
    this->defense=defense;
    this->kind=kind;
}

ostream &operator<< (ostream &left, const creature &right){

    left<<"("<<right.name<<", "<<right.color<<", "<<right.rarity<<", "<<right.attack<<", "<<right.defense<<", "<<right.kind<<")"<<endl;
    return left;
}

land::land(string name, string color, string rarity,int mana, string description,bool tap)
        : card(name, color, rarity){
    this->mana=mana;
    this->description=description;
    this->tap=tap;
}

ostream &operator<< (ostream &left, const land &right){
    left<<"("<<right.name<<", "<<right.color<<", "<<right.rarity<<", "<<right.mana<<", "<<right.description<<", ";
    if(right.tap)
        left<<"tapped";
    else{
        left<<"untapped";
    }
    left<<")"<<endl;
    return left;
}

int main() {

    creature c("Akroan Crusader", "Red", "Common", 1, 1, "Human Soldier");
    cout<<c;

    creature c2("Rune-Scarred Demon", "Green", "Rare", 6, 6, "Demon");
    cout<<c2;

    land l("Plains","white","uncommon",1,"Basic Land - Plains", false);
    cout<<l;


    return 0;
}
