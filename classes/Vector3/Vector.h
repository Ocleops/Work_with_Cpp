#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector
{
    public:
        Vector(T a, T b, T c);
        void print();


    private:
        T x,y,z;
};

#endif // VECTOR_H
