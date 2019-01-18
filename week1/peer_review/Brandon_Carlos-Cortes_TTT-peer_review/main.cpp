#include <iostream>

using namespace std;

//global constants
const char X = 'X';
const char O = 'O';
const char Space = ' ';

// functions
void showInstructions();
void showBoard(char theBoard[],int size);
int getMove(char theBoard[], char player);
bool checkWin(char theBoard[]);
bool checkTie(char theBoard[], int size);

int main()
{
    char repeat1;
    bool  repeat = true;
    while(repeat == true)
    {
        showInstructions();

        bool win = false, tie = false;
        int size =9;
        char player = X, index;
        char theBoard[] = {'0','1','2','3','4','5','6','7','8'};
        //  0-8 in the array so it can be displayed later as [0][1][2] etc.
        while(win == false && tie == false)
            {
                showBoard(theBoard,size);
                theBoard[getMove(theBoard,player)] = player; // getting the move
                if(player == X)
                {
                    player = O; //switches player
                }
                else
                {
                    player = X;
                }
                win = checkWin(theBoard);
                tie = checkTie(theBoard, size);//These two functions are checking if its a tie or someone won.
            }
            if(player == X)
            {
                player = O;
            }
            else
            {
                player = X; // switched back to the winning player because if left alone it would still switch them.
            }
            showBoard(theBoard,size);
            if(win == true)
            {
                cout<< "Congrats you won. Player:"<< player<<endl;

            }//displays the winning move
            else if( tie == true)
            {
                cout << "its a tie"<<endl;
            }//if a tie happens then outputs message saying its a tie
            cout<<"play again?" << endl;
            cin >> repeat1;
            switch(repeat1)
            {
            case 'y':
                repeat = true;
                break;
            case 'n':
                repeat = false;
                cout<<" Thanks for playing" << endl;
                break;
            }


    }


    return 0;
}
void showInstructions()
    {
        cout<< "Hello welcome to the game tic tac toe."<<endl;
        cout<< "How to play: "<<endl;
        cout<< "1) Select the spot you want by entering the corresponding number."<< endl;
        cout<< "2) If theres already a value there you can't choose that spot."<<endl;
        cout<< "3) If you have three in a row vertically, horizontally, or diagonally you win."<<endl;
        cout<< "4) at the end of the game please use y as in yes and n as in no"<<endl;

    }// function that displays the direction.
void showBoard(char theBoard[],int size)
{
    for(int i = 0; i<size; i++)
        {
            cout<< "["<< theBoard[i]<<"]";
            if(i == 2 || i == 5 || i == 8)
            {
                cout<<endl;
            }
        }
    //this loop is for displaying the board.
    }
int getMove(char theBoard[], char player)
{
    int spot;
    bool move;
    cout<<"Please choose your move"<<endl;
    cin>>spot;
    if( theBoard[spot] == X || theBoard[spot] == O || spot > 8)
    {
        move = false;
        while(move == false)
        {
            cout << " Error bad input. Try another one."<<endl;
            cin >> spot;
            if(theBoard[spot] != X && theBoard[spot] != O && spot < 9)
            {
                move = true;
            }

        }
    }
    return spot;
}
// this functions checks if the player moves is good and selects it.
bool checkWin(char theBoard[])
{
    if( theBoard[0] == X && theBoard[1] == X && theBoard[2]== X)
    {
        return true;
    }
    else if(theBoard[3] == X && theBoard[4] == X && theBoard[5]== X)
    {
        return true;
    }
    else if(theBoard[6] == X && theBoard[7] == X && theBoard[8]== X)
    {
        return true;
    }
    else if(theBoard[0] == X && theBoard[3] == X && theBoard[6]== X)
    {
        return true;
    }
    else if(theBoard[1] == X && theBoard[4] == X && theBoard[7]== X)
    {
        return true;
    }
    else if(theBoard[2] == X && theBoard[5] == X && theBoard[8]== X)
    {
        return true;
    }
    else if(theBoard[0] == X && theBoard[4] == X && theBoard[8]== X)
    {
        return true;
    }
    else if(theBoard[2] == X && theBoard[4] == X && theBoard[6]== X)
    {
        return true;
    }
    else if( theBoard[0] == O && theBoard[1] == O && theBoard[2]== O)
    {
        return true;
    }
    else if(theBoard[3] == O && theBoard[4] == O && theBoard[5]== O)
    {
        return true;
    }
    else if(theBoard[6] == O && theBoard[7] == O && theBoard[8]== O)
    {
        return true;
    }
    else if(theBoard[0] == O && theBoard[3] == O && theBoard[6]== O)
    {
        return true;
    }
    else if(theBoard[1] == O && theBoard[4] == O && theBoard[7]== O)
    {
        return true;
    }
    else if(theBoard[2] == O && theBoard[5] == O && theBoard[8]== O)
    {
        return true;
    }
    else if(theBoard[0] == O && theBoard[4] == O && theBoard[8]== O)
    {
        return true;
    }
    else if(theBoard[2] == O && theBoard[4] == O && theBoard[6]== O)
    {
        return true;
    }
    else
    {
        return false;
    }
}// this checks if a player has one by going every possibility in tic tac toe.
bool checkTie(char theBoard[],int size)
{

    for(int i = 0; i < size; i++)
    {
        if(theBoard[i] != X && theBoard[i] != O)
        {
            return false;
        }
    }
    return true;
}// this checks if the game is a tie by going through the array and if there no more available spots
//and the checkWin hasn't return true then automatically its a tie.
