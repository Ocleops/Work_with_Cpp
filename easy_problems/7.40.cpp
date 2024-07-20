#include <iostream>
#include <vector>

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

int main()
{
    double res = 0;
    res = Hermite(3,-1.6);
    std::cout<<res;
}
