#include <iostream>
#include "Vector.h"
#include <cmath>

Vector::Vector()
{}

Vector::Vector(double a, double b, double c)
:x(a),
y(b),
z(c)
{}

double Vector::amp()
{
    double amplitude = sqrt(pow((*this).x,2) + pow((*this).y,2) + pow((*this).z,2));
    return amplitude;

}

Vector Vector::operator+(Vector ob2)
{
    Vector ob3;
    ob3.x = (*this).x + ob2.x;
    ob3.y = (*this).y + ob2.y;
    ob3.z = (*this).z + ob2.z;

    return ob3;
}


Vector Vector::operator-(Vector ob2)
{
    Vector ob3;
    ob3.x = (*this).x - ob2.x;
    ob3.y = (*this).y - ob2.y;
    ob3.z = (*this).z - ob2.z;

    return ob3;
}


Vector Vector::operator*(double c)
{
    Vector new_ob;
    new_ob.x = (*this).x * c;
    new_ob.y = (*this).y * c;
    new_ob.z = (*this).z * c;

    return new_ob;
}


double Vector::operator*(Vector other_ob)
{
    return x*other_ob.x + y*other_ob.y + z*other_ob.z;
}


Vector Vector::operator&(Vector other_ob)
{
    Vector new_ob;

    new_ob.x = (y*other_ob.z - z*other_ob.y);
    new_ob.y = (z*other_ob.x - x*other_ob.z);
    new_ob.z = (x*other_ob.y - y*other_ob.x);

    return new_ob;
}


double Vector::angle(Vector ob2)
{

    return acos((*this)*ob2/((*this).amp() * ob2.amp()));

}


void Vector::print()
{
    std::cout<<"("<<x<<", "<<y<<", "<<z<<")\n";
}


Vector::~Vector()
{
    //std::cout<<"\n"<<"\n"<<"I am the Destructor"<<"\n"<<"I will DESTROY!!";
}
