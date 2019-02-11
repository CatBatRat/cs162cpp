#ifndef __MEM_GAME__
#define __MEM_GAME__

#include <iostream>
#include <limits>

const int CARDNUM = 8;
const char CARDS[CARDNUM] = { '&','$','#','@','?','%','!','+' };
const long int BIG_NUM = std::numeric_limits<std::streamsize>::max();
struct Game {
    int size;
    int last;
    int current;
    int tries;
    int matches;
    char * grid;
    bool * checked;

    Game(): size(4), last(-1), current(-1), tries(0), matches(0) {}
};


// ~play.cpp~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void getSize( Game & board );
// Gets card selection from the player, calculates the index of the two numbers
// in a one dimensional array, and verifies that the numbers entered are in the
// same range as the board.
void getMove( Game & board );
// Checks to see if a number other than -1 is in the two index values (this
// shows a card has been selected) checks to see if the symbols at those
// indices match and also makes sure the player does not cheat by selecting the
// same card twice in the same spot.
void checkMove( Game & board );
// Checks if all value of Game { matches } is equal to have the number of
// points on the number of cards on the board. Since there is two of every
// card, this number will always mean the game is done.
bool checkWin( Game & board );
// Ask the user if they would like to play again and return true if responding
// with y[es]. Also reset some of the values in Game to reflect the game
// restarting.
bool playAgain( Game & board );
// Simply waits for the user to press enter.
void waitEnter();
// If the user inputs a zero when selecting a column, this method will be
// called which deletes Game grid and checked before calling the exit()
// function from cstdio.
void gameExit( Game & board );


// ~board.cpp~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void intro();
// Makes the base board that the symbols for the game will be matched from.
// The array is filled using a list of chars acting as the cards. The cards are
// selected to placed in a rotating order so the their placement can adapt to
// any board size. This is dependant on the board being an even number of cards
// so the board size must be checked to see if b.size*b.size results in an even
// number.
char * makeBoard( const Game & board );
// Makes the board that will track whether a card has been matched ready for
// the display function to change how the cards are displayed after a match has
// be made.
bool * makeChecked( const Game & board );
// Displays the board along with row numbers. Un-flipped cards are shown as [*]
// cards that have been selected on the current turn are shown with ( ) and
// cards that have been matched are shown with { }.
void displayBoard( Game & board );
// Clear the contents of std::cin. This should be called any time input is
// going to be used as part of a loop. Put it before the loop or at the end of
// a loop before checking an condition and it will prevent any errors due from
// cin.fail().
void cinClear();


#endif //__MEM_GAME__
