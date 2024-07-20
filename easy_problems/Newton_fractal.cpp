#include <iostream>
#include <vector>
#include <fstream>
#include <complex>
#include <cmath>
#include <math.h>
#define j std::complex<double> (0.0 , 1.0)

int main()
{
    std::complex<double> a;
    std::complex<double> b;
    std::complex<double> c;
    a = 1.0 + j*0.0;
    b = cos(2*M_PI/3.0) + j* sin(2*M_PI/3.0);
    c = cos(-2*M_PI/3.0) + j* sin(-2*M_PI/3.0);

    std::vector<double> N(513);
    std::vector<double> M(513);

    for(int i=0; i<513; i++){
        double val = -1.0;
        val = val + i * (2.0/512.0);
        N[i] = val;
    }

    for(int i=0; i<513; i++){
        double val = -1.0;
        val = val + i * (2.0/512.0);
        M[i] = val;
    }

    std::ofstream err("err.txt");
    std::ofstream output("Newton_frac.ppm");
    output<<"P3\n"<<"513 513\n"<<"255\n";

    std::complex<double> z;
    double tol=0.0001;
    for(auto i=0; i<513; i++){
        for(auto n=0; n<513; n++){

            if(i==256 && n==256){
                output<<"255 255 255\n";
                continue;
            }

            z = N[i] + j*M[n];

            while( abs((pow(z,3)- (1.0+0.0*j))) > tol ){
                z = z - ( pow(z,3) - (1.0 + 0.0*j) ) /( (3.0+0.0*j) * pow(z,2) );
            }

            if(abs(z-a)<tol){
                output<<"255 0 0\n";
            }
            else if(abs(z-b)<tol){
                output<<"0 255 0\n";
            }
            else if(abs(z-c)<tol){
                output<<"0 0 255\n";
            }
            else{
                std::cout<<"error\n";
                err<<i<<" "<<n<<" "<<z<<"\n";
            }
        }
    }

}
