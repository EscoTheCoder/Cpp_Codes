#include <iostream>
using namespace std;

class Point{
private:
    double x,y;
public:
    Point(int x, int y) {
    this->x=x;
    this->y=y;
    }
    Point(){
        x=0;
        y=0;
    }

    double getX() const {
        return x;
    }

    void setX(double x) {
        this->x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        this->y = y;
    }
    void print_point() const{
        cout<<"("<<getX()<<","<<getY()<<")"<<endl;
    }
};

int main() {

    Point p1(1,2);
    Point p2(3,4);
    Point p3(9,5);

    p1.print_point();
    p2.print_point();
    p3.print_point();


    return 0;
}
