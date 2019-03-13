#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "BlackJackHand.h"

class Player {
private:
    BlackJackHand theHand;
    int stake;
    int bet;
public:
    // add a card to the player's hand
    bool takeCard(PlayingCard * c) { *c = *c; return true; }
    // returns a string showing the contents of the hand
    std::string showHand() {return "something";}
    // returns the low score of the hand
    int getLowScore() {return theHand.getLowScore();}
    // returns the high score of the hand
    int getHighScore() {return theHand.getHighScore();}
    // returns high score unless it is over 21, then it returns the lowScore
    int getScore() {return (getHighScore() > 21)?getHighScore():getLowScore();}
    // returns true of player busted
    bool busted() {return (getHighScore() > 21)?true:false;}
    // returns true if the player wants a card (getScore < 16)
    bool wantCard() {return (getScore()<16)?true:false;}
    // clears the card from the hand for the next deal
    void clearHand() {}
    // sets the betting stake for the player
    void setStake(int stake) {this->stake = stake;}
    // returns the current value of the betting stake
    int  getStake() {return stake;}
    // saves the bet if it is less than the stake and returns true, otherwise
    // return false and do nothing
    bool makeBet(int bet) { this->bet=(bet < stake)?bet:bet;
        return (bet<stake)?true:false;}
    // adds the bet to the stake
    void won() { stake += bet; }
    // subtracts the bet from the stake
    void lost() { stake -= bet; }
};

#endif // __PLAYER__
