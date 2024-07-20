#include <iostream>
#include <fstream>
#include <complex>
#include <cmath>

#define j std::complex<double> (0.0,1.0)


int R (int &I, int &K)
{
    int s;
    s=I/((K+1)*(K+1));
    return s;
}

int G (int &I, int &K)
{
    return (I/(K+1))%(K+1);
}

int B (int &I, int &K)
{
    return I%(K+1);
}


int I (int &R, int &G, int &B, int &K)
{
    return R*(K+1)*(K+1)+ G* (K+1) + B;
}


std::complex <double> z_i ( std::complex<double> & z , std::complex<double> & c)
{
    return pow(z,2)+c;
}


int mandelbrot (std::complex <double> &c, int &N)
{
    std::complex<double> z=c;
    int i=0;
    while(i< N){
        if(abs(z)> 2){
            break;
        }
        z=z_i(z,c);
        i++;
    }
    return N-i;
}


int main ()
{
    int i,r,b,g,K=5;
    int N=(K+1)*(K+1)*(K+1)-1;
    std::complex<double> c;
    std::complex<double> z;
    std::ofstream out ("test.ppm");
    out << "P3\n" << "512" << " 768\n"<< K <<"\n";

    for(double x = -0.5 ; x < 0 ; x += 0.5/768){
    for(double y = -0.5 ; y < 0 ; y += 0.5/512){

            c=x+j*y;
            i=mandelbrot(c,N);
            r=R(i,K);
            b=B(i,K);
            g=G(i,K);
            out << r << " " << g << " " << b << "\n";
        }
    }
}
