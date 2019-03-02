#include <string>

#ifndef __PERSON__
#define __PERSON__

using std::string;

class Person {
    string firstName;
    string lastName;
    string address;
public:
    // Default constructor sets all values to "".
    Person(): firstName(""), lastName(""), address("") {}
    // Overloaded constructor.
    // I know this takes more than one line, but I didn't feel it was needed to
    // make another cpp file just to hold one overloaded constructor.
    Person( string firstName, string lastName, string address ):
        firstName(firstName), lastName(lastName), address(address) {}
    // Sets and gets firstName and lastName.
    void   setFirstName(string F) { firstName = F; }
    string getFirstName() { return firstName; }
    void   setLastName(string L) { lastName = L; }
    string getLastName() { return lastName; }
    // Sets and gets address.
    void   setAddress(string A) { address = A; }
    string getAddress() { return address; }
};

#endif //__PERSON__
