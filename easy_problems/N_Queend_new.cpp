#include <iostream>
#include <vector>

void occupy(std::vector<int> & board, int i, int j, int N)
{
    const int x=j, y=i;
    while(j>=0){
        if(j != x){
            board[i + N*j] += 1;
        }
        j += -1;
    }
    j = x;
    i = y;
    while(j<N){
        if(j != x){
            board[i + N*j] += 1;
        }
        j += 1;
    }
    j = x;
    i = y;
    while(i >= 0){
        if(i != y){
            board[i + N*j] += 1;
        }
        i += -1;
    }
    j = x;
    i = y;
    while(i < N){
        if(i != y){
            board[i + N*j] += 1;
        }
        i += 1;
    }
    j = x;
    i = y;
    while(i >= 0 && j >= 0){
        if(i != y && j != x){
            board[i+N*j] += 1;
        }
        i += -1;
        j += -1;
    }
    j = x;
    i = y;
    while(i<N && j<N){
        if(i != y && j != x){
            board[i+N*j] += 1;
        }
        i += 1;
        j += 1;
    }
    j = x;
    i = y;
    while(i<N && j>=0){
        if(i != y && j != x){
            board[i+N*j] += 1;
        }
        i += 1;
        j += -1;
    }
    j = x;
    i = y;
    while(i>=0 && j<N){
        if( i != y && j != x){
            board[i+N*j] += 1;
        }
        j += 1;
        i += -1;
    }
}

void permit(std::vector<int> & board, int i, int j, int N)
{
    const int x=j, y=i;
    while(j>=0){
        if(j != x){
            board[i + N*j] += -1;
        }
        j += -1;
    }
    j = x;
    i = y;
    while(j<N){
        if(j != x){
            board[i + N*j] += -1;
        }
        j += 1;
    }
    j = x;
    i = y;
    while(i >= 0){
        if(i != y){
            board[i + N*j] += -1;
        }
        i += -1;
    }
    j = x;
    i = y;
    while(i < N){
        if(i != y){
            board[i + N*j] += -1;
        }
        i += 1;
    }
    j = x;
    i = y;
    while(i >= 0 && j >= 0){
        if(i != y && j != x){
            board[i+N*j] += -1;
        }
        i += -1;
        j += -1;
    }
    j = x;
    i = y;
    while(i<N && j<N){
        if(i != y && j != x){
            board[i+N*j] += -1;
        }
        i += 1;
        j += 1;
    }
    j = x;
    i = y;
    while(i<N && j>=0){
        if(i != y && j != x){
            board[i+N*j] += -1;
        }
        i += 1;
        j += -1;
    }
    j = x;
    i = y;
    while(i>=0 && j<N){
        if( i != y && j != x){
            board[i+N*j] += -1;
        }
        j += 1;
        i += -1;
    }
}
int main ()
{
    int N=7;
    std::vector<int> board(N*N);
    std::vector<int> column(N);
    for(auto n=0; n<N; n++){
        column[n] = - 1;
    }

    int i=0, j=0, c=0;
    while(i<N){
        if(board[i + j*N] == 0 && j != column[i]){
            occupy(board, i, j, N);
            board[i + j*N] = 22;
            column[i] = j;
            i += 1;
            j=0;
        }
        else if(j < N){
            j += 1;
        }
        else{
            i += -1;
            j = column[i];
            permit(board, i, j, N);
            board[i + N*j] = 0;
        }
    }

    for(auto i=0; i<N; i++){
        for(auto j=0; j<N; j++){
            std::cout<<board[i+N*j]<<"\t";
        }
        std::cout<<"\n";
    }
}
