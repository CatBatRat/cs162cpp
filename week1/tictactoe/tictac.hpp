#ifndef TIC_TAC
#define TIC_TAC

#include <string>

const int SIZE = 3;

struct Game {
    int wins[2] = {};
    int board[SIZE][SIZE] = {};
    int point[2] = {1, 1};
    int turn = 0;
};

/* Show instructions to the player Range to select from. What each command does
 * How to exit */
void dialog(std::string key);

/* Instantiate the Game struct call the functions the drive the main game. Gets
 * rerun each time the player chooses to play again after three rounds.  */
int gameLoop();

/* Display the game board, current choices made, and which empty square is
 * selected, as well as an indicator at the edges showing which empty row and
 * column is selected. */
void showBoard ( const struct Game &g /* point, wins, board */ );



 /* Get move from the player and validate range and whether a sqaure has been
  * used or not. */
void getMove( struct Game &g /* turn, point, board */);

/* Check for all possible win conditions and slightly decrease the number of
 * checks by using key squares to determine when a win condition should be
 * checked for. If the game grid increases I will need to change to using loops
 * exclusively for checking win conditions; I may do this anyway simply to help
 * me work out the logic involved in such a process. */
bool checkWin( struct Game &g /* turn, board */);

/* Simply checks the number to turns taken and declared a draw if the threshold is reached and there in no winner declared */
bool checkDraw( const struct Game &g /* turn */ );

#endif
