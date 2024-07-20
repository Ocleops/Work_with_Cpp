#include <iostream>
#include "Vector.h"
#include <cmath>

template <typename T>
Vector<T>::Vector(T a, T b, T c)
{
    x=a;
    y=b;
    z=c;
}

template <typename T>
void Vector<T>::print()
{
    std::cout<<x<<" "<<y<<" "<<z;
}
