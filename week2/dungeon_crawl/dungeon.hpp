#ifndef __DUNGEON__
#define __DUNGEON__

#include <iostream>
#include <string>
#include <cstdio>
#include <string>
#include <sstream>
#include "qolife.hpp"

// consts controlling dungeon size.
const int DUNY = 12;
const int DUNX = 16;

// Rate at which the dungeon update per move in milliseconds.
const int SPEED = 300;

// The chars used in the construction of the dungeon. When changing these make
// sure to update the legend in the 'showRoom' function.
const char DOT = '.', MON = '&', TRES = '$', PLAYER = '@', BORD = '#';
const char UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd';

struct Dungeon {

    int numMons = 0;
    // Dungeon play area
    char area[DUNY][DUNX] = {};

    // Player coordinates
    int py = 0;
    int px = 0;

    // Game end condition met
    bool end = false;

    // Player win condition met
    bool winner = false;
    bool loser = false;
};

// My first time using a functional class. I thought it would be better to use
// a class as it would make it much easier to handle the stored values for each
// monster such as position and determining where each one can move without
// them stepping on each other.
class Monster {
    private:
        // Last known psition of the monster instance to be used when selecting
        // the next move.
        int mony = 0;
        int monx = 0;
    public:
        // Set the starting position of the monster and record its current
        // position for later use.
        void initMon( Dungeon & room );
        // Move the monster toward the player on a semi-random axis and avoid
        // stepping on obstacles or the player. Player must run into the
        // monsters, but the monsters have a habit of boxing the player in so
        // there is no other option if you not careful.
        void moveMon( Dungeon & room );

};

// Show the instructions to the player displayed next to the board.
void instructions( Dungeon & room );

// Get moves from the player and call 'movePlayer' on valid options.
void getMoves( Dungeon & room, Monster * mon );

// Creates the starting room and fill with dots, places the player and other
// contents of the dungeon room. Since placement is done using the board y x as
// rand bounds there is no need for bounds checking.
void initRoom( Dungeon & room );

// The current state of the room and show content to the side that is fed into
// it.
void showRoom( Dungeon & room, std::string item );

// Contains text for display to the side of the dungeon map. Returned as
// sstream so each line can be iterated over rather than having to turn each
// string into an array/vector then iterating over that.
void sideBar(std::stringstream & side, std::string item );

// Generate multiple random numbers in ranges called by chars.
int dRand( char cord );

// Moves the player and handles making sure the previous space is set as empty
// again.
void movePlayer( Dungeon & room, int y, int x );

// Checks the result of a move and whether the move is valid.
bool checkMove( Dungeon & room, int y, int x );

// Places chars at random around the board. char comes from function call.
void placeObj( Dungeon & room, char obj );

#endif //__DUNGEON__
