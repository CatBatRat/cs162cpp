#include <iostream>
#include <iomanip>
#include <string>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

void getMoves( Dungeon & r, Monster * mon ) {
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
            default:
                cout << "You trip over you own feet becuase you forgot how to run." << endl;
        }

        if( y<DUNY and y>=0 and x<DUNX and x>=0 and checkMove( r, y, x ) ) {
            movePlayer( r, y, x );
            for( int m=0; m<NUMMONS; m++ ) {
                mon[m].moveMon( r );
            }
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

void movePlayer( Dungeon & r, int y, int x ) {
    r.area[r.py][r.px] = DOT;
    r.area[y][x] = PLAYER;
    r.py = y;
    r.px = x;
}

/* Generate multiple random numbers in ranges called by chars */
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

bool checkMove( Dungeon & r, int y, int x ) {
    bool valid = false;
    if( r.area[y][x] == DOT ) {
        valid = true;
    }
    if( r.area[y][x] == TRES ) {
        r.end = true;
        r.winner = true;
        valid = true;
    }
    if( r.area[y][x] == MON ) {
        r.end = true;
        r.loser = true;
        valid = false;
    }
    return valid;
}
