#include <string>

#ifndef __CAR_LIST__
#define __CAR_LIST__

#include "Car.h"

using std::string;

struct Garage {
    Garage * next;
    Car * car;
};

class CarList {
    Garage * bay;
    bool recFind(const Garage * ptr, const Car & fnd) const;
    void clearCars(Garage * cars);
public:
    CarList();
    ~CarList();
    void addCar( string make, string color, int year );
    void moreCars( string m = "", string c = "", int y = 0 );
    string displayList();
    Car * removeHead();
    bool findCar(string make, string color, int year);
};

#endif // __CAR_LIST__
