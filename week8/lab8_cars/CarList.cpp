#include <iostream>
#include <string>
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

// destructor, deletes items, using recursion
CarList::~CarList()
{
    clearCars(bay);
}

// recursive method to walk down list, deleting items starting at tail
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
bool CarList::recFind(Garage * ptr, Car & fnd)
{
    if ( ptr == nullptr )
        return false;

    if (*ptr->car == fnd)
        return true;

    return recFind(ptr->next, fnd);
}

// creates a new car on heap
//creates new link
//adds link to head of list
void CarList::addCar( string make, string color, int year )
{
    Car * tempCar = new Car(make,color,year);
    Garage * tempLink = new Garage;
    tempLink->car = tempCar;
    tempLink->next = bay;
    bay = tempLink;
}

// look for a car on the list
// create an instance of it, use recursive method to see if there
bool CarList::findCar(string make, string color, int year)
{
    Car fnd(make,color,year);
    return recFind(bay, fnd);
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
std::string CarList::displayList()
{
    std::stringstream buffer;

        // start at the head
    Garage * ptr = bay;

        // until done with list
    while ( ptr )
    {
        buffer << *ptr->car << ", ";
        ptr = ptr->next;
    }

        // now return the string
    return buffer.str();
}

