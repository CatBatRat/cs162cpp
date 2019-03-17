#include "Dealer.h"
#include <iostream>
using namespace std;
Dealer::Dealer() {
    this->theDeck = new class PlayingCardDeck();
    //int numShuffles = 0;
}
Dealer::Dealer(int numShuffles)
{
    int numS = numShuffles;
    theDeck->reset();
    theDeck->shuffle(numS);
}
Dealer::~Dealer()
{
    delete theDeck;
}
string Dealer::showHand() {
    return "XX";
}
string Dealer::fullHand()
{
    return theDeck->getAllCardCodes();
}
PlayingCard * Dealer::dealCard() {
    return theDeck->dealCard();
}
int Dealer::cardsLeft() //APPROVED
{
    return theDeck->getCountRemain();
}
void Dealer::shuffle() {
    int numS = 1;
    theDeck->reset();
    theDeck->shuffle(numS);
}
