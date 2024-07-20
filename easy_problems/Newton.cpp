#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <complex>
#include <math.h>

#define j std::complex<float> (0.0,1.0)

int main()
{
    std::vector<float> N(513);
    std::vector<float> M(513);

    std::complex<float> root1(1,0);
    std::complex<float> root2(cos(2*M_PI/3.0) , sin(2*M_PI/3.0));
    std::complex<float> root3(cos(-2*M_PI/3.0), sin(-2*M_PI/3.0));

//    std::cout << "Real part: " << real(root1)<<"\n";
//    std::cout << "Imaginary part: " << imag(root1);

    for(int i=0; i<513; i++){
        float a= -1.0;
        a = a + i * (2.0/512.0);
        N[i] = a;
        //std::cout<<N[i]<<"\n";
    }

    for(int i=0; i<513; i++){
        float a= -1.0;
        a = a + i * (2.0/512.0);
        M[i] = a;
        //std::cout<<M[i]<<"\n";
    }


    std::ofstream err("err.txt");
    std::ofstream output("Newton_frac.ppm");
    output<<"P3\n"<<"512 512\n"<<"255\n";

    float eps=0.000001;
    std::complex<float> one(1,0);
    std::complex<float> three(3,0);

    std::complex<float> z(0,0);
    std::complex<float> P(0,0);
    std::complex<float> P_prime(0,0);
    std::complex<float> div(0,0);
    float a,b,c,d;

    for(auto i=0; i<513; i++){
        for(auto j=0; j<513; j++){
            if(i==256 && j==256){
                output<<"255 255 255\n";
                continue;
            }
        }
    }


}
