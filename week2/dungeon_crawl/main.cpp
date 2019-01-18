#include <iostream>
#include "dungeon.hpp"

using std::cout;
using std::cin;
using std::endl;


int main()
{
    int test[DUNY][DUNX] = {};

    cout << "Hello world!" << endl;
    test = getMove( test );
    cout << getMove(test) << endl;
    return 0;
}
