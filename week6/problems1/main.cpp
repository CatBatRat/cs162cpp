#include <iostream>

using namespace std;

void display( int nums[] );
bool recFind(int arr[], int length, int index, int value);

int main() {

    int nums[] = {2,6,2,9,7,12};

    int fnd;
    while( true )
    {
        display( nums );
        cout << "Number to search for: " << endl;
        cin >> fnd;
        if(recFind(nums, 6, 0, fnd))
            cout << "Found it!" << endl;
        else
            cout << "Not there." << endl;
    }

    return 0;
}

bool recFind(int arr[], int length, int index, int value)

{
    if (index >= length)
        return false;
    if ( arr[index] == value )
        return true;

    return recFind(arr, length, index+1, value);
}

void display( int nums[] )
{
    for( int x=0; x<6; x++ )
        cout << nums[x] << endl;
}
