#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "Deck.h"

using namespace std;

// Abstract base class
class Player {
protected:
    string name;
    Hand hand;
    int wins;
    int losses;

public:
    Player(string name);
    virtual ~Player() {}

    // Pure virtual - MUST be implemented by derived classes
    virtual bool makeMove() = 0;  // returns true = hit, false = stand

    // Common to all players
    void receiveCard(Card card);
    void showHand() const;
    bool isBust() const;
    bool isBlackjack() const;
    int getTotal() const;
    string getName() const;
    void recordWin();
    void recordLoss();
    int getWins() const;
    int getLosses() const;
    void resetHand();
};

#endif