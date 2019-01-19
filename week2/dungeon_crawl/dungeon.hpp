#ifndef __DUNGEON__
#define __DUNGEON__

#include <string>
#include "qolife.hpp"

const int DUNY = 10;
const int DUNX = 14;

struct Dungeon {
    /* Dungeon room */
    char area[DUNY][DUNX] = {};
    /* Player coordinates */
    int py = 0;
    int px = 0;
};

/* The chars used in the construction of the dungeon. */
const char FILL = '.', MON = '&', TRES = '$', PLAYER = '@', BORD = '#';

void movePlayer( Dungeon & room );

void initRoom( Dungeon & room );

void showRoom( Dungeon room );

int dRand( char cord );

void updateDungeon( Dungeon & room, int y, int x );

#endif //__DUNGEON__
