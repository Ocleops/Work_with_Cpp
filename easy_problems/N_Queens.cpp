#include<iostream>
#include<vector>


void forbiden(auto b, int line, int col,int N)
{
    int c=0;
    for(auto i=0; i<N; i++){
        for(auto j=0; j<N; j++){
            if(i==line){
                std::advance(b,i+N*j);
                *b += 1;
                std::advance(b,-(i+N*j) );
            }
            if(j==col){
                std::advance(b,i+N*j);
                *b +=1;
                std::advance(b,-(i+N*j) );
            }
        }
    }

    int i=line,j=col;
    while(i<N && j<N){
        std::advance(b, i+N*j);
        *b += 1;
        std::advance(b, -(i+N*j) );
        i++;
        j++;
    }

    i=line;
    j=col;
    while(i>=0 && j>= 0){
        std::advance(b, i+N*j);
        *b += 1;
        std::advance(b, -(i+N*j) );
        i--;
        j--;
    }
    i=line;
    j=col;
    while(i>=0 && j<N){
        std::advance(b, i+N*j);
        *b += 1;
        std::advance(b, -(i+N*j) );
        i--;
        j++;
    }

    i=line;
    j=col;
    while(i<N && j>=0){
        std::advance(b, i+N*j);
        *b += 1;
        std::advance(b, -(i+N*j) );
        i++;
        j--;
    }
}

void allow(auto b, int line, int col,int N)
{
    int c=0;
    for(auto i=0; i<N; i++){
        for(auto j=0; j<N; j++){
            if(i==line){
                std::advance(b,i+N*j);
                *b += -1;
                std::advance(b,-(i+N*j) );
            }
            if(j==col){
                std::advance(b,i+N*j);
                *b += -1;
                std::advance(b,-(i+N*j) );
            }
        }
    }

    int i=line,j=col;
    while(i<N && j<N){
        std::advance(b, i+N*j);
        *b += -1;
        std::advance(b, -(i+N*j) );
        i++;
        j++;
    }

    i=line;
    j=col;
    while(i>=0 && j>= 0){
        std::advance(b, i+N*j);
        *b += -1;
        std::advance(b, -(i+N*j) );
        i--;
        j--;
    }
    i=line;
    j=col;
    while(i>=0 && j<N){
        std::advance(b, i+N*j);
        *b += -1;
        std::advance(b, -(i+N*j) );
        i--;
        j++;
    }

    i=line;
    j=col;
    while(i<N && j>=0){
        std::advance(b, i+N*j);
        *b += -1;
        std::advance(b, -(i+N*j) );
        i++;
        j--;
    }
}


int main()
{
    int N=4;
    int line=0,col=0;
    std::vector<int> grid(N*N);
    std::vector<int> column(N);

    for(auto i=0; i<N; i++){
            for(auto j=0; j<N; j++){
                grid[i+j*N] = 0;
            }
        }


    for(auto i=0; i<N; i++){
        column[i]=-1;
    }

    auto b = grid.begin();

    int i=0;
    int j=0;



    while(line<N){
        if(grid[i+N*j]==0 &&  j != column[i]){
            forbiden(b,i,j,N);
            column[i]=j;
            i++;
            line++;
            j=0;
        }
        else if(j<N){
            j++;
        }
        else{
            if(i>0){
                line--;
                i--;
                j=column[i];
                allow(b,i,j,N);
                j++;
            }
            else{
                std::cout<<"error\n"<<i<<" "<<j<<"\n";
            }
        }
    }

    for(auto i=0; i<N; i++){
            for(auto j=0; j<N; j++){
                grid[i+j*N] = 0;
            }
        }

    for(auto i=0; i<N; i++){
        grid[i+column[i]*N] += 1;
    }


    for(auto i=0; i<N; i++){
        for(auto j=0; j<N; j++){
            if(grid[i+j*N]==1){
                std::cout<<"Q";
            }
            else{
                std::cout<<"-";
            }
        }
        std::cout<<"\n";
    }



}
