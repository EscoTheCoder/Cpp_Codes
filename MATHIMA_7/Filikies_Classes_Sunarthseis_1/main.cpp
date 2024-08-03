#include <iostream>
using namespace std;

class man{
public:
    friend class god;
    man(int in_sins);
    int get_sins();
private:
    int sins; //sins = amarties
};

man::man(int in_sins) {
    sins=in_sins;
}

int man::get_sins() {
    return sins;
}

class god{
public:
    void forgive(man &obj);
};

void god::forgive(man &obj) {
    obj.sins=0;
}


int main() {

    man Nikolas(100);
    god Xristos;

    cout<<"Sins="<<Nikolas.get_sins()<<endl;
    Xristos.forgive(Nikolas);
    cout<<"Sins="<<Nikolas.get_sins()<<endl;

    return 0;
}
