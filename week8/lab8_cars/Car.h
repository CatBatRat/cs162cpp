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

    // Simple setters and getters for: make, color, and year.
    void   setMake( string make ) { this->make = make; }
    string getMake() { return make; }
    void   setColor( string color ) { this->color = color; }
    string getColor() { return color; }
    void   setYear( int year ) { this->year = year; }
    int    getYear() { return year; }

    // Comparison operator==() to handle comparison of the contents of one Car
    // to another.
    bool operator==( const Car & test ) const;

    // ostream function to output the current values in Car when used a part of
    // a cout statement.
    friend std::ostream & operator<<( std::ostream & out, const Car & o );
};

#endif //__CARS__
