#include <iostream>
#include <iomanip>

using namespace std;


// Function prototypes, see each function for additional detail. In retrospect, I need to be more consistent with my
// naming scheme. IE all function are camelcase, all variables use '_' etc.

void displayInstructions(char& player1, char& player2);
void showState(char gameBoard[], int asize, int active_player);
void makeMove(char gameBoard[], int asize, char player1, char player2, int active_player, int& pick);
void switchActive(int& active_player);
void checkWin(char gameBoard[], int asize, char player1, char player2, int& gamestate);
void displayWin(int gamestate, char gamecont, char gameBoard[], int asize, int active_player, bool& playing, int player1wins, int player2wins);
void checkDraw(char gameBoard[], int asize, int gamestate, char gamecont, bool& playing);

/*
    Main encompasses the tic-tac-toe program. I endeavored to have all code contained in the functions with
    names that made sense with little explanation. Instead of returning values to manipulate, almost all changes
    to the game-state are accomplished by passing by reference to change the variables value in memory. I will
    rely less heavily on this in the future to ensure my code is easily more maintainable and easier to read.
*/

int main()
{

 bool playing = true;
 char gameBoard[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '}; // Used 1d array for gameboard, used mostly as a learning exercise.
 char player1 = 'X', player2 = 'O', gamecont = 'Y';         // player1/2 is used to store X or O as the players mark, gamecont is saved to see if another game is to be played
 int pick = 0, active_player = 1, gamestate = 1;            // pick is which position is chosen, active player is as thought, gamestate 2 is when someone has won.
 static int player1wins = 0, player2wins = 0;               // static ints track how many times a player has won.

 displayInstructions(player1, player2);

 while (playing) {

    showState(gameBoard, 9, active_player);
    makeMove(gameBoard, 9, player1, player2, active_player, pick);
    checkWin(gameBoard, 9, player1, player2, gamestate);
    displayWin(gamestate, gamecont, gameBoard, 9, active_player, playing, player1wins, player2wins);
    checkDraw(gameBoard, 9, gamestate, gamecont, playing);
    switchActive(active_player);

 }

}

// displayInstructions does just that, as well as having the player input which mark they chose and validating the input.

void displayInstructions(char& player1, char& player2) {

    cout << "Hello and welcome to Tic-Tac-Toe! You will select X's or O's for \n";
    cout << "your preferred marker. Get three X's or O's in a row and you win!\n";
    cout << "You will be playing with a second player. If you lose, you will go 1st\n";
    cout << "in the next round.\n\n";
    cout << "The board for Tic-Tac-Toe is shown below with numerical positions.\n\n";
    cout << "[1] [2] [3]\n";
    cout << "[4] [5] [6]\n";
    cout << "[7] [8] [9]\n";
    cout << "\nTo begin, Player 1 will select X or O: \n";

    cin >> player1;

    while (player1 != 'X' && player1 != 'x' && player1 != 'O' && player1 != 'o') {
        cout << "\nThat entry was not an X or an O, please select X or O: \n";
        cin >> player1;
    }

    if (player1 == 'O' || player1 == 'o') {
        player2 = 'X';
    }

    cout << "\nPlayer 1 is " << player1 << "'s. \n";

}

/*
    showState shows the state of the gameboard by checking each element of the gameBoard array and printing it in the relevant
    slot as well as showing the currently actively player. after having done all of the work, I wish I had set the gameboard to
    mirror the numpad for easier use.
*/

void showState(char gameBoard[], int asize, int active_player){

    cout << "\nThe active player is " << active_player << ". \n";
    cout << "\nCurrently, the board appears as below: \n\n";
    cout << "[" << gameBoard[0] << "] " << "[" << gameBoard[1] << "] " << "[" << gameBoard[2] << "] \n";
    cout << "[" << gameBoard[3] << "] " << "[" << gameBoard[4] << "] " << "[" << gameBoard[5] << "] \n";
    cout << "[" << gameBoard[6] << "] " << "[" << gameBoard[7] << "] " << "[" << gameBoard[8] << "] \n";
    cout << " \n";

}

/*
    makeMove prompts the user for input of 1-9, validates it, and checks to ensure the selected slot
    is empty. the switch statement is utilized to update the corresponding array element to the active
    players mark.
*/

void makeMove(char gameBoard[], int asize, char player1, char player2, int active_player, int& pick){

    cout << "Please select which position to play on. (1-9)\n";
    cin >> pick;

    while (cin.fail() || pick < 1 || pick > 9) {
        cin.clear();
        cin.ignore();
        cout << "\nThat was not a valid selection. Please enter a number between 1 and 9.\n";
        cin >> pick;
    }

    while (gameBoard[pick - 1] != ' ') {
        cin.clear();
        cin.ignore();
        cout << "\nThat was not a valid selection. Please enter an unoccupied space.\n";
        cin >> pick;
    }

    cout << "\n Your choice was " << pick << endl;

    switch (pick) {
        case 1:
            if (active_player == 1){
                gameBoard[0] = player1;
            }
            else {
                gameBoard[0] = player2;
            }
            break;
        case 2:
            if (active_player == 1){
                gameBoard[1] = player1;
            }
            else {
                gameBoard[1] = player2;
            }
            break;
        case 3:
            if (active_player == 1){
                gameBoard[2] = player1;
            }
            else {
                gameBoard[2] = player2;
            }
            break;
        case 4:
            if (active_player == 1){
                gameBoard[3] = player1;
            }
            else {
                gameBoard[3] = player2;
            }
            break;
        case 5:
            if (active_player == 1){
                gameBoard[4] = player1;
            }
            else {
                gameBoard[4] = player2;
            }
            break;
        case 6:
            if (active_player == 1){
                gameBoard[5] = player1;
            }
            else {
                gameBoard[5] = player2;
            }
            break;
        case 7:
            if (active_player == 1){
                gameBoard[6] = player1;
            }
            else {
                gameBoard[6] = player2;
            }
            break;
        case 8:
            if (active_player == 1){
                gameBoard[7] = player1;
            }
            else {
                gameBoard[7] = player2;
            }
            break;
        case 9:
            if (active_player == 1){
                gameBoard[8] = player1;
            }
            else {
                gameBoard[8] = player2;
            }
            break;
        default:
            break;
    }

}

// switchActive switches the active player from 1 to 2 and vice versa.

void switchActive(int& active_player) {

    if (active_player == 1) {
        active_player = 2;
    }
    else {
        active_player = 1;
    }

}

/*
    checkWin compares the board state looking for a winning move. If any of the criteria are met,
    gameState will be set to 2, signaling that someone has won. if not, gamestate remains 1 and the
    game loop continues.
*/

void checkWin(char gameBoard[], int asize, char player1, char player2, int& gamestate){

    if (gameBoard[0] == player1 &&  gameBoard[1] == player1 && gameBoard[2] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[0] == player2 && gameBoard[1] == player2 && gameBoard[2] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[3] == player1 && gameBoard[4] == player1 && gameBoard[5] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[3] == player2 && gameBoard[4] == player2 && gameBoard[5] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[6] == player1 && gameBoard[7] == player1 && gameBoard[8] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[6] == player2 && gameBoard[7] == player2 && gameBoard[8] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[0] == player1 && gameBoard[3] == player1 && gameBoard[6] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[0] == player2 && gameBoard[3] == player2 && gameBoard[6] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[1] == player1 && gameBoard[4] == player1 && gameBoard[7] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[1] == player2 && gameBoard[4] == player2 && gameBoard[7] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[2] == player1 && gameBoard[5] == player1 && gameBoard[8] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[2] == player2 && gameBoard[5] == player2 && gameBoard[8] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[0] == player1 && gameBoard[4] == player1 && gameBoard[8] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[0] == player2 && gameBoard[4] == player2 && gameBoard[8] == player2) {
        gamestate = 2;
    }
    else if (gameBoard[2] == player1 && gameBoard[4] == player1 && gameBoard[6] == player1) {
        gamestate = 2;
    }
    else if (gameBoard[2] == player2 && gameBoard[4] == player2 && gameBoard[6] == player2) {
        gamestate = 2;
    }
    else {
        gamestate = 1;
    }

}

/*
    displayWin reads the gamestate variable, if '2', it congratulates the player and asks if they would like to continue, validating
    their input. if they do want to play, it will increment the victory counter for the active player, resets the gamestate, overwrites
    the array to all spaces using a for loop, and displays total wins for both players. retrospectively I should have created a different
    function to incorporate all the gamestate maintenance.
*/

void displayWin(int gamestate, char gamecont, char gameBoard[], int asize, int active_player, bool& playing, int player1wins, int player2wins) {

    if (gamestate == 2) {
        showState(gameBoard, 9, active_player);
        cout << "Congratulations! " << active_player << " has won! \n";
        cout << "\nWould you like to continue? (Y/N)\n";
        cin >> gamecont;

        while (gamecont != 'Y' && gamecont != 'y' && gamecont != 'N' && gamecont != 'n') {
            cout << "\nThat entry was not an Y or an N, please select Y or N: \n";
            cin >> gamecont;
        }

        if (gamecont == 'N' || gamecont == 'n') {
            playing = false;
        }
        else if (gamecont == 'Y' || gamecont == 'y') {

            gamestate = 1;

            if (active_player == 1) {
                player1wins++;
            }
            else if (active_player == 2) {
                player2wins++;
            }

            for (int i = 0; i < 9; i++) {
                gameBoard[i] = ' ';
            }
        cout << "Player 1 has won " << player1wins << " times!\n";
        cout << "Player 1 has won " << player2wins << " times!\n";

         }
    }

}

/*
    checkDraw will look at each element of the array and determine if they are not a space, if that is true and
    the gamestate is 1 indicating the game loop is ongoing it will declare a draw and prompt the user for input
    to see if they want to continue, validating their input. If no, we set playing to false ending the loop,
    if they do, we clear the board and start again.
*/

void checkDraw(char gameBoard[], int asize, int gamestate, char gamecont, bool& playing) {

    if (gameBoard[0] != ' ' && gameBoard[1] != ' ' && gameBoard[2] != ' ' &&
        gameBoard[3] != ' ' && gameBoard[4] != ' ' && gameBoard[5] != ' ' &&
        gameBoard[6] != ' ' && gameBoard[7] != ' ' && gameBoard[8] != ' ' &&
        gamestate == 1) {

            cout << "\nThe game is a draw. Would you like to play again?. (Y/N)\n";
            cin >> gamecont;

            while (gamecont != 'Y' && gamecont != 'y' && gamecont != 'N' && gamecont != 'n') {
                cout << "\nThat entry was not an Y or an N, please select Y or N: \n";
                cin >> gamecont;
            }

            if (gamecont == 'N' || gamecont == 'n') {
                playing = false;
            }

            for (int i = 0; i < asize; i++) {
                gameBoard[i] = ' ';
            }

         }

}
