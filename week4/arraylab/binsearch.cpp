#include <iostream>
#include "arraylab.hpp"

using std::cout;
using std::endl;

bool binSearch( int searched[], int size, int fnd, int index )
{
    if ( index <= size )
    {
        cout << "search" << endl;
        int mid = ( index+(size) ) / 2;
        if ( *(searched+mid) == fnd )
            return true;
        else if ( fnd < *(searched+mid) )
            return binSearch( searched, mid-1, fnd, index );
        else
            return binSearch( searched, size, fnd, mid+1 );
    }
    return false;
}
