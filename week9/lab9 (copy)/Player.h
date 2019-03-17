#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "BlackJackHand.h"

class Player {
private:
    int stake;
    int bet;
protected:
    BlackJackHand * myHand;
public:
    Player();
    Player( int stake );
    ~Player();
    // add a card to the player's hand
    bool takeCard(PlayingCard * c);
    // returns a string showing the contents of the hand
    std::string showHand();
    // returns the low score of the hand
    int getLowScore();
    // returns the high score of the hand
    int getHighScore();
    // returns high score unless it is over 21, then it returns the lowScore
    int getScore();

    // returns true of player busted
    bool busted();
    // returns true if the player wants a card (getScore < 16)
    bool wantCard();
    // clears the cards from the hand for the next deal
    void clearHand();
    // sets the betting stake for the player
    void setStake(int stake);
    // returns the current value of the betting stake
    int  getStake();
    // saves the bet if it is less than the stake and returns true, otherwise
    // return false and do nothing
    bool makeBet(int bet);
    // adds the bet to the stake
    void won();
    // subtracts the bet from the stake
    void lost();
};

#endif // __PLAYER__
