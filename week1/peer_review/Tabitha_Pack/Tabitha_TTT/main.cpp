#include <iostream>
using namespace std;

char board[9]={'0','1','2','3','4','5','6','7','8'}; //having an issue where the information from the last
// game is being held over...need to make 2 arrays.

void showInstructions();

void exoh(int player, int square);

void showBoard();
bool checkWin();
bool checkTie();
bool repeat();
int main()
{

 do {

    showInstructions();
    bool win, tie;

   do{

    //confine second array in here
    showBoard();

    int player1 = 1, player2 = 2;
    int grid, winner;

        cout<< " Player " << player1 << ", Enter what box you'd like to place your X in.\n";
		cin >> grid;

    exoh(player1,grid);
    showBoard();

		cout << "\n Player " << player2 << ", Enter what box you'd like to place your O in. \n";
		cin >> grid;
		exoh (player2, grid);
		showBoard();

    win = checkWin();

		if (win == 1 )
		{	cout<<"\n Way to go! Player " << player1 << " has won!";
			break;
		}
		else
		if (win == 2 )
		{	cout<<"\n Congrats! Player " << player2 << " has won! \n";
			break;
		}

    tie = checkTie();


   } while(tie != true || win != true);


}while(repeat() != false);







}
// function definitions
void showInstructions()
{
 cout << "Let's play Tic-Tac-Toe!\n";
 cout << "There are 2 players. Each turn you will enter the number to put your X or O.\n";


}
void showBoard()
{
 cout << "Here is the board.\n" << endl;

 cout << "       " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
			cout << "     -----+-----+-----" << endl;
			cout << "       " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
			cout << "     -----+-----+-----" << endl;
			cout << "       " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
			cout << "     -----+-----+-----" << endl;

}

void exoh(int player, int square){

    if (player == 1 )
	{

		board[square] = 'X'; //user entered number; grid
	}
	else
		board[square] = 'O';
}



bool checkWin()

 {
		if (board[0] == board[1]  && board[1] == board[2] )
		{	if ( board [0] == 'X' )
			return 1;
			else
			return 2;

		}
		else
		if (board[3] == board[4]  &&  board[4] == board[5] )
			{	if ( board[3] == 'X' )
			return 1;
			else
                return 2;

		}
		else
		if (board[6] == board[7]  && board[7] == board[8] )
			{	if ( board[6] == 'X' )
			return 1;
			else
			return 2;
		}
		else
		if (board[0] == board[3]  && board[3] == board[6] )
			{	if ( board [0] == 'X' )
			return 1;
			else
			return 2;
		}
		else
		if (board[1] == board [4]  && board[4] == board[7] )
			{	if ( board[1] == 'X' )
			return 1;
			else
			return 2;
		}
	else
		if (board[2] == board[5]  && board[5] == board[8] )
			{	if (board[2] == 'X' )
			return 1;
			else
			return 2;
		}
else
		if (board[0] == board[4]  && board[4] == board[8] )
			{	if (board[0] == 'X' )
			return 1;
			else
			return 2;
		}
	else
		if (board[2] == board[4]  && board[4] == board[6] )
			{	if (board[2] == 'X' )
			return 1;
			else
			return 2;
		}

	else
		return false;
}




bool checkTie()
{

    if (checkWin() == false){
    return true;

    cout << "Player 1 and Player 2 have come to a draw.\n";
    }

}

bool repeat()
{
    char yesNo;
 cout << "\n Would you like to play again? Y/N \n";
 cin >> yesNo;

 if (yesNo == 'Y' || 'y')
 {
     return true;
 }
 else
    return false;

}
