#include <iostream>
#include <cmath>
#include "Complex.h"

template<typename T>
void Complex<T>::print()
{
    std::cout<<"("<<real<<", "<<imag<<")";
}

template<typename T>
T Complex<T>::get_real()
{
    return real;
}

template<typename T>
T Complex<T>::get_imag()
{
    return imag;
}

template<typename T>
Complex<T> Complex<T>::operator=(const Complex<T>& z)
{
    Complex<T> new_ob;
    (*this).real = z.real;
    (*this).imag = z.imag;

    return *this;
}

template<typename T>
Complex<T> Complex<T>::operator+=(const Complex<T>& z)
{
    Complex<T> new_z;
    (*this).real = (*this).real + z.real;
    (*this).imag = (*this).imag + z.imag;

    return (*this);
}

template<typename T>
Complex<T> Complex<T>::operator-=(const Complex<T>& z)
{
    (*this).real = (*this).real - z.real;
    (*this).imag = (*this).imag - z.imag;

    return (*this);
}

template<typename T>
Complex<T> Complex<T>::operator*=(const Complex<T> & other)
{
    (*this).real =(*this).real * other.real - (*this).imag*other.imag;
    (*this).imag = (*this).real*other.imag + (*this).imag * other.real;

    return (*this);
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& z)
{
    Complex<T> new_z;
    new_z.real = (*this).real + z.real;
    new_z.imag = (*this).imag + z.imag;

    return new_z;
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T>& z)
{
    Complex<T> new_z;
    new_z.real = (*this).real - z.real;
    new_z.imag = (*this).imag - z.imag;

    return new_z;
}

template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& z)
{
    Complex<T> new_z;
    new_z.real = (real*z.real - imag*z.imag);
    new_z.imag = (real*z.imag + imag* z.real);

    return new_z;
}

template<typename T>
Complex<T> Complex<T>::operator/(const Complex<T>& z)
{
    Complex<T> new_z;
    new_z.real = (real*imag + z.real*z.imag)/(pow(z.real,2) + pow(z.imag,2));
    new_z.imag = (imag* z.real - real*z.imag)/(pow(z.real,2) + pow(z.imag,2));

    return new_z;

}

template<typename T>
Complex<T> Complex<T>::REAL(T a)
{
    real = a;

    return *this;
}

template<typename T>
Complex<T> Complex<T>::IMAG(T a)
{
    imag = a;

    return *this;
}

template<typename T>
std::ostream & operator<<(std::ostream & out, const Complex<T> & z)
{
    Complex<T> new_ob;
    new_ob = z;
    out<<"("<<new_ob.get_real()<<", "<<new_ob.get_imag()<<")\n";
    return out;
}



int main()
{
    Complex<double> a; // a = 0.0 + 0.0 i
    Complex<float> b; // b = 0.0f + 0.0f i
    Complex<double> z1{3.4,2.8};
    Complex<double> z2{3.4};
    Complex<double> z3{z2}; // z3 = 3.4 + 0.0 i
    a = z1; // a = z1;
    auto z5 = z1+z2;
    auto z6 = z1+z3-z2;
    auto z7 = z1*z3/z2;
    z7 += z2;
    z6 -= z1;
    z5 *= z3;
    std::cout << z5.get_real() << ' ' << z5.get_imag() << '\n';
    a.REAL(4.2); // y = 4.2 + 2.8 i
    a.IMAG(-0.9); // y = 4.2 - 0.9 i
    std::cout << a << '\n'; // -> (4.2,-0.9)
}
