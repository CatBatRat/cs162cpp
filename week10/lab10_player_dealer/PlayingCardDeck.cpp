#include <iostream>
#include <sstream>
#include <random>
#include <iomanip>
#include "PlayingCardDeck.h"

PlayingCardDeck::PlayingCardDeck()
{
    makeDeck();
}

PlayingCardDeck::PlayingCardDeck( int numShuffles )
{
    makeDeck();
    shuffle( numShuffles );
}

PlayingCardDeck::~PlayingCardDeck()
{
    clearDeck();
}

void PlayingCardDeck::clearDeck()
{
    for( int d=0; d<DECK_SIZE; d++ )
    {
        delete theDeck[d];
        theDeck[d] = nullptr;
    }
}

void PlayingCardDeck::reset()
{
    clearDeck();
    makeDeck();
    countUsed = 0;
    countRemain = DECK_SIZE;
}

bool PlayingCardDeck::shuffle(int numShuffles)
{
    bool noShuffle = false;
    PlayingCard * tempCard;
    if( countUsed == 0 )
    {
        noShuffle = true;
        for( int s=0; s<numShuffles; s++ )
        {
            for( int i=DECK_SIZE-1; i>0; i-- )
            {

                int l = rand() % i;
                //cout << nums[i] << " " << nums[l] << endl;
                tempCard = theDeck[i];
                theDeck[i] = theDeck[l];
                theDeck[l] = tempCard;
            }
        }
    }
    return noShuffle;
}
void PlayingCardDeck::makeDeck()
{
    countUsed = 0;
    countRemain = DECK_SIZE;
    char values[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    char suits[] = {'C','H','D','S'};
    int index = 0;
    for( int s=0; s<SUITS; s++ )
    {
        for( int c=0; c<CARDS; c++ )
        {
            theDeck[index++] = new PlayingCard(values[c], suits[s]);
        }
    }
}

PlayingCard * PlayingCardDeck::dealCard()
{
    if( countRemain > 0 )
    {
        countRemain -= 1;
        PlayingCard * temp = theDeck[countUsed];
        theDeck[countUsed++] = nullptr;
        return temp;
    }
    return nullptr;
}

std::string PlayingCardDeck::getAllCardCodes()
{
    std::ostringstream os;
    int counter = 0;
    bool notEmpty = false;
    for( int d=0; d<DECK_SIZE; d++ )
    {
        counter++;
        if( theDeck[d] )
        {
            notEmpty = true;
            os << std::setw(3) << std::left
                << theDeck[d]->getCardCode();
        }
        if( counter >= 13 )
        {
            counter = 0;
            if( notEmpty )
                os << std::endl;
        }
    }
    return os.str();
}
