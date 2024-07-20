#include <iostream>
#include <vector>
#include <fstream>
int digit(int N, int d)
{
    int mod=10, div=1;
    for(auto i=2; i<=d; i++){
        mod = mod*10;
        div = div*10;
    }
    int result = -1;
    result = (N%mod/div);
    return result;
}


int main ()
{
    std::ifstream input("ints201411.txt");
    std::vector<int>v1;
    int i=0;
    while(input >> i){
        v1.push_back(i);
    }

    std::ofstream output ("digits.txt");
    for(auto i=0; i<v1.size(); i++){
        output << digit(v1[i],3)<<"\n";
    }

}
