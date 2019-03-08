#include <iostream>
#include <sstream>

using namespace std;

ostream & outTest(ostream & out)
{

    out << "this is a test of the string transfer system!";

    return out;
}

int main() {

    cout << "Hello World!" << endl;

    cout << outTest;

    return 0;
}
