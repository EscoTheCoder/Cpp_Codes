#include <iostream>
#include <string>
using namespace std;

class king{
public:
    king(string realm);
    ~king();
    void rule();
    void setRealm(string realm);

private:
    string realm;
};

class philosopher{
public:
    philosopher(string philosophy);
    ~philosopher();
    void setPhilosophy(string philosophy);
    void think();
private:
    string philosophy;
};

class phil_king : public king, public philosopher{
public:
    phil_king(string realm, string philosophy);
    ~phil_king();
    void routine();
};


king::king(std::string realm) {
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

philosopher::philosopher(std::string philosophy) {
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

phil_king::phil_king(std::string realm, std::string philosophy) :
    king(realm), philosopher(philosophy)
    {
    cout<<"Constructing Philosopher King"<<endl;
}

phil_king::~phil_king() {
    cout<<"Destructing Philosopher King"<<endl;
}

void phil_king::routine() {
    think();
    rule();
    think();
}

int main() {

    phil_king marcus_aurelius("Roman Empire","stoic");

    marcus_aurelius.routine();

    return 0;
}
