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
    complex &operator++ (); //operator +    uperfwrtwsh tou telesth +
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

complex &complex::operator++ (){

    real++;
    imag++;
    return *this; //*this  = left stoixeio
}

int main() {

    complex a(1.0,1.0);
    complex c;

    c=++a; // me uperfwrtwsh telesth ++

    cout<<a.get_real()<<" "<<a.get_imag()<<endl;
    cout<<c.get_real()<<" "<<c.get_imag();



    return 0;
}
