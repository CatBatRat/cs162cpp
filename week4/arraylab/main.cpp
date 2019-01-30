#include <iostream>
#include <random>
#include "arraylab.hpp"

using namespace std;

int main() {

    srand(static_cast<int>(time(nullptr)));

    int size = getSize();
    int *tarray = new int[size];
    fillArray( tarray, &size );
    cout << "The array before sorting is:\n";
    displayArray( tarray, &size );
    recSelectionSort(tarray, &size);
    cout << "The array after sorting is:\n";
    displayArray( tarray, &size );
    int input;
    do
    {
        cin >> input;
        cin.clear();
        cin.ignore(1000000, '\n');
        if( input != 0 )
        {
            if ( binSearch( tarray, size, input ) )
                cout << "Found the number you are looking for." << endl;
            else
                cout << "That number is not in the array." << endl;
        }
    } while( input != 0 );
    delete[] tarray;

    return 0;
}

