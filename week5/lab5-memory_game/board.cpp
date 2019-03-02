#include <iostream>
#include <random>
#include "memgame.hpp"

using namespace std;

void intro()
{
    cout << "Welcome to"
    R"(
  ____ ____ ____ _________ ____ ____ ____ ____ ____ ____
 ||T |||h |||e |||       |||M |||e |||m |||o |||r |||y ||
 ||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__||
 |/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|/__\|
  _________ ____ ____ ____ ____
 ||       |||G |||a |||m |||e ||
 ||_______|||__|||__|||__|||__||
 |/_______\|/__\|/__\|/__\|/__\| )" << "\n\n"

         << "All you have to do is select a card from the grid\n"
            "and try to find a match.\n\n"

            "To select a card simply input the row and column\n"
            "\"Y X\" and the game will tell you if they match.\n"
            "When you find all the matching cards, you WIN!\n\n"

            "Good luck!" << endl;
}

char * makeBoard( const Game & b )
{
    int size = b.size*b.size;
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
    cout << "Turns taken = " << b.tries << endl
         << "Matches made = " << b.matches << " of "
         << ( (b.size*b.size) / 2 ) - b.matches << endl;
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

void resetGame( Game & b )
{
        b.size = 4;
        b.last = -1;
        b.current = -1;
        b.tries = 0;
        b.matches = 0;
}
