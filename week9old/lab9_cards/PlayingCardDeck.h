#include <iostream>
#include <sstream>

#ifndef __PLAYING_CARD_DECK__
#define __PLAYING_CARD_DECK__

#include "PlayingCard.h"

class PlayingCardDeck {

    private:
        static const int SUITS = 4;
        static const int CARDS = 13;
        static const int DECK_SIZE = 52;
        PlayingCard * theDeck[DECK_SIZE];

        // reset these when calling reset.
        int countUsed;
        int countRemain;

        void makeDeck();
        void clearDeck();
    public:
        PlayingCardDeck();
        PlayingCardDeck( int numShuffles );

        int getCountUsed() { return countUsed; }
        int getCountRemain() { return countRemain; }

        PlayingCard * dealCard();

        void reset();
        bool shuffle(int numShuffles);

        std::string getAllCardCodes();

        ~PlayingCardDeck();
};

#endif // __PLAYING_CARD_DECK__
