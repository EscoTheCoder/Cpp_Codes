#include <iostream>
using namespace std;

//class ANIMAL
class animal{
public:
    animal(int in_weight, int in_height);
    virtual ~animal();
    int getWeight() const;
    void setWeight(int weight);
    int getHeight() const;
    void setHeight(int height);
    virtual void make_sound()=0;
protected:
    int weight;
    int height;
public:
};

animal::animal(int weight, int height) : weight(weight), height(height) {
}

animal::~animal() {
    cout<<"Destructing Animal"<<endl;
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

//void animal::make_sound() {      // den xreiazetai giati egine pure virtual (amigws eikonikh)-> virtual void make_sound()=0;
//    cout<<"Animal Sound"<<endl;
//}


//class DOG
class dog : public animal{
private:
    string house_address;
public:
    dog(int inWeight, int inHeight, string in_house_address);
    ~dog(); //einai virtual logo tis Animal
    void bark();
    string getHouseAddress() const;
    void setHouseAddress(const string &houseAddress);
    friend ostream &operator<< (ostream &left, const dog &right);
    void make_sound(); //einai virtual logo tis Animal
};

dog::dog(int inWeight, int inHeight,  string houseAddress) : animal(inWeight, inHeight),house_address(houseAddress) {
}

dog::~dog() {
    cout<<"Destructing Dog"<<endl;
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

void dog::make_sound() {
    cout<<"Woof Woof"<<endl;
}


//Class Cat
class cat : public animal{
public:
    cat(int in_weight, int in_height);
    ~cat(); //einai virtual logo tis Animal
    int getWeight() const;
    void setWeight(int weight);
    int getHeight() const;
    void setHeight(int height);
    void make_sound(); //einai virtual logo tis Animal
private:
    int weight;
    int height;
public:
};

cat::cat(int in_weight, int in_height) : animal(in_weight, in_height)
{
}

cat::~cat() {
    cout<<"Destructing Cat"<<endl;
}

int cat::getWeight() const {
    return weight;
}

void cat::setWeight(int weight) {
    this->weight = weight;
}

int cat::getHeight() const {
    return height;
}

void cat::setHeight(int height) {
    this->height = height;
}

void cat::make_sound() {
    cout<<"Meow"<<endl;
}

int main() {

//    dog *dp=new dog(10,35,"Left Hill 154");
//    delete dp;

    //animal aa(10,12); // den mporw logo pure virtual method -> (abstract class)
    animal *ap=new dog(10,35,"Left Hill 154");
    delete ap;

    return 0;
}
