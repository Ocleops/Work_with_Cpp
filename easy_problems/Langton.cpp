#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>


void save(std::vector<int>&grid, int a, int M, int N)
{
    std::ostringstream name;
    name<<"LA_version_"<<a<<".pbm";
    std::ofstream output(name.str());
    output<<"P1\n"<<N<<" "<<M<<"\n";

    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            output<<grid[i+M*j]<<"\n";
        }
    }
}


int main()
{
    int M=512,N=512;
    std::vector<int>grid(M*N);
    std::vector<int>new_grid(M*N);
    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            grid[i+M*j]=0;
        }
    }


//    for(auto i=0; i<M; i++){
//        for(auto j=0; j<N; j++){
//            std::cout<<grid[i+M*j];
//        }
//        std::cout<<"\n";
//    }

    int x=256,y=256;
    int c=0, ant_dir=0;

    while(c<20000){
        if(grid[x+M*y]==0){
            grid[x+M*y]++;
            ant_dir++;
        }
        else if(grid[x+M*y]==1){
            grid[x+M*y]--;
            ant_dir--;
        }

        switch(ant_dir){
    case(0):
        if(x<1){
            continue;
        }
        else{
            x--;
        }
        break;
    case(1):
        if(y>=N-1){
            continue;
        }
        else{
            y++;
        }
        break;
    case(2):
        if(x>=M-1){
            continue;
        }
        else{
            x++;
        }
        break;
    case(3):
        if(y<1){
            continue;
        }
        else{
            y--;
        }
        break;
    case(4):
        ant_dir=0;
        if(x<1){
            continue;
        }
        else{
            x--;
        }
        break;
    case(-1):
        ant_dir=3;
        if(y<1){
            continue;
        }
        else{
            y--;
        }
        break;
        }
        if(c%1000==0){
            save(grid, c, M, N);
        }
        c++;
    }
//    std::cout<<"\n";
//    std::cout<<x<<" "<<y<<"\n";
//    std::cout<<ant_dir;
//    std::cout<<"\n";
//    for(auto i=0; i<M; i++){
//        for(auto j=0; j<N; j++){
//            std::cout<<grid[i+M*j];
//        }
//        std::cout<<"\n";
//    }


}
