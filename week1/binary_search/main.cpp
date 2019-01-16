#include <iostream>

using namespace std;

const int SIZE = 10;

int main()
{
    int squares[SIZE];

    for( int x=0; x<SIZE; x++ ) {
        squares[x] = (x+1) * (x+1);
    }

    for( int x=0; x<SIZE; x++ ) {
        cout << squares[x] << " ";
    }

}
