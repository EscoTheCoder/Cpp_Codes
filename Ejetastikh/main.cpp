#include <iostream>
using namespace std;

class Table; //forward declaration

class Chair{
public:
    Chair(const string &color, int height);
    friend ostream &operator<<(ostream &left, const Chair right);
    friend void shrink(Chair &c, Table &t);
protected:
    string color;
    int height;
};

class Table : public Chair{
public:
    Table(const string &color, int height, int weight);
    friend ostream &operator<<(ostream &left, const Table right);
    friend void shrink(Chair &c, Table &t);
private:
    int weight;
};

Chair::Chair(const string &color, int height) :
    color(color), height(height){
}

ostream &operator<<(ostream &left, const Chair right){
    left<<"color="<<right.color<<", "<<"height="<<right.height<<endl;
    return left;
}

Table::Table(const string &color, int height, int weight) :
    Chair(color, height), weight(weight) {
}

ostream &operator<<(ostream &left, const Table right){
    left<<"color="<<right.color<<", "<<"height="<<right.height<<", "<<"weight="<<right.weight<<endl;
    return left;
}

void shrink(Chair &c, Table &t){
    c.height-=(c.height*0.1);
    t.weight-=(t.weight*0.1);
    t.height-=(t.height*0.1);
}


int main() {

    Chair c1("brown",10);
    Table t1("grey",20,50);

    cout<<c1<<t1<<endl;
    shrink(c1,t1);
    cout<<c1<<t1;

    return 0;
}
