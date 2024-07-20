#include <iostream>
#include "Array2d.h"

template<typename T>
void Array2d<T>::print()
{
    for(auto i=1; i<=lines; i++){
        for(auto j=1; j<=columns; j++){
            std::cout<<ptr[i*columns+j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

template<typename T>
T& Array2d<T>::operator()(int a, int b)
{
    if(a>lines || b>columns){
        throw std::invalid_argument("This element is out of bounds!");
    }
    else{
        return ptr[a*columns + b];
    }


}

template<typename T>
Array2d<T>& Array2d<T>::operator=(Array2d<T> & other)
{
    lines = other.lines;
    columns = other.columns;

    T *new_ptr;
    new_ptr = new T[columns*lines];
    for(auto i=0; i<lines; i++){
        for(auto j=0; j<columns; j++){
            new_ptr[(i+1)*columns + (j+1)] = other.ptr[(i+1)*columns + (j+1)];
        }
    }

    ptr = new_ptr;

    return *this;

}

template<typename T>
int Array2d<T>::size()
{
    int c=0;

    for(auto i=0; i<lines; i++){
        for(auto j=0; j<lines; j++){
            c += 1;
        }
    }
    return c;
}

template<typename T>
int Array2d<T>::dim(int a)
{
    if(a==1){
        return lines;
    }
    else if(a==2){
        return columns;
    }
    else{
        throw std::invalid_argument("Arrays are 2 dimensional. Select dimension 1 or 2.");
    }
}

int main()
{
    Array2d<int> v1(3,4);
    v1.print();
    Array2d<int> v2;
    v2=v1;

    std::cout<<v2.dim(3);


}
