#include <iostream>
#include <cstdlib>
using namespace std;
#define N 5

class orc{
public:
    static int allive_orcs;
    static bool frenzy_mode;
    static void toggle_frenzy_mode();
    orc();
    ~orc();
    friend ostream &operator<< (ostream &left, const orc &right);
private:
    int h;
};

int orc::allive_orcs=0;

bool orc::frenzy_mode=false;

void orc::toggle_frenzy_mode() {
    if(orc::frenzy_mode){
        orc::frenzy_mode=false;
    }
    else{
        orc::frenzy_mode=true;
    }
}

orc::orc() {
    allive_orcs++;
}

orc::~orc() {
    allive_orcs--;
}

ostream &operator<< (ostream &left, const orc &right){
    if(orc::frenzy_mode){
        left<<"AAARFFGHHHRRRAAAA";
    }
    else{
        left<<"ougaba";
    }
    return left;
}

int main(){

    orc orc1,orc2;

    cout<<"NORMAL MODE"<<endl;
    cout<<"Orc1: "<<orc1<<endl;
    cout<<"Orc2: "<<orc2<<endl;

    orc::toggle_frenzy_mode();

    cout<<endl<<"FRENZY MODE"<<endl;
    cout<<"Orc1: "<<orc1<<endl;
    cout<<"Orc2: "<<orc2<<endl;

    return 0;
}


