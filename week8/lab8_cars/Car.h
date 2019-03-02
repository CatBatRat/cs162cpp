#include <string>

#ifndef __CARS__
#define __CARS__

using std::string;

class Car {
    string make;
    string color;
    int year;
public:
    Car();
    Car( string make, string color, int year );

    void   setMake( string make ) { this->make = make; }
    string getMake() { return make; }

    void   setColor( string color ) { this->color = color; }
    string getColor() { return color; }

    void   setYear( int year ) { this->year = year; }
    int getYear() { return year; }

    bool operator==( Car & test );
    friend std::ostream & operator<<( std::ostream & out, Car & o );
};

#endif //__CARS__
