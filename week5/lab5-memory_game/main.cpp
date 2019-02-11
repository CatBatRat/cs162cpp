#include <iostream>
#include <random>
#include "memgame.hpp"

using namespace std;

int main()
{
    srand(static_cast<int>(time(nullptr)));

    Game board;

    do
    {
        getSize( board );
        board.grid = makeBoard( board );
        board.checked = makeChecked( board );
        do
        {
            displayBoard( board );
            cout << "Pick the first card you would like to flip." << endl;
            getMove( board );
            displayBoard( board );
            cout << "Now pick the second card." << endl;
            getMove( board );
            //displayBoard( board );
            checkMove( board );
        } while( !( checkWin( board ) ) );
        displayBoard( board );
        cout << "Yay! You won the game!!!" << endl;

        delete[] board.grid;
        delete[] board.checked;
    } while( playAgain( board ) );

    return 0;
}
