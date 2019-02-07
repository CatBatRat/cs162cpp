#include <iostream>
#include "memgame.hpp"

using namespace std;

int main() {

    Game board;

    cout << "Enter the size of the board" << endl;
    cin >> board.size;
    bool red[12] = {};
    cout << red << endl;

    board.grid = makeBoard( board );
    board.checked = makeBoard( board );
    displayBoard( board );

    return 0;
}
