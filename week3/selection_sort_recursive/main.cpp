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
    int smallest = sorted[index];
    for ( int i=index; i<size; i++ ) {
        if ( smallest > sorted[i] ) {
            smallest = sorted[i];
            select = i;
        }
    }
    if ( select > 0 ) {
        std::swap( sorted[index], sorted[select] );
    }
    if ( index < size-2 ) {
        recursiveSelection( sorted, size, select=-1, ++index );
    }
}
