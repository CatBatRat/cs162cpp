#include <iostream>
#include <random>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand(static_cast<int>(time(NULL)));

    Dungeon room;

    initRoom( room );
    do {
        showRoom( room );
        movePlayer( room );
    } while( true );

    _wait_enter();


    return 0;
}
