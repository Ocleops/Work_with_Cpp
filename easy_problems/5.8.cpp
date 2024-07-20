#include <iostream>
#include <vector>

int main()
{
    int N=40, counter=0;
    std::vector<int>v1(N);
    std::vector<int>v2;
    for(auto i=0; i<N; i++){
        v1[i]=i+2;
    }
    int value=0, res=0;
    for(auto i=0; i<v1.size(); i++){
        value = v1[i];
        counter = 0;
        for(auto j=0; j<v1.size(); j++){
            res = value % v1[j];
            if(res == 0){
                counter += 1;
            }
        }
        if(counter < 2){
            v2.push_back(value);
        }
    }


    for(auto i=0; i<v2.size(); i++){
        std::cout<<v2[i]<<"\n";
    }
}
