#include <iostream>
#include <string>
using namespace std;

class king{
public:
    void rule();
    void setRealm(string realm);

private:
    string realm;
};

class philosopher{
public:
    void setPhilosophy(string philosophy);
    void think();
private:
    string philosophy;
};

class phil_king : public king, public philosopher{
public:
    void routine();
};


void king::setRealm(string realm) {
    this->realm = realm;
}

void king::rule() {
    cout<<"Now, I rule"<<endl;
}

void philosopher::setPhilosophy(string philosophy) {
    this->philosophy = philosophy;
}

void philosopher::think() {
    cout<<"Now, I think"<<endl;
}

void phil_king::routine() {
    think();
    rule();
    think();
}

int main() {

    phil_king marcus_aurelius;

    marcus_aurelius.setRealm("Roman Empire");
    marcus_aurelius.setPhilosophy("stoic");

    marcus_aurelius.routine();

    return 0;
}
