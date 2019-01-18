#include <iostream>
using namespace std;
// global constants
const char X = 'X';
const char O = 'O';
const char SPACE = ' ';

// function declarations
void showInstructions();
void showBoard(char theBoard[]);       // see flattening pdf & passing arrays pdf
void initBoard(char theBoard[]);
int getMove(int PlayerNo, char theBoard[]);
void updateBoard(char theBoard[], int, int playerNo);
bool checkWin(char theBoard[]);
bool checkTie(char theBoard[]);
bool repeat();

int main()
{
     // outer repeat loop
     do {
         // display instructions
         showInstructions();

         // set up game and define variables
         bool win, tie;
         char theBoard[9];
         initBoard(theBoard);
         int playerNo = 1;

         // inner game loop
         do {
             // display board
             showBoard(theBoard);

             // get next move
             int thisMove = getMove(playerNo, theBoard);

             // update board
             updateBoard(theBoard, thisMove, playerNo);

             // check for win
             win = checkWin(theBoard);

             // check for tie
             tie = checkTie(theBoard);

             // if game not over, swap player
             if ( not win and not tie )
             {
             if (playerNo == 1)
                playerNo = 2;
             else if (playerNo == 2)
                playerNo = 1;
             }
         } while (not win and not tie);

         // display final board and congratulate winner
         showBoard(theBoard);
         if ( win )
         cout << "Congratulations player " << playerNo << " you won!!" << endl;
         if ( tie )
         cout << "The game was a tie." << endl;
     } while ( repeat() );
     return 0;
}

// function definitions

void showInstructions()
{
 cout << "Welcome to \nTic Tac Toe : The Game.\n" << endl;
 cout << "To make your move, simply enter the number of the row and column that you " << endl;
 cout << "wish to occupy. E.g. Type \" A \" and then \" 1 \" to occupy the top left spot. " << endl
      << "The game is over when a player gets 3 marks in a row. \n" << endl;      // enter # of players i/o
}

void showBoard(char theBoard[])
{
    string a = "  ";
    string b = " | ";
    string endRow = "  -----------";

    cout    << "   1   2   3\n"
            << "A" << a << theBoard[0] << b << theBoard[1] << b << theBoard[2] << endl
            << endRow << endl
            << "B" << a << theBoard[3] << b << theBoard[4] << b << theBoard[5] << endl
            << endRow << endl
            << "C" << a << theBoard[6] << b << theBoard[7] << b << theBoard[8] << endl;
}

void initBoard(char theBoard[])
{
 cout << "Initializing board" << endl;
 for( int i=0; i<=8; i++)
 {
    theBoard[i] = SPACE;
 }
}

int getMove(int playerNo, char theBoard[])
{
    bool goodIn = 1;
    int spaceCounter = 0;
 do
    {
        char row;
        int col;
        cout << "Player " << playerNo << ", enter a valid move now. "<<  endl;
        cin >> row >> col;
        if ((row == 'A') || (row == 'a'))
            spaceCounter = 0;
        else if((row == 'B') || (row == 'b'))
            spaceCounter = 3;
        else if ((row == 'C') || (row == 'c'))
            spaceCounter = 6;
        else goodIn = 0;
        col -= 1;
        //loop here?

        if ((col >=0) && (col <3))
        {
            spaceCounter += col;
            goodIn = 1;
        }else
        {
            goodIn = 0;
        }

        if	(cin.fail() )
        {
            cout << "User input error. " << endl;
            goodIn = 0;
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');         ////////////////this doesn't work... WHY!?
        }
        else if(theBoard [spaceCounter] != ' ') // if occupied space
        {
            cout << " Woah, you can't just go wherever you want!" << endl;
            goodIn = 0;
            cin.clear();
        }
    }while(goodIn == 0);
    return spaceCounter;
}

void updateBoard(char theBoard[], int thisMove, int playerNo)
{
    char symbol;
    if (playerNo == 1)
        symbol = 'X';
    else
        symbol = 'O';
    cout << "Updating board" << endl;
    theBoard[thisMove] = symbol;
}

bool checkWin(char theBoard[])
{
     cout << "Checking for win" << endl;
     if (((theBoard[0] == theBoard[3]) && (theBoard[3] == theBoard[6]) && (theBoard[6] != ' ')) ||
         ((theBoard[1] == theBoard[4]) && (theBoard[4] == theBoard[7]) && (theBoard[7] != ' ')) ||
         ((theBoard[2] == theBoard[5]) && (theBoard[5] == theBoard[8]) && (theBoard[8] != ' ')) ||
         ((theBoard[0] == theBoard[1]) && (theBoard[1] == theBoard[2]) && (theBoard[2] != ' ')) ||
         ((theBoard[3] == theBoard[4]) && (theBoard[4] == theBoard[5]) && (theBoard[5] != ' ')) ||
         ((theBoard[6] == theBoard[7]) && (theBoard[7] == theBoard[8]) && (theBoard[8] != ' ')) ||
         ((theBoard[0] == theBoard[4]) && (theBoard[4] == theBoard[8]) && (theBoard[8] != ' ')) ||
         ((theBoard[2] == theBoard[4]) && (theBoard[4] == theBoard[6]) && (theBoard[6] != ' ')))
         {
         return true;
         }
        else
        {
         return false;
        }
}

bool checkTie(char theBoard[])
{
    int tie = 0;
    for (int i = 0 ; i <= 8; i++)
    {
        if (theBoard[i] == ' ')
        {
        return false;
        tie ++;
        }
    }
    if ( tie == 8)
    {
        return true;
    }
}

bool repeat()
{
    string repeatStr ;
    cout << "Would you like to play again? " << endl;
    cin >> repeatStr;
    if ((repeatStr == "Yes") || (repeatStr == "Y") || (repeatStr == "y") || (repeatStr == "yes"))
    {
        return true;
    }
    else
    {
    return false;
    }
}
