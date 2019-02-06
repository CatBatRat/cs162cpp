#include "arraylab.hpp"


void iterSelectionSort( int * arr, int * size )
{
    int select = 0;
    for( int o=0; o<*size-1; o++ )
    {
        select = findSmallest( arr, *size, o );
        if ( select > 0 )
        {
            swapper( arr+o, arr+select );
        }
    }
}

/*void recSelectionSort( int * arr, int * size, int index )
{
    int select = findSmallest( arr, *size, index );
    if ( select > 0 )
    {
        swapper( arr+index, arr+select );
    }
    if ( index < *size-2 )
    {
        recSelectionSort( arr, size, ++index );
    }
}*/

int findSmallest( int * numset, int size, int index )
{
    // Set foundat to 0 to start. This acts as a false if there is no smaller
    // number found because, even if the lowest is at index 0, there would be
    // no need to swap.
    int smallest = *(numset+index), foundat = 0;
    for ( int i=index; i<size; i++ )
    {
        if ( smallest > *(numset+i) )
        {
            smallest = *(numset+i);
            foundat = i;
        }
    }
    // Return just the index where the value is found. This can be used in the
    // swapper later.
    return foundat;
}

void swapper( int * left, int * right )
{
    // Bitwise XOR to swap values. At least I understand what is happing here
    // since taking math 82
    *left ^= *right;
    *right ^= *left;
    *left ^= *right;
}
