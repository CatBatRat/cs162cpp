#ifndef __DUNGEON__
#define __DUNGEON__

#include <iostream>
#include <string>
#include <random>
#include "qolife.hpp"

const int DUNY = 10;
const int DUNX = 14;

/* The chars used in the construction of the dungeon. */
const char DOT = '.', MON = '&', TRES = '$', PLAYER = '@', BORD = '#';
const int NUMMONS = 4;

struct Dungeon {

    /* Dungeon play area */
    char area[DUNY][DUNX] = {};

    /* Player coordinates */
    int py = 0;
    int px = 0;

    /* Game end condition met */
    bool end = false;

    /* Player win condition met */
    bool winner = false;
    bool loser = false;
};

/* My first time using a functional class. I thought it would be better to use
 * a class as it would make it much easier to handle the stored values for each
 * monster such as position and determining where each one can move without
 * them stepping on each other. */
class Monster {
    private:
        int mony = 0;
        int monx = 0;
        bool chase = false;
    public:
        void initMon( Dungeon & room );
        void moveMon( Dungeon & room );
};

void getMoves( Dungeon & room, Monster * mon );

/* Creates the starting room and fill with dots, places the player and and
 * other contents of the dungeon room. Since placement is done using the board
 * y x as rand bounds there is no need for bounds checking. */
void initRoom( Dungeon & room );

void showRoom( Dungeon & room );

int dRand( char cord );

void movePlayer( Dungeon & room, int y, int x );

bool checkMove( Dungeon & room, int y, int x );

void placeObj( Dungeon & room, char obj );

#endif //__DUNGEON__
