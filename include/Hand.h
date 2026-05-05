#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;

class Hand {
private:
    vector<Card> cards;
    int calculateTotal(int index) const; // recursive helper

public:
    void addCard(Card card);
    int getTotal() const;        // calls recursive function
    bool isBust() const;         // over 21?
    bool isBlackjack() const;    // exactly 21 with 2 cards?
    void display() const;        // print all cards
    void clear();                // reset hand
    int cardCount() const;
};

#endif