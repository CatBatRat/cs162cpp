#include <iostream>
#include <string>
#include "Player.h"

Player::Player(): stake(0) {
    myHand = new BlackJackHand;
}

Player::Player( int stake ): stake(stake) {
    myHand = new BlackJackHand;
}

Player::~Player() {
    delete myHand;
}

// add a card to the player's hand
bool Player::takeCard(PlayingCard * c) {
    return myHand->addCard(c);
}

// returns a string showing the contents of the hand
std::string Player::showHand() {
    return myHand->getAllCardCodes();
}

// returns the low score of the hand
int Player::getLowScore() {
    return myHand->getLowScore();
}

// returns the high score of the hand
int Player::getHighScore() {
    return myHand->getHighScore();
}

// returns high score unless it is over 21, then it returns the lowScore
int Player::getScore() {
    if( myHand->getHighScore() > 21 )
        return myHand->getHighScore();
    return myHand->getLowScore();
}


// returns true if player busted
bool Player::busted() {return myHand->isBust();}

// returns true if the player wants a card (getScore < 16)
bool Player::wantCard() {return myHand->canTakeCard();}

// clears the cards from the hand for the next deal
void Player::clearHand() {
    myHand->clearHand();
}

// sets the betting stake for the player
void Player::setStake(int stake) {
    this->stake = stake;
}

// returns the current value of the betting stake
int  Player::getStake() {
    return stake;
}

// saves the bet if it is less than the stake and returns true, otherwise
// return false and do nothing
bool Player::makeBet(int bet) {
    this->bet=(bet < stake)?bet:this->bet;
    return (bet<stake)?true:false;
}

// adds the bet to the stake
void Player::won() {
    stake += bet;
}

// subtracts the bet from the stake
void Player::lost() {
    stake -= bet;
}
