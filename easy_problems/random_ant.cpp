#include<iostream>
#include<vector>
#include<ctime>
int main()
{
    int M=9,N=9;
    std::vector<int> grid(M*N);
    for(auto i=0; i<N; i++){
        for(auto j=0; j<M; j++){
            if(i==N-1){
                grid[i+N*j]=1;
            }
            else{
                grid[i+N*j]=0;
            }
        }
    }

    for(auto i=0; i<N; i++){
        for(auto j=0; j<M; j++){
            std::cout<<grid[i+j*N];
        }
        std::cout<<"\n";
    }
    std::cout<<"\n"<<"\n";

    srand(time(NULL));
    int x=4,y=4,carry=0,c=0,c1=0,dir;

    while(true){
        c1++;
        dir=rand()%4;
        switch(dir){
    case(0):
        if(x<1){
            continue;
        }
        else{
            x--;
        }
        break;
    case(1):
        if(x>=N-1){
            continue;
        }
        else{
            x++;
        }
        break;
    case(2):
        if(y<1){
            continue;
        }
        else{
            y--;
        }
        break;
    case(3):
        if(y>=M-1){
            continue;
        }
        else{
            y++;
        }
        break;
        }
        if(grid[x+y*M]==1 && carry==0 && x==8){
            carry++;
            grid[x+y*M]--;
        }
        if(grid[x+y*M]==0 && carry==1 && x==0){
            carry--;
            grid[x+y*M]++;
        }
        for(auto j=0; j<M; j++){
            if(grid[0+j*M]==1){
                c++;
            }
        }
        if(c==9){
            break;
        }
        else{
            c=0;
        }
        if(c1>20000){
            break;
        }
    }


    for(auto i=0; i<N; i++){
        for(auto j=0; j<M; j++){
            std::cout<<grid[i+j*N];
        }
        std::cout<<"\n";
    }
    std::cout<<"\n"<<c1;


}
