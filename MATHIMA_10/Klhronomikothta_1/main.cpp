#include <iostream>
#include <string>
using namespace std;


//class ANIMAL
class animal{
public:
    int getWeight() const;
    void setWeight(int weight);
    int getHeight() const;
    void setHeight(int height);

private:
    int weight;
    int height;
public:
};

int animal::getWeight() const {
    return weight;
}

void animal::setWeight(int weight) {
    this->weight = weight;
}

int animal::getHeight() const {
    return height;
}

void animal::setHeight(int height) {
    this->height = height;
}


//class DOG
class dog : public animal{
private:
    string house_address;
public:
    void bark();
    string getHouseAddress() const;
    void setHouseAddress(const string &houseAddress);
    friend ostream &operator<< (ostream &left, const dog &right);
};

void dog::bark() {
    cout<<"....Woof Woof...."<<endl;
}

string dog::getHouseAddress() const {
    return house_address;
}

void dog::setHouseAddress(const string &houseAddress) {
    house_address = houseAddress;
}

ostream &operator<< (ostream &left, const dog &right){
    left<<"weight: "<<right.getHeight()<<endl;
    left<<"height: "<<right.getHeight()<<endl;
    left<<"address: "<<right.getHouseAddress()<<endl;
    return left;
}

int main() {

    dog piko;

    piko.setHouseAddress("Left Hill 154");
    piko.setWeight(10);
    piko.setHeight(35);

    piko.bark();
    cout<<piko;

    return 0;
}
