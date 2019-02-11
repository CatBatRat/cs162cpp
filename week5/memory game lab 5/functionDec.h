#ifndef FUNCTIONDEC_H_INCLUDED
#define FUNCTIONDEC_H_INCLUDED



struct t_move
{
  int test1;
  int test2;

};

const int ARRAYLENGTH = 16;
const int ROW = 4;
const int COL = 4;
const int PAIR = 2;
const string FILLER = "O";


//-------------------------------------------------------------------------

string* initilize();

string* initilizeSymbolArr();

void instructions();

void displayBacks(string *matchBacks);

void displaypairs(string *matchSymbols);





#endif // FUNCTIONDEC_H_INCLUDED
