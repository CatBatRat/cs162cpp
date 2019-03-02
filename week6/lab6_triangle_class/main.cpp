#include <iostream>
#include "triangle.hpp"

using namespace std;

int main()
{
    Triangle first;

    // show that default is properly built
    cout << "Default is 3,4,5 triangle, should be scalene and right" << endl
         << " for default a is " << first.getA() << " b is " << first.getB() << " c is " << first.getC() << endl
         << " default " << (first.isEquilateral() ? "is" : "is not") << " equalateral" << endl
         << " default " << (first.isScalene() ? "is" : "is not") << " scalene" << endl
         << " default " << (first.isIsosceles() ? "is" : "is not") << " isosceles" << endl
         << " default " << (first.isRight() ? "is" : "is not") << " right" << endl << endl;

    // test setter methods
    first.setA(2);
    first.setB(2);
    first.setC(3);
    cout << "Modified is 2,2,3 triangle, should be isosceles" << endl
         << " for modified a is " << first.getA() << " b is " << first.getB() << " c is " << first.getC() << endl
         << " modified " << (first.isEquilateral() ? "is" : "is not") << " equalateral" << endl
         << " modified " << (first.isScalene() ? "is" : "is not") << " scalene" << endl
         << " modified " << (first.isIsosceles() ? "is" : "is not") << " isosceles" << endl
         << " modified " << (first.isRight() ? "is" : "is not") << " right" << endl << endl;

    // test overloaded constructor
    Triangle second(4,4,4);
    cout << "Second is 4,4,4 triangle, should be equalateral and isosceles" << endl
         << " for second a is " << second.getA() << " b is " << second.getB() << " c is " << second.getC() << endl
         << " second " << (second.isEquilateral() ? "is" : "is not") << " equalateral" << endl
         << " second " << (second.isScalene() ? "is" : "is not") << " scalene" << endl
         << " second " << (second.isIsosceles() ? "is" : "is not") << " isosceles" << endl
         << " second " << (second.isRight() ? "is" : "is not") << " right" << endl << endl;
    //Triangle first;
    //cout << first.getA() << endl;

    return 0;
}
