#include <iostream>
#include <iomanip>
#include "arraylab.hpp"

using namespace std;

int getSize()
{
    int size = 0;
    cout << "Please enter a number between " << AMIN << " and " << AMAX << "\n"
         << "This will be the length of the list of\n"
         << "numbers to be sorted and searched." << endl;
    do
    {
        cout << "\nPlease enter your number.\n"
             << "It must be in the range " << AMIN << " to " << AMAX << endl;
        cin >> size;
        cin.clear();
        cin.ignore(1000000, '\n');
    } while( size < AMIN or size > AMAX );
    cout << "Setting size of the number list to " << size << "\n\n";
    return size;
}

int * makeArray( int * size )
{
    int *arr = new int[*size];
    for ( int l=0; l<*size; l++ )
    {
        *(arr+l) = rand() % RMAX + RMIN;
    }
    return arr;
}

void displayArray( int arr[], int * size, int line )
{
    int count = 0;
    for ( int l=0; l<*size; l++ )
    {
        // I was using a modulo operator here, but I realized how expensive
        // this can be in a large list, so I changed it to an increment count.
        if( count++ >= line )
        {
            count = 1;
            cout << endl;
        }
        cout << setw(3) << right << *(arr+l);
    }
    cout << "\n\n";
}
