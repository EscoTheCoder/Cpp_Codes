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
        void insert_point(point &ob);
        void clear();
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

void board::insert_point(point &ob) {
    if(ob.get_x()>=0 && ob.get_x()<N && ob.get_y()>=0 && ob.get_y()<N){
        p[ob.get_x()][ob.get_y()]='o';
    }
}

void board::clear() {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(p[i][j]!='.'){
                p[i][j]='.';
            }
        }
    }
}

int main() {
    board b(30);
    point temp_point(0,0);
    int choice;
    int x, y;
    while (true) {
        cout << "MENU" << endl;
        cout << "1) Na eisagei ena kainourio shmeio" << endl;
        cout << "2) Na ektupwsei to plaisio" << endl;
        cout << "3) Na katharisei to plasio" << endl;
        cout << "4) Na ginei ejodos apo to programma" << endl;
        cout << ">";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Dwse x, y: ";
                cin >> x >> y;
                temp_point.set_x(x);
                temp_point.set_y(y);
                b.insert_point(temp_point);
                break;
            case 2:
                cout << endl << b;
                break;
            case 3:
                b.clear();
                break;
            case 4:
                cout << "Bye Bye!!!";
                exit(0);
            default:
                cout << "Lathos EISODOS...";
        }
    }
    return 0;
}

