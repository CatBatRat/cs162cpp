#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "PlayingCardDeck.h"

class Dealer : public Player
{
    private:
        PlayingCardDeck * theDeck;

    public:
        Dealer() { theDeck = new PlayingCardDeck; }
        Dealer(int numShuffles) { theDeck = new PlayingCardDeck( numShuffles ); }
        ~Dealer() { delete theDeck; }
        std::string showHand();
        std::string fullHand() { return myHand->getAllCardCodes(); }
        PlayingCard * dealCard() { return theDeck->dealCard(); }
        int cardsLeft() { return theDeck->getCountRemain(); }
        void shuffle();
};

#endif
