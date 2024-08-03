//
// Created by nikolas on 9/7/2024.
//

#include "dog.h"

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