#include <iostream>
#include "2darray.h"

template<typename T>
void Array<T>::print()
{
    for(auto i=0; i<length; i++){
        std::cout<<pa[i]<<" ";
    }
    std::cout<<"\n";
}

template<typename T>
T& Array<T>::operator[](int ind)
{
    T *new_ptr;
    if(ind >= length){
        new_ptr = new T[ind+1];
        for(auto i=0; i<length; i++){
            new_ptr[i] = pa[i];
        }
        for(auto i=length; i<=ind; i++){
            new_ptr[i]=0;
        }
        length = ind+1;
        delete[] pa;
        pa = new_ptr;
    }
    return pa[ind];
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> ob)
{
    T *new_ptr;
    if(length == ob.length){
        for(auto i=0; i<length; i++){
            pa[i] = ob.pa[i];
        }
    }
    else if(length > ob.length){
        new_ptr = new T[ob.length];
        for(auto i=0; i<ob.length; i++){
            new_ptr[i] = ob.pa[i];
        }
        delete[] pa;
        pa = new_ptr;
        length = ob.length;
    }
    else{
        new_ptr = new T[ob.length];
        for(auto i=0; i<ob.length; i++){
            new_ptr[i] = ob.pa[i];
        }
        delete[] pa;
        pa = new_ptr;
        length = ob.length;
    }

    return (*this);
}

template<typename T>
Array<T>& Array<T>::my_fill(T a)
{
    for(auto i=0; i<length; i++){
        pa[i] = a;
    }

    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(T x[])
{

    T *new_ptr;
    new_ptr = new T[length];

    for(auto i=0; i<length; i++){
        new_ptr[i]=x[i];
    }
    delete[] pa;
    pa = new_ptr;
    delete[] new_ptr;

    return (*this);
}

template<typename T>
int Array<T>::Get_size()
{
    return length;
}


int main()
{
    Array<double>v1(6);
    int size_v1=0;
    size_v1 = v1.Get_size();

    for (auto i=0; i < size_v1; ++i){
        v1[i] = i;
    }
    v1.print();

    Array<double>v2{v1};


    v2.print();
}
