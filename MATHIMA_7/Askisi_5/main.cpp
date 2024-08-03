#include <iostream>
#include <cstdlib>
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



class board{
    private:
        int N;
        char **p;
    public:
        board(int in_N);
        board(const board &obj);
        ~board();
        board &operator= (const board &obj);
        char get_elem(int i, int j) const;
        friend ostream &operator<<(ostream &left, const board &right);

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

board::board(int in_N){
    N=in_N;
    p=new char *[N];
    if(!p){
        cout<<"Error Allocating Memory";
        exit(0);
    }
    for(int i=0; i<N; i++){
        p[i]=new char [N];
        if(!p[i]){
            cout<<"Error Allocating Memory";
            exit(0);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            p[i][j]='.';
        }
    }
}

board::~board() {
    for(int i=0; i<N; i++){
        delete [] p[i];
    }
    delete [] p;
}

board::board(const board &obj){
    N=obj.N;
    p=new char *[N];
    if(!p){
        cout<<"Error Allocating Memory";
        exit(0);
    }
    for(int i=0; i<N; i++){
        p[i]=new char [N];
        if(!p[i]){
            cout<<"Error Allocating Memory";
            exit(0);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            p[i][j]=obj.p[i][j];
        }
    }
}

board &board::operator=(const board &obj) {
    if(p!=NULL){
        for(int i=0; i<N; i++){
            delete [] p[i];
        }
        delete [] p;
    }
    N=obj.N;
    p=new char *[N];
    if(!p){
        cout<<"Error Allocating Memory";
        exit(0);
    }
    for(int i=0; i<N; i++){
        p[i]=new char [N];
        if(!p[i]){
            cout<<"Error Allocating Memory";
            exit(0);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            p[i][j]=obj.p[i][j];
        }
    }
}

char board::get_elem(int i, int j) const {
    return p[i][j];
}

ostream &operator<<(ostream &left, const board &right){
    for(int i=right.N-1; i>=0; i--) {
        for (int j = 0; j < right.N; j++){
            left<<right.p[i][j]<<" ";
        }
        left<<endl;
    }
    return left;
}

int main() {

    point p(100,65);
    board b(40);

    cout<<b;

    return 0;
}
