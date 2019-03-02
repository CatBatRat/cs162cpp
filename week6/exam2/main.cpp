#include <iostream>

using namespace std;

const int LEN = 10;

int * makeArray();
void displayArray( int * arr );

int main() {

    int * nums = makeArray();

    displayArray( nums );

    delete[] nums;

    return 0;
}

int * makeArray()
{
    int * temp = new int[LEN];
    int oddCount = 0;
    int numCount = 0;
    while( oddCount < LEN )
    {
        if( numCount % 2 != 0 )
        {
            temp[oddCount] = numCount;
            oddCount++;
        }
        numCount++;
    }
    return temp;
}

void displayArray( int * arr )
{
    for( int x=0; x<LEN; x++ )
    {
        cout << arr[x] << " ";
    }

}
