#include <iostream>
#include "2darray.h"

template<typename T>
void 2darray<T>::print()
{
    for(auto i=0; i<lines; i++){
        for(auto j=0; j<columns; j++){
            std::cout<<ptr[i*columns+j]
        }
        std::cout<<"\n";
    }
}

int main()
{

}
