#include <string>
#include "Dealer.h"

Dealer::Dealer() {
    theDeck = new PlayingCardDeck;
}

Dealer::Dealer(int numShuffles) {
    theDeck = new PlayingCardDeck( numShuffles );
}

Dealer::~Dealer() {
    delete theDeck;
}

std::string Dealer::showHand() {
    std::string sub = myHand->getAllCardCodes();
    return "XX " + sub.substr(3,sub.length());
}

std::string Dealer::fullHand() {
    return theDeck->getAllCardCodes();
}

PlayingCard * Dealer::dealCard() {
    return theDeck->dealCard();
}

int Dealer::cardsLeft() {
    return theDeck->getCountRemain();
}

void Dealer::shuffle() {
    theDeck->reset();
    theDeck->shuffle(5);
}
