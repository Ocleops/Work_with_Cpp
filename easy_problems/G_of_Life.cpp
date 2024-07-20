#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

void save(std::vector<int> &grid, int a)
{
    std::ostringstream name;
    name<<"GL_version_"<<a<<".pbm";
    std::ofstream output1(name.str());
    output1<<"P1\n"<<"512 512\n";
    for(auto i=0;i<512;i++){
        for(auto j=0; j<512; j++){
            output1<<grid[i+512*j]<<"\n";
        }
    }

}

int main()
{
    std::ofstream output ("GL.pbm");
    int M=512,N=512;
    output<<"P1\n"<<M<<" "<<N<<"\n";
    std::vector<int> grid(M*N);
    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            grid[i+M*j] = 0;
        }
    }
    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            if(i==j){
                grid[i+1+M*j]++;
                grid[i-1+M*j]++;
            }
        }
    }
    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            if(M-1-i==(N-1-j)){
                if(grid[i+1+M*(N-1-j)]!=1){
                    grid[i+1+M*(N-1-j)]++;
                }
                if(grid[i-1+M*(N-1-j)]!=1){
                    grid[i-1+M*(N-1-j)]++;
                }
            }
        }
    }

    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            output<<grid[i+M*j]<<"\n";
        }
    }




//------------------------------------------------------------------Initial Conditions and print

    int counter=0;
    std::vector<int> new_grid(M*N);
    for(auto i=0; i<M; i++){
        for(auto j=0; j<N; j++){
            new_grid[i+M*j] = grid[i+M*j];
        }
    }

    int c=0,a=0;
    while(c<1000){
        for(auto i=0; i<M; i++){
            for(auto j=0; j<N; j++){
                counter = 0;
                for(auto k=i-1; k<=i+1; k++){
                    if(k<0 || k>= M){
                        continue;
                    }
                    for(auto n=j-1; n<=j+1; n++){
                        if(n<0 || n>=N){
                            continue;
                        }
                        if(i==k && j==n){
                            continue;
                        }
                        if(grid[k+M*n]==1){
                            //std::cout<<i<<" "<<j<<" "<<k<<" "<<n<< "\n";
                            counter++;
                        }
                    }
                }
                if(counter==3){
                    //std::cout<<"geia\n";
                    new_grid[i+j*M] = 1;
                }
                else if(counter==2 && grid[i+M*j]==1){
                    new_grid[i+j*M] = 1;
                }
                else if(counter==2 && grid[i+M*j]==0){
                    new_grid[i+j*M] = 0;
                }
                else{
                    new_grid[i+j*M] = 0;
                }
            }
        }

        for(auto i=0; i<M; i++){
            for(auto j=0; j<N; j++){
                grid[i+M*j] = new_grid[i+M*j];
            }
        }
        c++;
        if(c%100==0){
            save(grid,a);
            a++;
        }
    }








//    for(auto i=0; i<M; i++){
//        for(auto j=0; j<N; j++){
//            std::cout<<grid[i+M*j];
//        }
//        std::cout<<"\n";
//    }
//    std::cout<<"\n"<<c;

}
