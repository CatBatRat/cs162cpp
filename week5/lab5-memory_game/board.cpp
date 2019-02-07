#include <iostream>
#include "memgame.hpp"

int * makeBoard( const Game & b )
{

    return new int[b.size*b.size];
}

void displayBoard( Game & b )
{
    for( int y=0; y<b.size; y++ )
    {
        for( int x=0; x<b.size; x++ )
        {
            std::cout << b.grid[x] << "  ";
        }
        std::cout << std::endl;
    }
}

