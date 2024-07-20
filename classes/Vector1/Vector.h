#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
    public:
        Vector();
        Vector(double, double, double);
        void print();
        double amp();
        Vector operator*(double);
        double operator*(Vector);
        Vector operator&(Vector);
        double angle(Vector);
        Vector operator+(Vector);
        Vector operator-(Vector);

        ~Vector();

    private:
        double x,y,z;
};

#endif // VECTOR_H
