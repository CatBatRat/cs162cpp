#include <iostream>

using namespace std;

int main() {

    int index = 0;
    bool refer[8] = {};
    int test[8] = {};

    for( int r=0; r<8; r++ )
        refer[r] = false;
    for( int t=0; t<8; t++ )
        test[t] = t;
    do
    {
        cin >> index;
        refer[index] = true;
        for( int t=0; t<8; t++ )
        {
            if( refer[t] )
                cout << test[t] << endl;
            else
                cout << "nothing" << endl;
        }
        cout << "\n\n\n\n";
    } while( true );

    return 0;
}
