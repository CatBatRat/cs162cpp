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
    bool recFind(Garage * ptr, Car & fnd);
    void clearCars(Garage * cars);
    //void recDestruct(Garage * ptr);
public:
    CarList();
    ~CarList();
    void addCar( string make, string color, int year );
    string displayList();
    Car * removeHead();
    bool findCar(string make, string color, int year);
};

#endif // __CAR_LIST__
