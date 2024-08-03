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
    complex operator+ (int right) const; //operator +    uperfwrtwsh tou telesth +
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

complex complex::operator+ (int right) const{
//    complex result;
//    result.real=real+right;
//    result.imag=imag+right;
//    return result;

    return complex(real+right,imag+right); //POIOS APLOS KAI GRHGOROS TROPOS
}

int main() {

    complex a(1.0,1.0);
    //complex b(2.0,3.0);
    complex c;


    c=a+5; // me uperfwrtwsh telesth +

    cout<<c.get_real()<<" "<<c.get_imag();



    return 0;
}
