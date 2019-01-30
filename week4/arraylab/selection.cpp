#include "arraylab.hpp"


void recSelectionSort( int sorted[], int * size, int index )
{
    int select = findSmallest( sorted, *size, index );
    if ( select > 0 )
    {
        swapper( sorted+index, sorted+select );
    }
    if ( index < *size-2 )
    {
        recSelectionSort( sorted, size, ++index );
    }
}

int findSmallest( int numset[], int size, int index )
{
    int smallest = numset[index], foundat = -1;
    for ( int i=index; i<size; i++ )
    {
        if ( smallest > numset[i] )
        {
            smallest = numset[i];
            foundat = i;
        }
    }
    return foundat;
}

void swapper( int * left, int * right )
{
    int temp = *left;
    *left = *right;
    *right = temp;
}
