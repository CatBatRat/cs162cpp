
//Find and fix the problems with this program

#include <iostream>

using namespace std;

class Demo {
    private:
        int value;
    public:
        int getValue() const { return value; }
        void display() const;
        void setValue(int value) { this->value = value; }
        void getInput();
};

void Demo::display() const
{
    cout << getValue() << endl;
}

void Demo::getInput()
{
    cout << "Enter an integer";
    cin >> value;
    setValue(value);
}

int main()
{
    Demo sue;

    sue.getInput();
    sue.display();

    return 0;
}
