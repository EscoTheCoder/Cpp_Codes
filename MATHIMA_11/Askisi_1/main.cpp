#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

class pool{
public:
    pool();
    virtual ~pool();
    card *pick_random_card();
private:
    card *cards[300];
    int n_cards;

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

pool::pool() {

    cards[0]=new creature("Akroan Crusader", "red", "common",1,1,"Human Soldier");
    cards[1]=new creature("Rune-Scarred Demon", "black", "rare",6,6,"Demon");
    cards[2]=new land("Plains", "white", "uncommon", 1, "Basic Land - Plains", false);
    cards[3]=new land("Swamp", "black", "uncommon", 1, "Basic Land - Swamp", false);
    cards[4]=new creature("Aegis Angel", "white", "rare",5,5,"Angel");
    cards[5]=new creature("Angler Turtle", "blue", "rare",5,7,"Turtle");
    cards[6]=new creature("Harbinger of Life", "black", "common",2,3,"Summon Spirit");
    cards[7]=new creature("Ghalta, Primal Hunger", "green", "rare",12,12,"Elder Dinosaur");
    cards[8]=new creature("Skarrgan Hellkite", "red", "rare",4,4,"Dragon");
    cards[9]=new creature("Spawn of Mayhem", "black", "rare",4,4,"Demon");

    n_cards=10;
}

pool::~pool() {
    for(int i=0; i<n_cards; i++){
        delete cards[i];
    }
}

card *pool::pick_random_card() {


    int k = 0+rand()%n_cards;
    return cards[k];
}

int main() {

    srand(time(0));

    pool p;


    return 0;
}
