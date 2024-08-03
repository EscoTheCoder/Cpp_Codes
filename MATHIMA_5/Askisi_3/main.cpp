#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


class demigorgon{
private:
    int height;
    int weight;
    int health;

public:
    demigorgon(){
        height=5;
        health=1000;
        weight=500;
    }
    int attack(){

        //srand(time(0));
        return 300+rand()%201; // arxh+rand()%(telos-arxh+1)
    }
};

class demidog{
private:
    int health;
public:
    demidog(){
        health=100;
    }
    int attack(){
        //srand(time(0));
        return 10+rand()%21; // arxh+rand()%(telos-arxh+1)
    }
};

class hive{
public:
    hive(bool in_demigorgon){
        if(in_demigorgon){
            demi_ptr=new demigorgon;
            if(!demi_ptr){
                cout<<"Error allocating memory";
            }
        }
        else{
            demi_ptr=NULL;
        }

        srand(time(0));
        n_demidogs=10+rand()%41;
        array_demidogs = new demidog [n_demidogs];
        if(!array_demidogs) {
            cout<<"Error allocating memory";
        }
    }
    int attack(){
        int damage;
        int sum=0;
        if(demi_ptr!=NULL){
            damage=demi_ptr->attack();
            sum+=damage;
            cout<<"Demigorgon attacks! (damage: "<<damage<<")"<<endl;
        }
        for(int i=0; i<n_demidogs; i++){
            damage=array_demidogs[i].attack();
            sum+=damage;
            cout<<"Demidog "<<i<<" attacks! (damage: "<<damage<<")"<<endl;
        }
        return sum;
    }

private:
    demigorgon *demi_ptr;
    demidog *array_demidogs;
    int n_demidogs; // plithos apo demidogs
};

int main() {

    hive h(true);
    int damage;

    damage=h.attack();
    cout<<"Total damage: "<<damage;


    return 0;
}
