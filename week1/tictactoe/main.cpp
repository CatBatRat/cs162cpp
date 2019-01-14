#include <iostream>
#include "tictac.hpp"

using namespace std;

int main() {

    bool again;

    do {

        dialog("instructions");

        switch( gameLoop() ) {
            case 0:
                dialog("draw");
                break;
            case 1:
                dialog("p1win");
                break;
            case 2:
                dialog("p2win");
                break;
        }
        dialog("again");
        char choice;
        cin >> choice;
        if( choice == 'y' or choice == 'Y' ) {
            again = true;
        }
        else {
            again = false;
        }
    } while( again );

    return 0;
}
