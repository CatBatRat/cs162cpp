#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void recursiveSelection( int sorted[], int size, int select=0, int index=0 );

int main() {

    int sorted[] = { 5,3,8,7,2 };
    int size = sizeof(sorted)/sizeof(sorted[0]);
    cout << "The elements of sorted are\n";
    for ( int n=0; n<size; n++ )
        cout << " " << sorted[n] << " ";
    cout << endl;
    cout << "The size of sorted is " << size << endl;
    recursiveSelection( sorted, size );
    cout << "The final sorted list is" << endl;
    for ( int n=0; n<size; n++ )
        cout << " " << sorted[n] << " ";

    return 0;
}

void recursiveSelection( int sorted[], int size, int select, int index )
{

    // Find the smallest number.
    bool isSwap = false;
    int smallest = sorted[index];
    for ( int i=index; i<size; i++ )
    {
        if ( smallest > sorted[i] )
        {
            smallest = sorted[i];
            isSwap = true;
            select = i;
        }
    }
    if ( isSwap )
    {
        cout << "Swap " << sorted[index] << " with " << sorted[select] << endl;
        std::swap( sorted[index], sorted[select] );
        for ( int n=index; n<size; n++ )
            if ( n==index or n==select )
                cout << "[" << sorted[n] << "]";
            else
                cout << " " << sorted[n] << " ";
        cout << endl;
    }
    else
        cout << "No need to swap at index " << index << endl;
    if ( index < size-2 )
    {
        recursiveSelection( sorted, size, select, ++index );
    }
}
