#include <iostream>
#include <iomanip>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

void initRoom( Dungeon & r ) {
    for( int y=0; y<DUNY; y++ ) {
        for( int x=0; x<DUNX; x++ ) {
            r.area[y][x] = FILL;
        }
    }
    r.py = dRand('y');
    r.px = dRand('x');
    r.area[r.py][r.px] = PLAYER;
}

void showRoom( Dungeon r ) {
    for( int l=0; l<300; l++ )
        cout << "\n";
    cout << std::string(DUNX*2+3, BORD) << endl;
    for( int y=0; y<DUNY; y++ ) {
        cout << BORD << " ";
        for( int x=0; x<DUNX; x++ ) {
            cout << r.area[y][x] << " ";
        }
        cout << BORD << endl;
    }
    cout << std::string(DUNX*2+3, BORD) << endl;
}
