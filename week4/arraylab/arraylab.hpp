#ifndef __ARRAY_LAB__
#define __ARRAY_LAB__

void recSelectionSort( int sorted[], int * size, int index=0 );
int findSmallest( int numset[], int size, int index );
void swapper( int * left, int * right );

bool binSearch( int searched[], int size, int fnd, int index=0 );

int getSize();
void fillArray( int tarray[], int * size );
void displayArray( int tarray[], int * size );

#endif //__ARRAY_LAB__
