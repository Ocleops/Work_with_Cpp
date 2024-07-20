#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
int main ()
{
    std::string P2;
    int weidth, height,K;
    int p=5;


    std::ifstream input("casablanca.pgm");
    input >> P2 >> weidth >> height >> K;
    std::ofstream output("blur.pgm");
    output <<P2<<"\n"<<weidth<<" "<<height<<"\n"<<K<<"\n";

    std::vector<int>original(height*weidth);
    std::vector<int>blur(height*weidth);

    for(auto i=0; i<height; i++){
        for(auto j=0; j<weidth; j++){
            input>>original[i+height*j];
            //output<<original[i+height*j]<<"\n";
        }
    }
    int counter=0,sum=0;
    for(auto i=0; i<height; i++){
        for(auto j=0; j<weidth; j++){
            for(auto k=i-p; k<=i+p; k++){
                if(k<0 || k >= height){
                    continue;
                }
                for(auto n=j-p; n<=j+p; n++){
                    if(n<0 || n >= weidth){
                        continue;
                    }
                    sum =sum+ original[k+n*height];
                    counter++;
                }
            }
             output << sum/counter << "\n";
             sum=0;
             counter=0;
        }
    }


}
