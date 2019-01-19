#include <iostream>
#include <iomanip>
#include <string>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

void movePlayer( Dungeon & r ) {
    std::string moves = "";
    cout << "Input the sequence of moves you would like to make." << endl;
    cin >> moves;
    _cin_clear();

    for( auto m : moves ) {
        int y = r.py;
        int x = r.px;
        switch( m ) {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
        }
        if( y<DUNY and y>=0 and x<DUNX and x>=0 ) {
            updateDungeon( r, y, x );
            showRoom( r );
            cout << endl;
            _sleep( 300 );
        }
        else {
            cout << "You run into a wall and break your nose." << endl;
            _sleep( 4000 );
            break;
        }
    }
}

void updateDungeon( Dungeon & r, int y, int x ) {
    r.area[r.py][r.px] = FILL;
    r.area[y][x] = PLAYER;
    r.py = y;
    r.px = x;
}

/* Generate multiple random numbers in ranges based on predetermined chars */
int dRand( char cord ) {
    int temp;
    if( cord == 'y' ) {
        temp = rand() % DUNY;
    }
    if( cord == 'x' ) {
        temp = rand() % DUNX;
    }
    return temp;
}
