#include <iostream>

using namespace std;

struct Student {
    string name;
    int grade;
}; // Needs a colon here.

int main()
{
    struct Student mary;

     mary.name = "Mary"; // Accessor for struct member is .
                         // and variables are case sensitive

     mary.grade = 100;

     // Missing a << here.
     cout << mary.name << " got a " << mary.grade << endl;

    return 0;

}
