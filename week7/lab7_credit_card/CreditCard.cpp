#include <string>
#include "CreditCard.h"

using std::string;


// Overloaded constructor that that allows setting first name, last name, and address in 'Person' and
// sets card number and credit limit in 'CreditCard'. Also instantiates balance at 0.
CreditCard::CreditCard( string fName, string lName, string address, int CN, double cLimit ):
    pe( fName, lName, address ), cardNum(CN), creditLimit(cLimit), balance(0) {}

// Set the owners name by changing the private values in 'Person' using it's setters.
void CreditCard::setOwnerName( string F, string L ) {
    pe.setFirstName(F);
    pe.setLastName(L);
}
// Use the getters in 'Person' to return the first name and last name values from
// 'Person' as a string.
string CreditCard::getOwnerName() {
    return pe.getFirstName() + " " + pe.getLastName();
}

// Credit limit can be set to a value lower than the current balance, but should
// not be set to value less than 0.
void CreditCard::setCreditLimit( double creditLimit ) {
    if( creditLimit >= 0 )
        this->creditLimit = creditLimit;
    else
        creditLimit = 0;
}

// Charge can only be made if the amount of charge + balance does not
// exceed the credit limit.
bool CreditCard::makeCharge( double charge ) {
    bool valid = false;
    if( charge > 0 and charge+balance<creditLimit ) {
        balance += charge;
        valid = true;
    }
    return valid;
}

// Payments to pay off balance must be greater than 0.
bool CreditCard::payBalance( double pay ) {
    bool valid = false;
    if( pay > 0 ) {
        balance -= pay;
        valid = true;
    }
    return valid;
}
