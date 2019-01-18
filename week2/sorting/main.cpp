#include <iostream>
#include <random>

using namespace std;

const int SIZE = 20;

    void fillArray(int arr[]);
    //void mySort(int arr[], int theSize);
    void display(int arr[]);
int main() {

    srand(static_cast<int>(time(0)));
    int theArray[SIZE];
    fillArray(theArray);
    display(theArray);
    mySort(theArray);

    return 0;
}


void fillArray(int arr[]) {
    for( int x=0; x<SIZE; x++ ) {
        arr[x] = rand() % 100 + 1;
    }
}

void display(int arr[]) {
    for( int i=0; i<SIZE; i++ ) {
        cout << arr[i] << " ";
    }
}

void mySort(int arr[])
{
    int Max = 0;
}




