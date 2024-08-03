#include <iostream>
#include <cstring>

using namespace std;

class table; //forward declaration

class chair{
private:
    char color[80];
    int height;
public:
    friend void shrink(chair &c, table &t);
    chair(char *in_color, int in_height);
    friend ostream &operator<<(ostream &left, const chair obj);
};


class table{
private:
    char color[80];
    int mhkos;
    int platos;
public:
    friend void shrink(chair &c, table &t);
    table(char *in_color, int in_mhkos, int in_platos);
    friend ostream &operator<<(ostream &left, const table obj);
};


void shrink(chair &c, table &t) {
    c.height=0.9*c.height;
    t.mhkos=0.9*t.mhkos;
    t.platos=0.9*t.platos;
}


chair::chair(char *in_color, int in_height) {
    strcpy(color,in_color);
    height=in_height;
}

ostream &operator<<(ostream &left, const chair obj){

    left<<"Chair: Color= "<<obj.color<<" Height= "<<obj.height;
    return left;
}


table::table(char *in_color, int in_mhkos, int in_platos) {
    strcpy(color,in_color);
    mhkos=in_mhkos;
    platos=in_platos;
}


ostream &operator<<(ostream &left, const table obj){

    left<<"Table: Color= "<<obj.color<<" Mhkos= "<<obj.mhkos<<" Platos= "<<obj.platos;
    return left;
}



int main() {

    chair c("Blue",150);
    table t("Brown",200,200);

    cout<<c<<endl<<t;

    shrink(c,t);

    cout<<endl<<endl<<"NEES DIASTASEIS:"<<endl;
    cout<<c<<endl<<t;


    return 0;
}
