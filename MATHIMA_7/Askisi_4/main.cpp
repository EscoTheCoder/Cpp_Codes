#include <iostream>
using namespace std;

class point{
private:
    int x,y;
public:
    point(int in_x, int in_y);
    void set_x(int in_x);
    int get_x() const;
    void set_y(int in_y);
    int get_y() const;
    friend ostream &operator<<(ostream &left, const point &right);
};

point::point(int in_x, int in_y) {
    if(in_x<0 || in_x>59){
        cout<<"Lathos timh tou x"<<endl;
        x=0;
    }
    else{
        x=in_x;
    }
    if(in_y<0 || in_y>59){
        cout<<"Lathos timh tou y"<<endl;
        y=0;
    }
    else{
        y=in_y;
    }
}

void point::set_x(int in_x) {
    x=in_x;
}

int point::get_x() const {
    return x;
}

void point::set_y(int in_y) {
    y=in_y;
}

int point::get_y() const {
    return y;
}

ostream &operator<<(ostream &left, const point &right){
    left<<"("<<right.x<<", "<<right.y<<")";
    return left;
}

int main() {

    point p(100,65);

    cout<<p;

    return 0;
}
