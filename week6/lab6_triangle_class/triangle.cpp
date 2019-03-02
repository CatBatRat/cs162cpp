#include "triangle.hpp"

void Triangle::setA( int A )
{
    sideA = A;
}
void Triangle::setB( int B )
{
    sideB = B;
}
void Triangle::setC( int C )
{
    sideC = C;
}
int Triangle::getA()
{
    return sideA;
}
int Triangle::getB()
{
    return sideB;
}
int Triangle::getC()
{
    return sideC;
}
bool Triangle::isEquilateral()
{
    if( getA() == getB() and getA() == getC() )
        return true;
    return false;
}
bool Triangle::isIsosceles()
{
    if( getA() == getB() or getB() == getC() or getC() == getA() )
        return true;
    return false;
}
bool Triangle::isScalene()
{
    //if( getA() != getB() and getA() != getC() and getB() != getC() )
    if( !isIsosceles() )
        return true;
    return false;
}
bool Triangle::isRight()
{
    if( getA()*getA() + getB()*getB() == getC() * getC() )
        return true;
    if( getA()*getA() + getC()*getC() == getB() * getB() )
        return true;
    if( getB()*getB() + getC()*getC() == getA() * getA() )
        return true;
    return false;
}
