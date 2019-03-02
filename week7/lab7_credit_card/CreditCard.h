#include <string>

#ifndef __CREDIT_CARD__
#define __CREDIT_CARD__

#include "Person.h"

using std::string;

class CreditCard {
    Person pe;
    int     cardNum;
    double  creditLimit;
    double  balance;
public:
    CreditCard(): cardNum(0), creditLimit(0), balance(0) {}
    CreditCard( string fName, string lName, string address, int cNum, double cLimit );
    // Set and gets first and last of Person.
    void   setOwnerName( string fName, string lName ); // v/
    string getOwnerName();
    // Sets and gets address of Person.
    void   setAddress( string A ) { pe.setAddress(A); }
    string getAddress() { return pe.getAddress(); }
    // Sets and gets cardNumber.
    void   setCardNumber( int cNum ) { cardNum = cNum; }
    int    getCardNumber() { return cardNum; }
    // Sets and gets creditLimit.
    void   setCreditLimit( double climit );
    double getCreditLimit() { return creditLimit; }
    // Adds charge to balance.
    bool   makeCharge( double charge );
    // Decreases balance based on payment.
    bool   payBalance( double pay );
    // returns the current balance on the card.
    double getBalance() { return balance; }
};

#endif //__CREDIT_CARD__
