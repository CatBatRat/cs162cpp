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

/*#include <iostream>

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

}*/


/*#include <iostream>

#include <iomanip>   // used to format output in neat columns

using namespace std;

// constants for array

const int ROW = 5;

const int COL = 5;

// When passing a multidimensional array you must pass bounds for all dimensions except the first
void showArray(int arr[][5]);

int main()

{

    // define the array in main

    int arr[ROW][COL];

    

    // for loops for arrays should start 0.
    for(int i = 0; i < ROW; i++)

        for(int j = 0; j < COL; j++)

            // Shot in the dark but if this should be a multiplication table then should be (i+1) * (j+1)
            arr[i][j] = (i+1) * (j+1);

    

    showArray(arr);

    return 0;

}

// function to display array, using setw to align columns

void showArray(int arr[][COL])

{

        // loop to output the rows, one at a time

    // must be < not <= , array out of bounds
    for(int i = 0; i < ROW; i++)

    {

            // loop to output the values in that row

        for(int j = 0; j < COL; j++)

        {

            cout << setw(4) << arr[i][j];

        }

            // end this line of output

        cout << endl;

    }

        // put final endline after table

    cout << endl;

}*/

/*#include <iostream>

using namespace std;

int main()

{

    const int SIZE = 6;

    int arr[SIZE];

    // <= will over step array bounds. use < instead
    for(int i = 0; i < SIZE; i++)

    {

        cout << "Enter next value:";

        cin >> arr[i];

    }

    // sum should start at a value, or else whatever was in memory where the
    // variable was created will be contained in the var
    int sum = 0;

    // use < here as well. this is an array being accessed
    for(int i = 0; i < SIZE; i++)

    {

        sum += arr[i];

    }

    cout << "The sum is " << sum << endl;

    return 0;    

}*/

#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

const int HEIGHT = 6;
const int WIDTH = 10;
void fillArray( int arr[][WIDTH] );
void showArray( int arr[][WIDTH] );
int main()
{
    srand(static_cast<int>(time(nullptr)));

    int arr[HEIGHT][WIDTH] = {};

    fillArray( arr );
    showArray( arr );

    return 0;
}

void fillArray( int arr[][WIDTH] )
{
    for( int h=0; h<HEIGHT; h++ )
    {
        for( int w=0; w<HEIGHT; w++ )
        {
            arr[h][w] = rand() % 99 + 1;
        }
    }
}

void showArray( int arr[][WIDTH] )
{
    int rowSum = 0, h = 0, w = 0;
    while( h < HEIGHT )
    {
        while( w < WIDTH )
        {
            cout << setw(3) << left << arr[h][w];
            rowSum += arr[h][w];
            w++;
        }
        cout << "= " << rowSum << endl;
        rowSum = 0;
        h++;
    }
}
