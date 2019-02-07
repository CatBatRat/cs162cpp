#ifndef __MEM_GAME__
#define __MEM_GAME__

//const int SIZE = 4*4; // 4x4 grid

struct Game {
    int size;
    int last;
    int * grid;
    int * checked;
};

int getMove( Game & board );
int * makeBoard( const Game & board );
void displayBoard( Game & board );

#endif //__MEM_GAME__
