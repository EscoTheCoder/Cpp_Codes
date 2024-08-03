#include <iostream>
using namespace std;

class ARRAY{
public:
    ARRAY(int in_length);
    ~ARRAY();
    void set_i(int i,int val);
    int get_i(int i) const;
    void print();
private:
    int length;
    int *ptr;
};

ARRAY::ARRAY(int in_length) {
    length=in_length;
    ptr=new int[length];
    if(!ptr){
        cout<<"Error allocating memory";
    }
}
ARRAY::~ARRAY() {
    delete [] ptr;

}

void ARRAY::set_i(int i, int val) {
    if(i>=0 && i<length){
        ptr[i] = val;
    }
    else {
        cout<<"OUT OF BOUND"<<endl;
    }
}

int ARRAY::get_i(int i) const {
    if(i>=0 && i<length){
        return ptr[i];
    }
    else {
        cout<<"OUT OF BOUND"<<endl;
    }
}

void ARRAY::print() {
    for (int i = 0; i < length; i++) {
        cout << ptr[i] << " ";
    }
}

int main(){

    ARRAY array(10);

    for(int i=0; i<10; i++){
        array.set_i(i,i*i);
    }

    array.print();

    return 0;
}