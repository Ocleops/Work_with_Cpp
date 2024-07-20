#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include <string>
int main()
{
    srand(time(NULL)*time(NULL)*time(NULL));
    std::ifstream input ("in.txt");
    std::vector<float> in(7*4);
    std::ofstream output("fractal.txt");
    std::vector<int> grid(512*512);

    //output<<"P1\n"<<"20 20\n";

    for(auto i=0; i<512; i++){
        for(auto j=0; j<512; j++){
            grid[i+512*j]=0;
        }
    }

    for(auto i=0; i<4; i++){
        for(auto j=0; j<7; j++){
            input >> in[i+4*j];
        }
    }
    //int c=0,x=0,y=0,x_prim,y_prim;
    int c1=0,c2=0,c3=0;
    float r,x=0,y=0,x_prime,y_prime;
    while(c2<1000000){
        while(c1<1000){
            r = (float)rand()/RAND_MAX;
            //std::cout<<x<<", "<<y<<"\n";
            if(r>=0 && r< in[0+4*6]){
                x_prime = in[0+4*0]*x + in[0+4*1]*y + in[0+4*4];
                y_prime = in[0+4*2]*x + in[0+4*3]*y + in[0+4*5];
            }
            else if(r >= in[0+4*6] && r<(in[0+4*6]+in[1+4*6])){
                x_prime = in[1+4*0]*x + in[1+4*1]*y + in[1+4*4];
                y_prime = in[1+4*2]*x + in[1+4*3]*y + in[1+4*5];
            }
            else if(r >= (in[0+4*6]+in[1+4*6]) && r< (in[0+4*6]+in[1+4*6]+ in[2+4*6])){
                x_prime = in[2+4*0]*x + in[2+4*1]*y + in[2+4*4];
                y_prime = in[2+4*2]*x + in[2+4*3]*y + in[2+4*5];
            }
            else if(r >= (in[0+4*6]+in[1+4*6]+ in[2+4*6]) && r<(in[0+4*6]+in[1+4*6]+ in[2+4*6]+in[3+4*6])){
                x_prime = in[3+4*0]*x + in[3+4*1]*y + in[3+4*4];
                y_prime = in[3+4*2]*x + in[3+4*3]*y + in[3+4*5];
            }
            else{
                std::cout<<"something is terribly wrong\n";
                c3++;
            }
            c1++;
            x = x_prime;
            y = y_prime;
        }
        output<<x<<" "<<y<<"\n";
        c2++;
    }
    std::cout<<c3;
    //std::cout<<x<<", "<<y<<"\n";
    //std::cout<<(in[0+4*6]+in[1+4*6]+ in[2+4*6]+in[3+4*6]);

}

