#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#define pi M_PI

template<typename T>
T Hermite(int n, T x)
{
    std::vector<T> Hn(n+1);
    Hn[0]=1;
    Hn[1]= 2*x;
    T Hermite_value = 0;
    if(n<2){
        return Hn[n];
    }
    else{
        for(auto i=2; i<=n; i++){
            Hermite_value = 2*x*Hn[i-1] - 2*(i-1)*Hn[i-2];
            Hn[i] = Hermite_value;
        }
    }
    return Hn[n];

}

template<typename T>
double wavefunction(int n, T x)
{
    T y = 0;
    double k=1, m=1, hbar=1;
    y=x*sqrt(sqrt(k*m)/hbar);

    T Hermite_value = 0;
    Hermite_value = Hermite(n,y);

    int nfactorial = 1;
    for(auto i=2; i<=n; i++){
        nfactorial = nfactorial * i;
    }
    double constant = 0;
    constant = sqrt(1/(pow(2,n)*nfactorial*sqrt(pi)));

    double Prob = 0;
    Prob = pow(constant,2) * pow(Hermite_value,2) * exp(-pow(x,2));


    return Prob;
}

int main ()
{
    std::ofstream output ("Harmonic.txt");
    for(double x=-6.0; x<6.2; x=x+0.2){
        output << x << "\t" << "-->" << "\t" << wavefunction(5,x) << "\n";
    }

}
