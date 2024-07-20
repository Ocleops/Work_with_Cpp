#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>

int main ()
{
    std::ifstream input ("primes.txt");
    int i=0;
    std::vector<int> v;
    while(input >> i){
        v.push_back(i);
    }

    int n=76378260;
    std::vector<int> factors;
    int j =0, res=0;
    while(j < v.size()){
        res = n%v[j];
        if(res == 0){
            factors.push_back(v[j]);
            n = n/v[j];
        }
        else{
            j += 1;
        }
    }

    for(auto i=0; i<factors.size(); i++){
        std::cout<<factors[i]<<" ";
    }

}
