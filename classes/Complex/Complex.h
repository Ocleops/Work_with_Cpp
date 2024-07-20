#ifndef COMPLEX_H
#define COMPLEX_H


template<typename T>
class Complex
{
    public:
        Complex()
        {
            T a=0,b=0;
            real = a;
            imag = b;
        }

        Complex(T a):
            real(a),
            imag(0){}

        Complex(T a, T b):
            real(a),
            imag(b){}

        Complex(const Complex<T>& z)
        {
            (*this).real = z.real;
            (*this).imag = z.imag;
        }

        void print();

        Complex<T> operator=(const Complex<T> & );
        Complex<T> operator+=(const Complex<T> &);
        Complex<T> operator-=(const Complex<T> &);
        Complex<T> operator*=(const Complex<T> &);
        Complex<T> operator+(const Complex<T> &);
        Complex<T> operator-(const Complex<T> &);
        Complex<T> operator*(const Complex<T> &);
        Complex<T> operator/(const Complex<T> &);

        T get_real();
        T get_imag();

        Complex<T> REAL(T);
        Complex<T> IMAG(T);


    private:
        T real, imag;
};

#endif // COMPLEX_H
