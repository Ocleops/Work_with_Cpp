#include <iostream>
#include <vector>
#include <random>
int main()
{
    int M = 5, N = 5;
    std::vector<int> v1(M*N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr1(0, M-1);
    std::uniform_int_distribution<> distr2(0, N-1);

    int x=0,y=0;
    for(auto i=0; i<4; i++){
        x = distr1(gen);
        y = distr2(gen);
        v1[x + M*y] = 1;
    }
    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            if(v1[i+M*j]==1){
                std::cout<<"x";
            }
            else{
                std::cout<<"o";
            }
        }
        std::cout<<"\n";
    }
}
