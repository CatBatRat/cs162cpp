#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "PlayingCardDeck.h"

class Dealer : public Player
{
    private:
        PlayingCardDeck * theDeck;

    public:
    	Dealer();
    	Dealer(int numShuffles);
        ~Dealer();
        std::string showHand();
        std::string fullHand();
        PlayingCard * dealCard();
        int cardsLeft();
        void shuffle();
};

#endif
