#include <iostream>

using namespace std;

int main() {

    const int contest = 5;

    const int *c = &contest;

    int contest2 = 12;

    int * const c2 = &contest2;

    cout << *c << endl;
    cout << *++c << endl;
    cout << *c2 << endl;
    *c2 += 8;
    cout << *c2 << endl;

    return 0;
}
