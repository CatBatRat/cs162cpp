#include <iostream>
#include <random>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    srand(static_cast<int>(time(NULL)));

    std::string state = "";

    Dungeon room;

    Monster * mon;
    mon = new Monster[NUMMONS];
    for( int m=0; m<NUMMONS; m++ )
        mon = new Monster;

    initRoom( room );
    for( int m=0; m<3; m++ )
        mon[m].initMon( room );

    do {
        showRoom( room );
        getMoves( room, mon );
    } while( !room.end );
    if( room.winner ) {
        cout << "You Won!!!!!!!! Goooooooooaaaaallllllll!!!!!!!!" << endl;
    }
    if( room.loser ) {
        cout << "The wall turns out to be a monster that was taking a nap.\n"
                "It wakes up and eats you. Let sleeping monsters lie!" << endl;
    }

    _wait_enter();

    return 0;
}
