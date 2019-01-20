#include <iostream>
#include <random>
#include "dungeon.hpp"


void Monster::initMon( Dungeon & room ) {
    mony = rand() % DUNY;
    monx = rand() % DUNX;
    while( room.area[mony][monx] != '.' ) {
        mony = rand() % DUNY;
        monx = rand() % DUNX;
    }
    room.area[mony][monx] = MON;
    std::cout << "I'm a monster @: " << mony << monx << std::endl;
}

void Monster::moveMon( Dungeon & room ) {
    int direc = rand() % 2;
    if( direc == 0 ) {
        if( room.py > mony and room.area[mony+1][monx] == '.' ) {
            room.area[mony++][monx] = DOT;
            room.area[mony][monx] = MON;
        }
        if( room.py < mony and room.area[mony-1][monx] == '.' ) {
            room.area[mony--][monx] = DOT;
            room.area[mony][monx] = MON;
        }
    }
    if( direc == 1 ) {
        if( room.px > monx and room.area[mony][monx+1] == '.' ) {
            room.area[mony][monx++] = DOT;
            room.area[mony][monx] = MON;
        }
        if( room.px < monx and room.area[mony][monx-1] == '.' ) {
            room.area[mony][monx--] = DOT;
            room.area[mony][monx] = MON;
        }
    }
    //mony += y;
    //monx += x;
    std::cout << "I'm a monster @: " << mony << monx << std::endl;
}
