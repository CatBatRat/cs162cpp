/*#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 5;

void makeTable( int table[][SIZE] );
void showTable( int table[][SIZE] );

int main() {

    int table[SIZE][SIZE] = {};

    makeTable( table );
    showTable( table );

    return 0;
}

void makeTable( int table[][SIZE] )
{
    for ( int y=0; y<SIZE; y++ )
    {
        for ( int x=0; x<SIZE; x++ )
        {
            table[y][x] = (y+1) * (x+1);
        }
    }

}

void showTable( int table[][SIZE] )
{
    for ( int y=0; y<SIZE; y++ )
    {
        for ( int x=0; x<SIZE; x++ )
        {
            cout << setw(3) << left << table[y][x] << " ";
        }
        cout << endl;
    }
}*/

/*#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 5;

    // mismatch between the declared size of the array and the number of
    // elements.
    int arr[SIZE] = { 1, 3, 5, 7, 9 , 11 };

    // the <= will cause an array out of bounds becuase the size of the array
    // is not the same as the ending index but is instead one less.
    for(int i = 0; i <= SIZE; i++)
        cout << arr[i] << endl;

    return 0;

}*/

#include <iostream>

using namespace std;

int main()

{
    int length;
    cout << "Enter the number of values" << endl;
    cin >> length;

    // Must be plus one to include all values entered by the user.
    int array[length+1];

    cout << "Now enter the values, one per line" << endl;

    // Start at 0 to fill all elements. Index 0 is being skipped
    for(int i = 0; i < length; i++)
        cin >> array[i];

    // The char 'o' cannot be used as an index. Use 0 instead.
    int smallest = array[0];
    for(int i = 1; i < length; i++)
        if ( smallest > array[i] )
            smallest = array[i];

    cout << "The smallest value is " << smallest << endl;

    return 0;

}
