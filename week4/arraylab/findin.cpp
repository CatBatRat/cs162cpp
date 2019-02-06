#include <iostream>
#include "arraylab.hpp"

using namespace std;

bool binSearch( int * arr, int size, int fnd, int index )
{
    // Remember to use <= so the first item in the array is not left out if it
    // is the last result.
    if ( index <= size )
    {
        int mid = ( index+size ) / 2;
        if ( *(arr+mid) == fnd )
            return true;
        else if ( fnd < *(arr+mid) )
            // Send size as mid-1 becaus this loation has aready been checked,
            // so there is no need to include it in the next search.
            return binSearch( arr, mid-1, fnd, index );
        else
            return binSearch( arr, size, fnd, mid+1 );
    }
    return false;
}

void findInArray( int *arr, int *size )
{
    int input;
    cout << "You may now input 3 numbers and have them checked to\n"
            "see if they are present in the list of sorted numbers.\n" << endl;
    for( int l=0; l<LOOPS; l++ )
    {
        cin >> input;
        cin.clear();
        cin.ignore(1000000, '\n');
        if( input != 0 )
        {
            if ( binSearch( arr, *size, input ) )
                cout << input << " is in the list." << endl;
            else
                cout << input << " is not in the list." << endl;
        }
        else
        {
            cout << "Now exiting.";
            break;
        }
    }
}
