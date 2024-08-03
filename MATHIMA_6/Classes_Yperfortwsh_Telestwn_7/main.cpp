#include <iostream>
#include <vector>

using namespace std;

//YPERFORTWSH TELESTWN

//class migadikos
class ARRAY{
public:
    ARRAY(int in_n);
    ARRAY(const ARRAY &obj);
    ~ARRAY();
    int get_n() const;
    int &operator[] (int i);
    void print();
private:
    int *p;
    int n;
};

ARRAY::ARRAY(int n){
    this->n=n;
    p=new int [n];
    if(!p){
        cout<<"Error allocating memory!";
    }
}

void ARRAY::print(){
    for(int i=0; i<n; i++){
        cout<<p[i]<<" ";
    }
}

int &ARRAY::operator[] (int i) {
    if(i>0 && i<n){
        return p[i];
    }
    else{
        cout<<"Index Error";
    }
}

ARRAY::~ARRAY(){
    delete [] p;
}

ARRAY::ARRAY(const ARRAY &obj) {

}

int ARRAY::get_n() const{
    return n;
}

int main() {

    int n=10;
    ARRAY pin(10);

    for(int i=0; i<n; i++){
        pin[i]=i*i;
    }

    pin.print();

    return 0;
}