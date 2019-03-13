#include <iostream>
#include <string>
#include <sstream>
#include "CarList.h"

using std::string;

//
//  StructList.cpp
//  List_of_Cars
//
//  Created by Jim Bailey on 2/17/18.
//  Copyright © 2018 jim. All rights reserved.
//

#include <sstream>

// constructor, defines head
CarList::CarList()
{
    bay = nullptr;
}

// Calls recursive function clearCars()
CarList::~CarList()
{
    clearCars(bay);
}

// Recursively crushes all cars in Garage Before the garage gets burned down.
void CarList::clearCars(Garage * cars)
{
    if ( cars )
    {
        clearCars(cars->next);
        delete cars->car;
        delete cars;
    }
}

// recursive method to search the list
// uses overloaded equality operator in Car
bool CarList::recFind(const Garage * car, const Car & fcar) const
{
    if ( car == nullptr )
        return false;

    if (*(car)->car == fcar)
        return true;

    return recFind(car->next, fcar);
}

// creates a new car on heap
// creates new link
// adds link to head of list
void CarList::addCar( string make, string color, int year )
{
    Car * tempCar = new Car(make,color,year);
    Garage * tempLink = new Garage;
    tempLink->car = tempCar;
    tempLink->next = bay;
    bay = tempLink;
}

// look for a car on the list, create an instance of it, use recursive recFind
// to return the result.
bool CarList::findCar(string make, string color, int year)
{
    Car fcar(make,color,year);
    return recFind(bay, fcar);
}

// remove the item at head and return its value
Car * CarList::removeHead()
{
    // deal with empty list
    if ( bay == nullptr )
        return nullptr;
    // non-empty, so get first item and process
    Garage * tempLink = bay;
    Car * car = tempLink->car;
    // update head
    bay = bay->next;
    // delete old link
    delete tempLink;
    // return the value
    return car;
}

// build a sring  by walking down the list
// uses overloaded extraction operator in Car
string CarList::displayList()
{
    std::stringstream buffer;

        // start at the head
    Garage * ptr = bay;

        // until done with list
    while ( ptr )
    {
        buffer << *(ptr)->car << ", ";
        ptr = ptr->next;
    }

        // now return the string
    return buffer.str();
}

// Optionally add more cars to list based on user input.
// Uncomment ADDITIONAL_CARS define in main.cpp to use.
void CarList::moreCars( string m, string c, int y )
{
    bool more = false;
    string input = "";
    do {
        std::stringstream out;
        std::cout << "\nIf you would like to add any additional cars\n"
                     "please do so now.\n"
                     "Leave blank to continue with the current/new\n"
                     "contents of the list.\n"
                     "New cars should be in the format:\n"
                     "\n<Make>, <Color>, <Year>"<< std::endl;
        std::getline( std::cin, input );
        out << input;
        out >> m;
        if( input != "" ){
            out >> c >> y;
            if( y ) {
                addCar(m,c,y);
            }
            else {
                std::cout << "Invalid input. Please try again."
                    << std::endl;
            }
        }
        else
            more = true;
        input = "";
    } while( !more );
}
