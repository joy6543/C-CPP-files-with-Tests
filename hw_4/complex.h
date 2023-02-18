#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex {
    public:
    Complex(double x, double y) : re(x), im(y) {}
    Complex(double a) : re(a), im(0) {};

    double magnitude() const;

    // Function real: Return real part of the complex number
    double real() const;

    // Function imaginary: Return imaginary part of the complex number
    double imaginary() const;

    // Function conjugate: Return conjugate of the complex number
    Complex conjugate() const;

    // Function operator+: Return sum of two complex numbers 
    // by overloading using '+' operator
    friend Complex operator+(const Complex &a, const Complex &b);

    // Function operator*: Return multiplication of two complex numbers 
    // by overloading using '*' operator
    friend Complex operator*(const Complex &a, const Complex &b);
    
    // Function operator==: Return if two complex numbers are equal or not
    // by overloading using '==' operator
    friend bool operator==(const Complex &a, const Complex &b);

    private:
    double re, im;
}; 

bool operator<(const Complex& a, const Complex& b);

#endif