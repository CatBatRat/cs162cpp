#include <iostream>

using namespace std;

class Demo {
     private:
          int value;
     public:
          // make const to work with const reference
          int getValue() const { return value; }
          // Use this-> to allow the use of the save var name
          void setValue(int value) { this->value = value; }
};


void display( const Demo & d )
{
    cout << "The value of sue is ";
     cout << d.getValue() << endl;
}

// can't change values is passing as const
// Also needs to be part of Demo
void getInput( Demo & d )
{
     // Need to have a var for value.
     int value;
     cout << "Enter an integer: ";
     cin >> value;
     d.setValue(value);
}

int main()
{
    Demo sue;

    // getInput not getinput and should pass the object to the function.
    getInput(sue);
    display(sue);

    return 0;
}
