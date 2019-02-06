#include <iostream>
#include <random>
#include "arraylab.hpp"

using namespace std;

int main() {

    // static_cast because time gives an unsigned int but srand wants an int.
    srand(static_cast<int>(time(0)));

    int size = getSize();

    // Create a pointer to the address of a new array created in makeArray().
    int * tarray = makeArray( &size );

    cout << "The list before sorting is:\n";
    displayArray( tarray, &size, 5 );

    // Sort the array.
    iterSelectionSort(tarray, &size);

    cout << "The list after sorting is:\n";
    displayArray( tarray, &size, 5 );

    // Prompt user for input data to search for.
    findInArray( tarray, &size );

    // Always delete the block of memory when done with it.
    delete[] tarray;

    return 0;
}
