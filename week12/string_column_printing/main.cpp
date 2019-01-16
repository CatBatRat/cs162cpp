#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string col = "ww ss a d a d";
    for( auto s : col ) {
        switch( s ) {
            case 'w': cout << "Up" << endl; break;
            case 'a': cout << "Left" << endl; break;
            case 's': cout << "Down" << endl; break;
            case 'd': cout << "Right" << endl; break;
        }
    }
    return 0;
}
