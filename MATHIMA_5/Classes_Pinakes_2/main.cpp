#include <iostream>
#define N 3
using namespace std;

class grades{
public:
    grades(){
        for(int i=0; i<N; i++){
            array[i]=0;
        }
    }
    void set_i(int pos, int value){
        if(pos>=0 && pos<N) {
            array[pos] = value;
        }
        else{
            cout<<"out of bounds";
        }
    }
    int get_i(int pos) const{
        if(pos>=0 && pos<N) {
            return array[pos];
        }
        else{
            cout<<"out of bounds";
        }
    }
private:
    int array[N];
};

class dummy{
private:
    int x;
public:
    dummy(){
        x=0;
    }
    dummy(int x){
        this->x=x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getX() const {
        return x;
    }

};



int main() {

//    grades my_grades;
//    //eisagwgh dedomenwn
//    my_grades.set_i(0,5);
//    my_grades.set_i(1,8);
//    my_grades.set_i(2,7);
//
//    //ektupwsh dedomenwn
//    for(int i=0; i<N; i++){
//        cout<<my_grades.get_i(i)<<endl;
//    }

//    dummy array[N]={dummy(),dummy(3),dummy(5)};

//    dummy array[N];
//    for(int i=0; i<N; i++){
//        array[i].setX(i*i);
//    }
//    for(int i=0; i<N; i++){
//        cout<<array[i].getX()<<" ";
//    }

//    dummy *array;
//    int n=3;
//
//    array = new dummy [n];
//    if(!array) {
//        cout << "Mem error";
//    }
//
//    for(int i=0; i<N; i++){
//        array[i].setX(i*i);
//    }
//
//    for(int i=0; i<N; i++){
//        cout<<array[i].getX()<<" ";
//    }
//
//    delete [] array;

    dummy *array[N];

    for(int i=0; i<N; i++){
        array[i] = new dummy;
    }

    for(int i=0; i<N; i++){
        array[i]->setX(i*i);
    }

    for(int i=0; i<N; i++){
        cout<<array[i]->getX()<<" ";
    }

    for(int i=0; i<N; i++){
        delete array[i];
    }

    return 0;
}
