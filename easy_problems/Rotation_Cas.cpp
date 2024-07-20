#include <iostream>
#include<vector>
#include<fstream>
#include <sstream>
int main()
{
    int N,M,K;
    std::ifstream input("casablanca.pgm");
    std::string P2;
    input >> P2 >> M >> N >> K;

    //M=lines , N=columns

    std::ofstream output ("Rotated.pgm");
    output <<P2<<"\n"<< N <<" "<< M <<"\n"<<K <<"\n";

    std::vector<int> original(N*M);
    std::vector<int> rotated(N*M);

    for(auto i=0; i<N; i++){
        for(auto j=0; j<M; j++){
            input >> original[i + j*N];
            //output << original[i + j*N] << "\n";
        }
    }

    //N=lines , M=columns


    for(auto i=0; i< N; i++){
        for(auto j=0; j< M; j++){
            rotated[j+(N-1-i)*M] = original[i+j*N];
        }
    }


    for(auto i=0; i< M; i++){
        for(auto j=0; j< N; j++){
            output << rotated[i+j*M] <<"\n";
        }
    }

}
