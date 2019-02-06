#ifndef __ARRAY_LAB__
#define __ARRAY_LAB__

// Set values for min and max array size for input validation, min and max
// random range, and number of loops to perform when asking the user for a
// number to search for.
const int AMIN = 10, AMAX = 20, RMIN = 1, RMAX = 99, LOOPS = 3;

// A selection sort using recursion. Iteration would have been better but I
// wanted to force myself to get more comfortable with recursion, as it is
// still a bit foreign to me.
//void recSelectionSort( int *arr, int *size, int index=0 );

// Iterative version of selection sort.
void iterSelectionSort( int * arr, int * size );
// Simply find the smallest number in an array for use in the sorting function.
// Called with index increased by one to keep from wasting time searching when
// the smallest of the last iteration has already been found.
int findSmallest( int *arr, int size, int index );
// Simple function to swap two values using index of the values.
void swapper( int *left, int *right );


// Gets the size of the array from the user and stores it.
int getSize();
// Makes the array in newly allocated memory and returns the address of the
// array to a pointer.
int * makeArray( int *size );
// Displays the array with optional number of items per line.
void displayArray( int *arr, int *size, int line );

// Prompts the user for a series of numbers to attempt to find in the array and
// report whether they are present or not.
void findInArray( int *arr, int *size );
// Recursive binary search. Binary search as excellent choice to make recursive
// because they it take so few checks to find an item even in a very large data
// set.
bool binSearch( int *arr, int size, int fnd, int index=0 );

#endif // __ARRAY_LAB__
