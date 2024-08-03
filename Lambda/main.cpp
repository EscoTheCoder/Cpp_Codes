#include <iostream>
using namespace std;

class dummy{
public:
    dummy(int in_value);
    ~dummy();
    int getValue() const;
    void setValue(int in_value);
private:
    int value;
    int *ptr;
};

dummy::dummy(int in_value) {
    value=in_value;
    ptr=new int;
    if(!ptr){
        cout<<"Error allocating memory";
    }
    *ptr=value;
}

dummy::~dummy() {
    delete ptr;
}

int dummy::getValue() const {
    return *ptr;
}

void dummy::setValue(int in_value) {
    value = in_value;
}


int main() {

    dummy d(10);

    cout<<d.getValue();

    return 0;

}

    //    unsigned howMany;
//    cin >> howMany;
//    int* storage = new int[howMany];
//
//    for(unsigned i = 0; i < howMany; i++) {
//        cin >> storage[i];
//    }
//    for(unsigned i = 0; i < howMany; i++) {
//        cout << i << ": " << storage[i] << endl;
//    }
//    delete[] storage;


