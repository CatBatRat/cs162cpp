#include <string>
#include "CreditCard.h"

using std::string;


CreditCard::CreditCard( string fName, string lName, string address, int CN, double cLimit ):
    cardNum(CN), creditLimit(cLimit), balance(0)
    { setOwnerName( fName, lName ); setAddress(address); }

void CreditCard::setOwnerName( string F, string L ) {
    pe.setFirstName(F);
    pe.setLastName(L);
}
string CreditCard::getOwnerName() {
    return pe.getFirstName() + " " + pe.getLastName();
}

void CreditCard::setCreditLimit( double creditLimit ) {
    if( creditLimit >= 0 )
        this->creditLimit = creditLimit;
    else
        creditLimit = 0;
}

bool CreditCard::makeCharge( double charge ) {
    bool valid = false;
    if( charge > 0 and charge+balance<creditLimit ) {
        balance += charge;
        valid = true;
    }
    return valid;
}

bool CreditCard::payBalance( double pay ) {
    bool valid = false;
    if( pay > 0 ) {
        balance -= pay;
        valid = true;
    }
    return valid;
}
