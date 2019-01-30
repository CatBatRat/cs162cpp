#include <iostream>

using namespace std;

int main() {

    cout << "Hello World!" << endl;
    int size;
    cin >> size;
    int *myarray = new int[size];
    for ( int i=0; i<size; i++ )
        cin >> *(myarray+i);
    for ( int i=0; i<size; i++ )
        cout << *(myarray+i) << " ";
    delete[] myarray;

    return 0;
}
