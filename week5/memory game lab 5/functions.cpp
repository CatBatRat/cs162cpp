#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;
#include "functionDec.h"

// cout << endl;

void instructions()
{
    cout << "Welcome to The Memory Game!" << endl;
    cout << "Choose two numbers (one at a time) and letters will be shown." << endl;
    cout << "If the two letters match then you got a pair!" << endl;
    cout << "Find all 8 letter pairs in the shortest amount of moves." << endl;
    cout << "Can you beat your own score?" << endl;
}

//-------------------------------------------------------------------------
string* initilize()
{
    string* matchBacks = new string [ARRAYLENGTH] {"0" , "1" , "2" , "3" ,
                                                   "4" , "5" , "6" , "7" ,
                                                   "8" , "9" , "10" ,"11" ,
                                                   "12", "13" ,"14" ,"15"}; //dynamically creating array


    return matchBacks;
}

//-------------------------------------------------------------------------
string* initilizeSymbolArr() //I tried to change this from a char to a string and thats when the bug started happening.
{

    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int F = 0;
    int G = 0;
    int H = 0;

    int randNumb;

    string* symbols = new string [ARRAYLENGTH]; //dynamically creating array

    for(int i = 0; i < ARRAYLENGTH; i++)
    {
      symbols[i] = FILLER;
    }

    while(A < PAIR) //for the A pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "A";
            A++;
        }
    }

    while(B < PAIR) //for the B pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "B";
            B++;
        }
    }

    while(C < PAIR)//for the C pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "C";
            C++;
        }
    }

    while(D < PAIR) //for the D pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "D";
            D++;
        }
    }

    while(E < PAIR) //for the E pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "E";
            E++;
        }
    }

    while(F < PAIR) //for the F pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "F";
            F++;
        }
    }

    while(G < PAIR) //for the G pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "G";
            G++;
        }
    }

    while(H < PAIR) //for the H pairs
    {
    randNumb = rand() % 16;
        if(symbols[randNumb] == FILLER)
        {
            symbols[randNumb] = "H";
            H++;
        }
    }
    cout <<"A"<< " " <<"B"<< " " <<"C"<< " " <<"D"<< " " <<"E"<< " " <<"F"<< " " <<"G"<< " " <<"H"<< endl;
    cout << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << " " << H << endl;

    return symbols;
}

//-------------------------------------------------------------------------
void displayBacks(string *matchBacks)
{
for(int i = 0; i < ROW; i++)
    {
       for(int j = 0; j < COL; j++)
       {
          cout << setw(3) << *(matchBacks + (i*ROW)+ j) << " ";
       } //end forloop j
        cout << endl;
    }//end forloop i
}

//-------------------------------------------------------------------------
void displaypairs(string *matchSymbols)
{
for(int i = 0; i < ROW; i++) //printing rows
    {
       for(int j = 0; j < COL; j++) // printing col
       {
           cout << setw(3) << *(matchSymbols + (i*ROW)+ j) << " ";
       }
        cout << endl;
    }
}

//-------------------------------------------------------------------------

/*
int getmove1(string *matchSymbols, string *matchBacks)
{
    int number;

    cout << "Enter a number to begin " << endl;
    cin >> number;

    if(*(matchSymbols + number) != FILLER)
    {
      switch(number)
        {
            case 0:
            cout << "you chose 0 and that spot is available." << endl;

            break;
            default:
            cout << "That number is not available" << endl;
        }
    }
return 0;
}
*/




