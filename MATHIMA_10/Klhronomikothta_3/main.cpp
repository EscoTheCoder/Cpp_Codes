#include <iostream>
using namespace std;

//class ANIMAL
class animal{
public:
    animal(int in_weight, int in_height);
    ~animal();
    int getWeight() const;
    void setWeight(int weight);
    int getHeight() const;
    void setHeight(int height);

private:
    int weight;
    int height;
public:
};

animal::animal(int weight, int height) : weight(weight), height(height) {
    cout<<"Constructing Animal..."<<endl;
}

animal::~animal() {
    cout<<"Destructing Animal..."<<endl;
}

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
    dog(int inWeight, int inHeight, string in_house_address);
    ~dog();
    void bark();
    string getHouseAddress() const;
    void setHouseAddress(const string &houseAddress);
    friend ostream &operator<< (ostream &left, const dog &right);
};

dog::dog(int inWeight, int inHeight,  string houseAddress) : animal(inWeight, inHeight),house_address(houseAddress) {
    cout<<"Constructing Dog..."<<endl;
}

dog::~dog() {
    cout<<"Destructing Dog..."<<endl;
}

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

    dog piko(10,35,"Left Hill 154");
    piko.bark();
    cout<<piko;

    return 0;
}
