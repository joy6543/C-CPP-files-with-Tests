#include <math.h>
#include "complex.h"

double Complex::magnitude() const {

    return sqrt(re*re + im*im);

}

bool operator<(const Complex& a, const Complex& b) {

    return a.magnitude() < b.magnitude();

}

// Function real: Return real part of the complex number
double Complex::real() const {
    return re;
}

// Function imaginary: Return imaginary part of the complex number
double Complex::imaginary() const {
    return im;
}

// Function conjugate: Return conjugate of the complex number
Complex Complex::conjugate() const {
    return Complex(re , -im);
}

// Function operator+: Return sum of two complex numbers 
// by overloading using '+' operator
Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.re + b.re , a.im + b.im);
}

// Function operator*: Return multiplication of two complex numbers 
// by overloading using '*' operator
Complex operator*(const Complex &a, const Complex &b) {
    return Complex(a.re * b.re - a.im * b.im , a.re * b.im + a.im * b.re);
}

// Function operator==: Return if two complex numbers are equal or not
// by overloading using '==' operator
bool operator==(const Complex &a, const Complex &b) {
    return (a.re == b.re) && (a.im == b.im);
}