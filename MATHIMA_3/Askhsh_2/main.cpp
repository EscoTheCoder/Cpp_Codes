#include <iostream>
using namespace std;

class ARRAY{
private:
    int *p;
    int n;
public:
    ARRAY(int n){
        this->n=n;
        p=new int [n];
        if(!p){
            cout<<"Error allocating memory!";
        }
    }
    ~ARRAY(){
        delete [] p;
    }
    void set_i(int i,int value){
        if(i>=0 && i<n){
            p[i]=value;
        }
        else{
            cout<<"Error: Out of bounds!";
        }
    }
    int get_i(int i){
        if(i>=0 && i<n) {
            return p[i];
        }
        else{
            cout<<"Error: Out of bounds!";
        }
    }
    void print(){
        for(int i=0; i<n; i++){
            cout<<p[i]<<" ";
        }
    }
};

int main() {

    int n=10;
    ARRAY pin(n);
    ARRAY pin2(n);

    for(int i=0; i<n; i++){
        pin.set_i(i,i*i);
    }

    for(int i=0; i<n; i++){
        pin2.set_i(i,i*i*i);
    }

    pin=pin2;

    pin.print();
    cout<<endl;
    pin2.print();

    //UPARXEI TO BUG ME THN ANTIGRAFH ANTIKEIMENWN

    return 0;
}
