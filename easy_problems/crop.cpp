#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>

int main()
{
    std::string name = "casablanca.pgm";
    std::string P2;
    int K=0, weidth=0, height=0, w=0, h=0;
    int x1=154, x2=347, y1=150, y2=280;
    std::ifstream input(name);
    input>> P2>>weidth>>height>>K;
    //std::cout<<P2<<"\n"<<weidth<<" "<<height<<"\n"<<K<<"\n";
    std::vector<int> image(weidth*height);
    for(auto i=0; i<height; i++){
        for(auto j=0; j<weidth; j++){
            input>>image[i+j*height];
        }
    }


    w = x2-x1;
    h = y2-y1;
    std::ofstream output("testCAS.pgm");
    std::vector<int>cropped(w*h);
    output<<P2<<"\n"<<x2-x1<<" "<<y2-y1<<"\n"<<K<<"\n";

    for(auto i=y1; i<y2; i++){
        for(auto j=x1; j<x2; j++){
            cropped[(i-y1)+h*(j-x1)] =  image[i+height*j];
        }
    }

    image = cropped;

    for(auto i=0; i<h; i++){
        for(auto j=0; j<w; j++){
            output << image[i+h*j] << "\n";
        }
    }

}
