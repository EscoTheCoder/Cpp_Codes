#include <iostream>
#include <vector>

using namespace std;

//YPERFORTWSH TELESTWN

//class migadikos
class complex{
public:
    complex();
    complex(double real, double imag);
    void set_real(double in_real);
    void set_imag(double in_imag);
    double get_real() const;
    double get_imag() const;
    complex operator+ (const complex &right) const; //operator +    uperfwrtwsh tou telesth +
    complex operator-(const complex &right) const; //operator -    uperfwrtwsh tou telesth -
    complex operator++ (int right); //operator +    uperfwrtwsh tou telesth ++ -------> x++
    complex &operator++ (); //operator +    uperfwrtwsh tou telesth ++  -----> ++x
    complex &operator= (const complex &right); //operator +    uperfwrtwsh tou telesth =
    //int &operator[] (int i);
    friend complex operator+ (int left, complex &right); //operator +    uperfwrtwsh tou telesth +
    friend ostream &operator<<(ostream &left, const complex &right);
	//friend istream &operator>>(istream &left, STRING &obj);
private:
    double real;
    double imag;
};



complex::complex() {
    real=0.0;
    imag=0.0;
}
complex::complex(double in_real, double in_imag){
    real=in_real;
    imag=in_imag;
}

void complex::set_real(double in_real) {
    real=in_real;
}

void complex::set_imag(double in_imag) {
    imag=in_imag;
}

double complex::get_real() const {
    return real;
}

double complex::get_imag() const {
    return imag;
}

complex complex::operator+ (const complex &right) const{
//    complex result;
//    result.real=real+right.real;
//    result.imag=imag+right.imag;
//    return result;

    return complex(real+right.real,imag+right.imag); //POIO APLOS KAI GRHGORS TROPOS
}

complex complex::operator- (const complex &right) const{
//    complex result;
//    result.real=real-right.real;
//    result.imag=imag-right.imag;
//    return result;

    return complex(real-right.real,imag-right.imag); //POIO APLOS KAI GRHGORS TROPOS
}

complex complex::operator++ (int right){

    return complex(real++,imag++);
}

complex &complex::operator++ (){

    real++;
    imag++;
    return *this; //*this  = left stoixeio
}

complex &complex::operator= (const complex &right) {

    if(this==&right) {
        return *this; //*this  = left stoixeio
    }
    real=right.real;
    imag=right.imag;
    return *this;
}

//int &ARRAY::operator[] (int i) {
//    if(i>0 && i<n){
//        return p[i];
//    }
//    else{
//        cout<<"Index Error";
//    }
//}

complex operator+ (int left, complex &right){

//    complex result;
//    result.real=left+right.real;
//    result.imag=left+right.imag;
//    return result;
    return complex(left+right.real,left+right.imag);
}

ostream &operator<<(ostream &left, const complex &right){
    left<<"("<<right.real<<", "<<right.imag<<")";
    return left;
}

istream &operator>>(istream &left, STRING &obj){
    char in_str[80];

    left>>in_str;
    if(obj.str!=NULL){
    delete [] obj.str;
    }
    obj.str = new char [strlen(in_str)+1];  //+1 gia to \0
    if(!obj.str){
    cout<<"Error allocating memory";
    }
    obj.length= strlen(in_str);
    strcpy(obj.str,in_str);

    return left;
}


int main() {

    complex a(1.0,1.0);
//    complex b(2.0,3.0);
//    complex c;

    cout<<a;



    return 0;
}
