#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void instructions( Dungeon & r ) {

    std::vector<string> index = { "intro", "instructions" };
    for( int i=0; i<static_cast<int>(index.size()); i++ )
    {
        showRoom( r, index[i] );
        _wait_enter();
    }
    //showRoom( r, "instructions" );
    //_wait_enter();
}

void showRoom( Dungeon & r, string item )
{
    std::stringstream side;
    sideBar( side, item );
    string line;
    for( int l=0; l<20; l++ )
        cout << "\n";
    for( int y=0; y<DUNY; y++ ) {
        for( int x=0; x<DUNX; x++ ) {
            cout << r.area[y][x] << " ";
        }
        if( std::getline( side, line ) and y < DUNY )
            cout << line;
        cout << endl;
    }
}

void sideBar(std::stringstream & side, string item ) {
    //std::stringstream out;

    if( item=="intro" ) {
        side << "This is a simple dungeon crawl.\n"
            "Your goal is to get to the end\n"
            "without running into, or getting\n"
            "trapped by enemies.\n\n"

            "Input using 'wasd' as a sequence,\n"
            "and your moves will match.\n\n"
            "Good luck!!!";
    }

    if( item=="instructions" ) {
        side << "w = Up\n\na = Left\n\ns = Down\n\nd = Right";
    }

    if( item=="legend" ) {
        side << PLAYER << " = Player\n\n"
            << MON    << " = Monster\n\n"
            << BORD   << " = Wall/Obstacle\n\n"
            << TRES   << " = Treasure";
    }

    //return out;
}
