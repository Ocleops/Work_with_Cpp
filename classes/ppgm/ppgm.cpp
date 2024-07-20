#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "ppgm.h"


ppgm::ppgm(std::string name)
{
    int k=0, h=0,w=0;
    std::string P2;
    std::ifstream input (name);
    input >> P2 >> w >> h >> k;
    //std::cout<<P2<<"\n"<<w<<" "<<h<<"\n"<<K<<"\n";
    weidth = w;
    height = h;
    K=k;

    std::vector<int> read(weidth * height);
    for(auto i=0; i<height; i++){
        for(auto j=0; j<weidth; j++){
            input >> read[i+height*j];
        }
    }
    image = read;
}

ppgm::ppgm(ppgm & other)
{
    (*this).image = other.image;
    (*this).weidth = other.weidth;
    (*this).height = other.height;
    (*this).K = other.K;
}
ppgm::~ppgm(){}

int ppgm::Width()
{
    return weidth;
}

int ppgm::Height()
{
    return height;
}

void ppgm::write(std::string name)
{
    std::ofstream output (name);
    output << "P2\n"<<weidth<<" "<<height<<"\n"<<K<<"\n";
    for(auto i=0; i<height; i++){
        for(auto j=0; j<weidth; j++){
            output << image[i+height*j]<<"\n";
        }
    }
}

void ppgm::blur(int p)
{
    std::vector<int> blured(weidth * height);
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
                    sum =sum+ image[k+n*height];
                    counter++;
                }
            }
            blured[i+height*j] = sum/counter;
             //output << sum/counter << "\n";
             sum=0;
             counter=0;
        }
    }

    image = blured;
}

void ppgm::rotate(int deg)
{
    int N=0, M=0;
    std::vector<int> rotated(weidth*height);
    if(deg == -90){
        deg = 270;
    }
    else if(deg == -180){
        deg = 180;
    }
    else if(deg == -270){
        deg = 90;
    }
    else if(deg == 360 || deg == -360){
        deg = 0;
    }

    switch(deg){
case 0:
    break;

case 90:
    N=height;
    M=weidth;
    for(auto i=0; i< N; i++){
            for(auto j=0; j< M; j++){
                rotated[j+(N-1-i)*M] = image[i+j*N];
            }
        }
    height = M;
    weidth = N;
    image = rotated;
    break;

case 180:
    for(auto iter=0; iter<2; iter++){
        N=height;
        M=weidth;
        for(auto i=0; i< N; i++){
                for(auto j=0; j< M; j++){
                    rotated[j+(N-1-i)*M] = image[i+j*N];
                }
            }
        height = M;
        weidth = N;
        image = rotated;
    }
    break;

case 270:
    for(auto iter=0; iter<3; iter++){
        N=height;
        M=weidth;
        for(auto i=0; i< N; i++){
                for(auto j=0; j< M; j++){
                    rotated[j+(N-1-i)*M] = image[i+j*N];
                }
            }
        height = M;
        weidth = N;
        image = rotated;
    }
    break;
    }

}

void ppgm::crop(int x1, int x2, int y1, int y2)
{
    int w=0, h=0;
    w = x2-x1;
    h = y2-y1;
    std::vector<int>cropped(w*h);
    for(auto i=y1; i<y2; i++){
        for(auto j=x1; j<x2; j++){
            cropped[(i-y1)+h*(j-x1)] =  image[i+height*j];
        }
    }

    image = cropped;

    height = h;
    weidth = w;

}





