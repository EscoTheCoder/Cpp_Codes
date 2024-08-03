#include <iostream>
#include <string>
using namespace std;

//GIA NA ANTIMETOPISOUME TO PROVLHMA TOU DIAMANTIOU MESO VIRTUAL



class person{
public:
    person();
    person(string name);

protected:
    string name;
};

class king : virtual public person{
public:
    king(string realm);
    ~king();
    void rule();
    void setRealm(string realm);

protected:
    string realm;
};

class philosopher : virtual public person{
public:
    philosopher(string philosophy);
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



king::king(string realm){
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

philosopher::philosopher(string philosophy){
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
    person(name), king(realm), philosopher(philosophy)
    {
    cout<<"Constructing Philosopher King"<<endl;
}

phil_king::~phil_king() {
    cout<<"Destructing Philosopher King"<<endl;
}

person::person() {

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
    left<<right.name<<endl; //antimetopish provlhma tou diamantiou
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
