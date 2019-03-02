#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include "memgame.hpp"

using namespace std;

void getSize( Game & b )
{
    cout << "Enter the size of the board or "
        "type 0 to use the default." << endl;
        int size;
        cin >> size;
        cinClear();
        if( size > 1 and size % 2 == 0 )
            b.size = size;
        else if( size == 0 )
        {
            cout << "Using default size of 4." << endl;
            waitEnter();
        }
        else
        {
            cout << "Must select a number that will result in an\n"
                    "even number of cards.\n"
                    "defaulting to 4." << endl;
            waitEnter();
        }
}

void getMove( Game & b )
{
    int y = 0, x = 0;
    cin >> y;
    if( y == 0 )
        gameExit( b );
    cin >> x;
    cinClear();
    while( y<1 or y>b.size or x<1 or x>b.size ) {
        cout << "That is not in the range of the board." << endl
             << "Please input a value from 1 to " << b.size << endl
             << "Try again." << endl;
        cin >> y >> x;
        cinClear();
    }
    if( b.last == -1 )
        b.last = (y-1) + (x-1) * b.size;
    else
        b.current = (y-1) + (x-1) * b.size;
}

void checkMove( Game & b )
{
    cout << b.size << endl;
    if( b.checked[b.last] or b.checked[b.current] )
    {
        cout << "You have already picked cards at these locations." << endl;
        cout << "Try again." << endl;
    }
    else if( b.last == b.current )
            cout << "What are you trying to pull?\n"
                    "That's the same card twice!" << endl;
    else if( b.grid[b.last] == b.grid[b.current] )
    {
        displayBoard( b );
        cout << "Those cards match!" << endl;
        b.checked[b.last] = true;
        b.checked[b.current] = true;
        b.matches += 1;
    }
    else
    {
        displayBoard( b );
        cout << "Those cards do not match... sorry." << endl;
    }
    b.last = -1;
    b.current = -1;
    b.tries += 1;
    waitEnter();
}

bool checkWin( Game & b )
{
    bool win = false;
    if( b.matches >= (b.size*b.size) / 2 )
        win = true;
    return win;
}

bool playAgain( Game & b )
{
    char play = 'n';
    cout << "Would you like to play again?\n"
            "yes/no : ";
    cin >> play;
    if( play == 'y' )
    {
        resetGame( b );
        return true;
    }
    else
        cout << "Game ended, you may now close the window." << endl;
    return false;
}

void waitEnter()
{
    string enter = "";
    cout << "Press enter to continue." << endl;
    getline( cin, enter );
}

void gameExit( Game & b )
{
    cout << "Exit command recived. Cleaning up before closing." << endl;
    cout << "You may now close the window." << endl;
    delete[] b.grid;
    delete[] b.checked;
    exit(0);
}
