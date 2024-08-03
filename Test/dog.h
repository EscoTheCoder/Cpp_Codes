#ifndef TEST_DOG_H
#define TEST_DOG_H

#endif //TEST_DOG_H


class complex{
public:
    complex();
    complex(double real, double imag);
    void set_real(double in_real);
    void set_imag(double in_imag);
    double get_real() const;
    double get_imag() const;
private:
    double real;
    double imag;
};

