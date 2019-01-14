#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include "tictac.hpp"

using std::cin;
using std::cout;
using std::endl;

int gameLoop() {

    /* This is for the return value that shows win or draw of the round to be
     * used in the switch case statement at game end. */
    int state;

    /* Create instance of struct Game as g. This contains all data and stats
     * for the game. Just trying this out but, while it does make things
     * easier, it could complicate things later as it is not immediately clear
     * what is being passed to the functions which could make debugging
     * difficult. */
    struct Game g;

    for( int rnd=0; rnd<3; rnd++ ) {
        showBoard( g );
        bool exit = false;
        do {
            getMove( g );
            showBoard( g );
            if( checkWin( g ) or checkDraw( g ) )
                exit = true;
            else if( checkDraw( g ) )
                exit = true;
        } while( !exit );
        g.turn = 0;

        /* Erase the contents of 'g.board' for each round.
         * May be better if I use a new instance of a struct/class. Would be
         * cleaner, and it may not be valid to assume all the values should be
         * set to zero. */
        std::memset(g.board, 0, sizeof(g.board));
    }
    if( g.wins[0] == g.wins[1] )
        state = 0;
    else if( g.wins[0] > g.wins[1] )
        state = 1;
    else
        state = 2;
    return state;
}

void showBoard ( const struct Game &g ) {
    /* Copy the current value 'g.point' to short-name vars to make them easier to work with */
    int y = g.point[0]-1;
    int x = g.point[1]-1;
    /* Contents for each cell determined by the current int value in each cell. */
    char cells[3] = { '_', 'O', 'X' };
    /* Quick and dirty game stats showing number of wins. */
    cout << "Number of wins." << endl
         << "   Player 1 = " << g.wins[0] << endl
         << "   Player 2 = " << g.wins[1] << endl;
    /* Column indicator using flexible space showing the last used column. */
    cout << "  "<< std::right << std::setw(x*3) << "" << "v" << endl;
    for( int row=0; row<SIZE; row++ ) {
        /* Output the row numbers. */
        cout << row+1;

        /* Create each cell and set the contents based on numbers used as index
         * for the 'cells' array. */
        for( int col=0; col<SIZE; col++ ) {
            cout << "[" << cells[g.board[row][col]] << "]";
        }
        /* Last used row indicator. */
        if( y == row ) {
            cout << "<";
        }
        cout << endl;
    }
    /* Output the column numbers. */
    cout << " ";
    for( int i=1; i<=SIZE; i++ )
        cout << " " << i << " ";
    cout << endl;
}

void getMove( struct Game &g ) {
    int playerTurn = g.turn%2+1;
    bool valid = false;

    do {
        dialog("getin");
        cin >> g.point[0] >> g.point[1];
        int y = g.point[0]-1, x = g.point[1]-1;
        if( !g.board[y][x] == 0 ) {
            dialog("taken");
            showBoard( g );
        }
        else{
            g.board[y][x] = playerTurn;
            valid = true;
        }
    } while( !valid );

}

bool checkWin( struct Game &g ) {
    /* Using from struct Game
     *      g.board
     *      g.wins
     *      g.turn*/
    int (&b)[SIZE][SIZE] = g.board;
    bool win = false;
    // Check rows for win
    for( int row=0; row<SIZE; row++ ) {
        if( g.board[row][0] != 0 ) {
            if( b[row][0] == b[row][1] and b[row][0] == b[row][2] ) {
                win = true;
            }
        }
    }
    // Check columns for win
    for( int col=0; col<SIZE; col++ ) {
        if( b[0][col] != 0 ) {
            if( b[0][col] == b[1][col] and b[0][col] == b[2][col] ) {
                win = true;
            }
        }
    }
    // Check diagonals for win
    if( b[1][1] != 0 ) {
        if( b[1][1] == b[0][0] and b[1][1] == b[2][2] ) {
            win = true;
        }
        if( b[1][1] == b[0][2] and b[1][1] == b[2][0] ) {
            win = true;
        }
    }
    if( win ) {
        dialog("rwin");
        g.wins[g.turn%2] += 1;
    }
    g.turn++;

    return win;
}

bool checkDraw( const struct Game &g ) {
    int draw = false;
    if( g.turn == SIZE*SIZE ) {
        dialog("rdraw");
        draw = true;
    }
    return draw;
}
