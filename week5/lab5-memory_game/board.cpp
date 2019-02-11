#include <iostream>
#include <random>
#include "memgame.hpp"

using namespace std;

char * makeBoard( const Game & b )
{
    int size = b.size*b.size;
    //char CARDS[] = { '&','$','#','@','?','%','!','+' };
    char * temp = new char[size];
    for( int d=0; d<=size; d++ )
    {
        temp[d] = '0';
    }
    for( int i=0; i<size/2; i++ )
    {
        for( int t=0; t<2; t++ )
        {
            bool filled = false;
            while( !filled )
            {
                int rFill = rand() % size;
                if( temp[rFill] == '0' )
                {
                    temp[rFill] = CARDS[i % CARDNUM];
                    filled = true;
                }
            }
        }
    }
    return temp;
}

bool * makeChecked( const Game & b )
{
    bool * temp = new bool[b.size*b.size];
    for( int i=0; i<b.size*b.size; i++ )
        temp[i] = 0;
    return temp;
}

void displayBoard( Game & b )
{
    // Output 10000 blank lines (Longer than the scroll-back buffer of most
    // terminals) so the player's memory is actually tested.
    for( int i=0; i<5000; i++ )
        cout << '\n';
    cout << "   ";
    // Numbers for each column.
    for( int n=0; n<b.size; n++ )
        cout << " " << n+1 << " ";
    cout << endl;
    for( int y=0; y<b.size; y++ )
    {
        cout << " " << y+1 << " ";
        for( int x=0; x<b.size; x++ )
        {
            // Somehow I find working with flattened arrays easier than
            // standard 2d arrays. While it is a bit more typing, the formula
            // is simple, and storing the index of an item only needs one
            // variable. In addition, filling the array with random numbers, or
            // all one value, only takes a single for loop. Same goes for
            // searching and sorting.
            if( b.checked[y + x * b.size] )
                cout << "{" << b.grid[y + x * b.size] << "}";
            else if( b.last == (y+x*b.size) or b.current == (y+x*b.size) )
                cout << "(" << b.grid[y + x * b.size] << ")";
            else
                cout << "[*]";
        }
        cout << endl;
    }
}

void cinClear()
{
    cin.clear();
    cin.ignore(BIG_NUM, '\n');
}
