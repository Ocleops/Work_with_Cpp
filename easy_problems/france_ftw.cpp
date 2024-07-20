#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
int main()
{
    std::string P3="P3";
    int height=360, weidth=360, K=255;
    std::ofstream output("france.ppm");
    output<<P3<<"\n"<<weidth<<" "<<height<<"\n"<<K<<"\n";

    std::vector<int>pixels(weidth*height);

    for(auto i=0; i<height; i++){
        for(auto j=0; j<weidth; j++){
            if(j<weidth/3){
                output<<0<<" "<<0<<" "<<255<<"\n";
            }
            else if(j >= weidth/3 && j < 2*weidth/3){
                output<<255<<" "<<255<<" "<<255<<"\n";
            }
            else{
                output<<255<<" "<<0<<" "<<0<<"\n";
            }
        }
    }
}
