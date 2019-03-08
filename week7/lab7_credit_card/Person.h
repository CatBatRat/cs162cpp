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
    Person( string fName, string lName, string address ):
        firstName(fName), lastName(lName), address(address) {}
    // Sets and gets firstName and lastName.
    void   setFirstName(string firstName) { this->firstName = firstName; }
    string getFirstName() { return firstName; }
    void   setLastName(string lastName) { this->lastName = lastName; }
    string getLastName() { return lastName; }
    // Sets and gets address.
    void   setAddress(string address) { this->address = address; }
    string getAddress() { return address; }
};

#endif //__PERSON__
