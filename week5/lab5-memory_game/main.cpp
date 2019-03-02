#include <iostream>
#include <random>
#include "memgame.hpp"

using namespace std;

int main()
{
    srand(static_cast<int>(time(nullptr)));

    Game board;

    intro();
    do
    {
        getSize( board );
        board.grid = makeBoard( board );
        board.checked = makeChecked( board );
        do
        {
            displayBoard( board );
            cout << "Pick the first card you would like to flip." << endl;
            // If the player inputs a 0 during any turn, then the gameExit
            // function will be called which frees up memory from board.grid
            // and board.checked before calling the exit function from cstdlib.
            getMove( board );
            displayBoard( board );
            cout << "Now pick the second card." << endl;
            getMove( board );
            checkMove( board );
            // checkWin also resets the board to starting values should the player
        } while( !( checkWin( board ) ) );
        displayBoard( board );
        cout << "Yay! You won the game!!!" << endl;

        delete[] board.grid;
        delete[] board.checked;
    } while( playAgain( board ) );

    return 0;
}
