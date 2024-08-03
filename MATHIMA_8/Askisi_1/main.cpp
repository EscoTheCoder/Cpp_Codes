/* cpp6.askisi2.cpp */

#include <iostream>
using namespace std;

class ARRAY {
public:
    ARRAY(int in_n);
    ARRAY(const ARRAY &ob);
    ~ARRAY();
    int get_n() const;
    int &operator[] (int i);
    ARRAY &operator= (ARRAY &right);
    ARRAY &operator+= (int right);
    friend ostream &operator<<(ostream &left, const ARRAY &obj);
    static int MAX_LENGTH;
private:
    int *p;
    int n;
};


ARRAY::ARRAY(int in_n)
{

    if (in_n<=ARRAY::MAX_LENGTH) {
        n = in_n;
        p = new int[n];
        if (!p) {
            cout << "Error allocating memory!";
        }
    }
    else{
        cout<<"ERROR n is to big!";
        n=0;
    }
}

ARRAY::ARRAY(const ARRAY &ob)
{
    n = ob.get_n();

    p = new int [n];
    if (!p) cout<<"Memory Allocation Error!";
}

ARRAY::~ARRAY()
{
    if(n>0) {
        delete[] p;
    }
}

int ARRAY::get_n() const
{
    return n;
}

//void ARRAY::print()
//{
//    int i;
//
//    for (i=0; i<n; i++)
//        cout<<p[i]<<" ";
//}

int &ARRAY::operator[] (int i)
{
    if (i>=0 && i<n)
        return p[i];
    else
        cout<<"Index Error";
}

ARRAY &ARRAY::operator= (ARRAY &right)
{
    if (this==&right) return *this;

    n=right.n;
    delete [] p;
    p=new int [n];
    if(!p) cout<<"Error Allcoating Memory";

    for (int i=0; i<n; i++)
        p[i]=right[i];

    return *this;
}

ARRAY &ARRAY::operator+= (int right)
{
    int newn=n+right;
    int *newp;
    int i;

    if (right>0)
    {
        newp = new int [newn];
        if (!newp) cout<<"Error Allocating Memory";

        for (i=0; i<n; i++)
            newp[i]=p[i];
        for (i=n; i<newn; i++)
            newp[i]=0;

        delete [] p;
        n=newn;
        p=newp;
    }
    else
        cout<<"Wrong index!";
    return *this;
}

ostream &operator<<(ostream &left, const ARRAY &obj){

    left<<"[";
    for(int i=0; i<obj.n-1; i++){
        left<<obj.p[i]<<", ";
    }
    left<<obj.p[obj.n-1];
    left<<"]";
    return left;
}

int ARRAY::MAX_LENGTH=1000;



int main()
{
    int n=1001;
    ARRAY pin(n);

    return 0;
}