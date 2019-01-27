#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main() {

    cout << "Hello World!" << endl;
    int temp;
    int test1[] = { 5, 2, 8, 1, 4, 3, 9, 3 };

    for( int p=0; p<8; p++ )
    {
        for( int x=0; x<8; x++ )
        {
            if( x<8 )
            {
                if( test1[x]>test1[x+1] )
                {
                    temp = test1[x];
                    test1[x] = test1[x+1];
                    test1[x+1] = temp;
                }
            }
        }
    }
    for( int n=0; n<8; n++ )
    {
        cout << test1[n] << endl;
    }

    int test2[] = { 5, 2, 8, 1, 4, 3, 9, 3 };

    temp = 0;
    for( int p=8; p>=0; p )
    {
        for( int x=0; x<8; x++ )
        {
            if( x<0 )
            {
                if( test2[x]>test2[x+1] )
                {
                    temp = test2[x];
                    test2[x] = test2[x+1];
                    test2[x+1] = temp;
                }
            }
        }
    }

    std::string hold = "";
    cout << "Press Enter.";
    std::getline(cin, hold);

    return 0;
}
