#include "Player.h"

Player::Player(string name) : name(name), wins(0), losses(0) {}

void Player::receiveCard(Card card) {
    hand.addCard(card);
}

void Player::showHand() const {
    cout << name << "'s hand:" << endl;
    hand.display();
}

bool Player::isBust() const       { return hand.isBust(); }
bool Player::isBlackjack() const  { return hand.isBlackjack(); }
int  Player::getTotal() const     { return hand.getTotal(); }
string Player::getName() const    { return name; }
void Player::recordWin()          { wins++; }
void Player::recordLoss()         { losses++; }
int  Player::getWins() const      { return wins; }
int  Player::getLosses() const    { return losses; }
void Player::resetHand()          { hand.clear(); }