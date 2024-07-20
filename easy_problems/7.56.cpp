#include <iostream>
#include <vector>

std::vector<int> RemovePlaces(std::vector<int>& board, int line, int col,int N)
{
    const int x=col, y=line;
    while(line >=0 ){
        if(board[line+N*col] >= 22){
            line += -1;
        }
        else{
            board[line + N*col] += 1;
            line += -1;
        }
    }
    line = y;
    while(line<N){
        if(board[line+N*col] >= 22){
            line += 1;
        }
        else{
            board[line+N*col] += 1;
            line += 1;
        }
    }
    line = y;
    while(col >=0){
        if(board[line + N*col] >= 22){
            col += -1;
        }
        else{
            board[line + N*col] += 1;
            col += -1;
        }
    }
    col = x;
    while(col < N){
        if(board[line + N*col] >= 22){
            col += 1;
        }
        else{
            board[line + N*col] += 1;
            col += 1;
        }
    }
    col = x;
    while(col >=0 && line >= 0){
        if(board[line+N*col] >= 22){
            col += -1;
            line += -1;
        }
        else{
            board[line+N*col] += 1;
            col += -1;
            line += -1;
        }
    }
    col = x;
    line = y;
    while(col < N && line < N){
        if(board[line + N*col] >= 22){
            col += 1;
            line += 1;
        }
        else{
            board[line + N*col] += 1;
            col += 1;
            line += 1;
        }
    }
    col = x;
    line = y;
    while(col < N && line >= 0){
        if(board[line+N*col] >= 22){
            line += -1;
            col += 1;
        }
        else{
            board[line+N*col] += 1;
            line += -1;
            col += 1;
        }
    }
    col = x;
    line = y;
    while(col >= 0 && line < N ){
        if(board[line+N*col] >= 22){
            line += 1;
            col += -1;
        }
        else{
            board[line+N*col] += 1;
            line += 1;
            col += -1;
        }
    }
    line = y;
    col = x;


    return board;
}

std::vector<int> UnremovePlaces(std::vector<int>& board, int line, int col,int N)
{
    const int x=col, y=line;
    while(line >=0 ){
        if(board[line+N*col] >= 22){
            line += -1;
        }
        else{
            board[line + N*col] += -1;
            line += -1;
        }
    }
    line = y;
    while(line<N){
        if(board[line+N*col] >= 22){
            line += 1;
        }
        else{
            board[line+N*col] += -1;
            line += 1;
        }
    }
    line = y;
    while(col >=0){
        if(board[line + N*col] >= 22){
            col += -1;
        }
        else{
            board[line + N*col] += -1;
            col += -1;
        }
    }
    col = x;
    while(col < N){
        if(board[line + N*col] >= 22){
            col += 1;
        }
        else{
            board[line + N*col] += -1;
            col += 1;
        }
    }
    col = x;
    while(col >=0 && line >= 0){
        if(board[line+N*col] >= 22){
            col += -1;
            line += -1;
        }
        else{
            board[line+N*col] += -1;
            col += -1;
            line += -1;
        }
    }
    col = x;
    line = y;
    while(col < N && line < N){
        if(board[line + N*col] >= 22){
            col += 1;
            line += 1;
        }
        else{
            board[line + N*col] += -1;
            col += 1;
            line += 1;
        }
    }
    col = x;
    line = y;
    while(col < N && line >= 0){
        if(board[line+N*col] >= 22){
            line += -1;
            col += 1;
        }
        else{
            board[line+N*col] += -1;
            line += -1;
            col += 1;
        }
    }
    col = x;
    line = y;
    while(col >= 0 && line < N ){
        if(board[line+N*col] >= 22){
            line += 1;
            col += -1;
        }
        else{
            board[line+N*col] += -1;
            line += 1;
            col += -1;
        }
    }
    line = y;
    col = x;


    return board;
}


int main ()
{
    int N=4, col=0, line = 0;
    std::vector<int>board(N*N);
    std::vector<int> column(N);
    for(auto i=0; i<column.size(); i++){
        column[i] = -1;
    }
    int i=0, j=0, c=0;
//    while(line <= N){
//        if(board[i + N*j] == 0 && j > column[i]){
//            board = RemovePlaces(board, i, j, N);
//            board[i+N*j] = 22;
//            column[i] = j;
//            i += 1;
//            line += 1;
//            j = 0;
//        }
//        else if(j < N){
//            j += 1;
//        }
//        else if(j == N){
//            i += -1;
//            j = column[i];
//            board = UnremovePlaces(board, i, j, N);
//            board[i + N*j] = 0;
//        }
//        if(c==23){
//            std::cout<<i<<" "<<j<<" "<<column[i]<<"\n";
//            break;
//        }
//        c += 1;
//    }

    board[0+0*N] = 22;
    board = RemovePlaces(board, 0, 0, N);
    board = UnremovePlaces(board, 0, 0, N);
    board[0 + 0*N] = 0;


    for(auto i=0; i<N; i++){
        for(auto j=0; j<N; j++){
            std::cout<<board[i+N*j]<<"\t";
        }
        std::cout<<"\n";
    }

//    for(auto i=0; i<column.size(); i++){
//        std::cout<<column[i];
//    }

}
