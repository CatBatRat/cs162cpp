#include <iostream>
#include <random>

using namespace std;

const int SIZE = 17;


int main() {
    srand(static_cast<int>(time(nullptr)));

    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    //int nums[SIZE] = {};
//#define _forward
#define _reverse
#ifdef _forward
    for( int i=0; i<SIZE-1; i++ )
    {
        int j = SIZE - i - 1;
        int l = rand() % j + i + 1;
        //cout << nums[i] << " " << nums[j] << endl;
        nums[i] ^= nums[l];
        nums[l] ^= nums[i];
        nums[i] ^= nums[l];
    }
#endif // _forward
#ifdef _reverse
    for( int i=SIZE-1; i>0; i-- )
    {
        int l = rand() % i;
        //cout << nums[i] << " " << nums[l] << endl;
        nums[i] ^= nums[l];
        nums[l] ^= nums[i];
        nums[i] ^= nums[l];
    }
#endif // _reverse

    for( int s=0; s<SIZE; s++ )
        cout << nums[s] << endl;

    return 0;
}
