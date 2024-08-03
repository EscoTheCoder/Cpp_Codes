#include <iostream>
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
    friend complex operator+ (int left, complex &right); //operator +    uperfwrtwsh tou telesth +
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

complex operator+ (int left, complex &right){
    return complex(left+right.real,left+right.imag);
}

int main() {

    complex a(1.0,1.0);
    //complex b(2.0,3.0);

    complex c;

    c=5+a;

    cout<<c.get_real()<<" "<<c.get_imag();

    return 0;
}
