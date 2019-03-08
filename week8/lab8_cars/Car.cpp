#include <string>
#include <iostream>
#include "Car.h"

using std::string;

Car::Car():
    make("Ford"), color("Black"), year(1910) {}
Car::Car( string make, string color, int year )
{
    setMake(make);
    setColor(color);
    setYear(year);
}

bool Car::operator==( const Car & t ) const
{
    if( t.make == make and t.color == color and t.year == year )
        return true;
    return false;
}

std::ostream & operator<<( std::ostream & out, const Car & o )
{
    out << o.year << " " << o.color << " " << o.make;
    return out;
}
