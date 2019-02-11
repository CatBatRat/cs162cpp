#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;
#include "functionDec.h"


int main()
{
srand (time(NULL));

instructions();

/*
t_move thisIsATest = {10, 20}; //when you are calling a struct, you have to give a nickname to the information you want to store.
// you put the information you want to store in order in the brackets. (first in the struct is "test1" so the first thing in the brackets will be stored there. add a coma to separate things.

cout << thisIsATest.test1 << endl; //use the nickname and the name of the variable you want to call from the struct.
cout << thisIsATest.test2 << endl;
*/

string *matchBacks = initilize();

string *matchSymbols = initilizeSymbolArr(); //problem here


cout << endl << endl;
displayBacks(matchBacks);


cout << endl;
cout << "Cheat Sheet" << endl;
displaypairs(matchSymbols);


return 0;
}
