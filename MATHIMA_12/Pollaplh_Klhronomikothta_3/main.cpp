#include <iostream>
#include <string>
using namespace std;

//TO PROVLHMA
//TOU DIAMANTIOU



class person{
public:
    person(string name);

protected:
    string name;
};

class king : public person{
public:
    king(string name, string realm);
    ~king();
    void rule();
    void setRealm(string realm);

protected:
    string realm;
};

class philosopher : public person{
public:
    philosopher(string name, string philosophy);
    ~philosopher();
    void setPhilosophy(string philosophy);
    void think();
protected:
    string philosophy;
};

class phil_king : public king, public philosopher{
public:
    phil_king(string name, string realm, string philosophy);
    ~phil_king();
    void routine();
    friend ostream &operator<< (ostream &left, phil_king &right);
};



king::king(string name, string realm) :
    person(name)
    {
    this->realm=realm;
    cout<<"Constructing King"<<endl;
}

king::~king() {
    cout<<"Destructing King"<<endl;
}

void king::setRealm(string realm) {
    this->realm = realm;
}

void king::rule() {
    cout<<"Now, I rule"<<endl;
}

philosopher::philosopher(string name, string philosophy) :
    person(name){
    this->philosophy=philosophy;
    cout<<"Constructing Philosopher"<<endl;
}

philosopher::~philosopher() {
    cout<<"Destructing Philosopher"<<endl;
}

void philosopher::setPhilosophy(string philosophy) {
    this->philosophy = philosophy;
}

void philosopher::think() {
    cout<<"Now, I think"<<endl;
}

phil_king::phil_king(string name, string realm, string philosophy) :
    king(name,realm), philosopher(name,philosophy)
    {
    cout<<"Constructing Philosopher King"<<endl;
}

phil_king::~phil_king() {
    cout<<"Destructing Philosopher King"<<endl;
}

person::person(std::string name) {
    this->name=name;
}

void phil_king::routine() {
    think();
    rule();
    think();
}

ostream &operator<< (ostream &left, phil_king &right){
    left<<right.philosopher::name<<endl; //antimetopish provlhma tou diamantiou
    left<<"Rulling "<<right.realm<<endl;
    left<<"using "<<right.philosophy<<" philosophy"<<endl;
    return left;

}

int main() {

    phil_king the_King("Marcus Aurelius","Roman Empire","stoic");

    cout<<endl<<the_King<<endl;

    the_King.routine();

    return 0;
}
    