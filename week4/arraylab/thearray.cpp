#include <iostream>
#include <iomanip>
#include "arraylab.hpp"

using namespace std;

int getSize()
{
    int size = 0;
    cout << "Please enter a number between 10 and 20\n"
         << "This will be the length of the list of\n"
         << "numbers to be sorted and searched." << endl;
    do
    {
        cout << "\nPlease enter your number.\n"
             << "It must be in the range 10 to 20" << endl;
        cin >> size;
        cin.clear();
        cin.ignore(1000000, '\n');
    } while( size < 10 or size > 20 );
    cout << "Setting size of the number list to " << size << endl;
    return size;
}

void fillArray( int unsorted[], int * size )
{
    for ( int l=0; l<*size; l++ )
    {
        *(unsorted+l) = rand() % 99 + 1;
    }
}

void displayArray( int tarray[], int * size )
{
    for ( int l=0; l<*size; l++ )
    {
        cout << *(tarray+l) << " ";
    }
    cout << endl;
}
