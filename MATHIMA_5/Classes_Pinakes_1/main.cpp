#include <iostream>
using namespace std;

class dummy{
private:
    int x,y;
public:
//    dummy(int x, int y){
//        this->x=x;
//        this->y=y;
//    cout<<"Constructing..."<<endl;
//    }
    dummy(int x, int y) : x(x), y(y) {
        cout<<"Constructing..."<<endl;
    }
    void print(){
        cout<<x<<" "<<y;
    }

    inline int getX() const {
        return x;
    }

    inline void setX(int x) {
        this->x = x;
    }

    inline int getY() const {
        return y;
    }

    inline void setY(int y) {
        this->y = y;
    }
};




inline int sqr(int x){
    return x*x;
}

int sum(int x1=0, int x2=0, int x3=0, int x4=0){
    return x1+x2+x3+x4;
}

int main() {
//    dummy obj(3,4);
//    obj.print();

//    cout<<sqr(4);

    //vlepoume ta prokathorismena orismata (default argument)
    cout<<sum(1,2,3,4)<<endl;
    cout<<sum(1,2,3)<<endl;
    cout<<sum(1,2)<<endl;

    return 0;
}