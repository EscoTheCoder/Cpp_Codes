#include <iostream>
using namespace std;


class dummy{
public:
    dummy(){
        ptr_val = new int;
        if(!ptr_val){
            cout<<"Error allocating memory";
        }
        cout<<"Constructing..."<<endl;
    }
    ~dummy(){
        delete ptr_val;
        cout<<"Destructing..."<<endl;
    }

    void setPtrVal(int in_value) {
        *ptr_val = in_value;
    }

    int getPtrVal() const {
        return *ptr_val;
    }

private:
    int *ptr_val;
};

int main() {

    dummy obj;
    obj.setPtrVal(3);
    dummy obj2;
    obj2=obj;

    cout<<obj.getPtrVal()<<endl;
    cout<<obj2.getPtrVal()<<endl;


    return 0;
}
