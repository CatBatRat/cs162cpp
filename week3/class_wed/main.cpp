#include <iostream>

using namespace std;
bool recFind(int arr[], int size, int value, int index)
{
    if( index >= size)
        return false;
    if( arr[index] == value )
        return true;
    return recFind( arr, size, value, index+1);
}
bool linFind(int arr[], int size, int value) {
    return recFind (arr, size, value, 0);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};

    int value;
    do {
        cout << "enter number" << endl;
        int value;
        cin >> value;
        if ( linFind(arr, 12, value))
            cout << "found" << endl;
        else
            cout << "not found" << endl;

    } while ( linFind( value ) )
}
