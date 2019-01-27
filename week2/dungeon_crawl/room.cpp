#include <iostream>
#include <iomanip>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

void initRoom( Dungeon & r ) {
    for( int y=0; y<DUNY; y++ ) {
        for( int x=0; x<DUNX; x++ ) {
            if( y==0 or y==DUNY-1 )
                r.area[y][x] = BORD;
            else if( x==0 or x==DUNX-1 )
                r.area[y][x] = BORD;
            else
                r.area[y][x] = DOT;
        }
    }
    placeObj( r, PLAYER );
    placeObj( r, TRES );
    for( int d=0; d<5; d++ )
        placeObj( r, BORD );
}

void placeObj( Dungeon & r, char obj ) {
    int y = dRand('y'), x = dRand('x');
    while( r.area[y][x] != '.' ) {
        y = dRand('y');
        x = dRand('x');
    }
    r.area[y][x] = obj;
    if( obj == PLAYER ) {
        r.py=y;
        r.px=x;
    }
}
