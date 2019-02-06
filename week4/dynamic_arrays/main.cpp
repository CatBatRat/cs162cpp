#include <iostream>

using namespace std;

class myArray
{
    public:
        int *arr;
        myArray( int y, int x )
        {
            arr = new int[y*x];
        }
};

int main()
{

    myArray a( 5, 6 );
    cout << a.arr[0];
    delete &a;

    return 0;
}
