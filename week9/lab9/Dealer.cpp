#include <string>
#include "Dealer.h"

std::string Dealer::showHand() {
    std::string sub = myHand->getAllCardCodes();
    return "XX " + sub.substr(3,sub.length());
}

void Dealer::shuffle() {
    theDeck->reset();
    theDeck->shuffle(5);
}
