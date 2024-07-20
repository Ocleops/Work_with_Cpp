#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N=10000, sqN=0;
    int res=0, mod=100, div=10, k=0;
    std::vector<int> v{1,2,3,4,5};
    while(true){
        sqN = N*N;
        for(auto i=0; i<5; i++){
            res = sqN%mod/div;
            if(res == v[4-i]){
                mod = mod*100;
                div = div*100;
                k += 1;
            }
            else{
                k=0;
                mod = 100;
                div = 10;
                N += 1;
                break;
            }
        }
        if(k == 5){
            break;
        }
    }
    std::cout<<N;
}
