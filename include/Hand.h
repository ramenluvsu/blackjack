#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;

class Hand {
private:
    vector<Card> cards;
    int calculate_total(int index) const; //recursive helper to add up the cards

public:
    void add_card(Card card);
    int get_total() const;        //calls the recursive function
    bool is_bust() const;         //returns true if over 21
    bool is_blackjack() const;    //true if 21 with just 2cards
    void display() const;         //prints allcards in hand.
    void clear();                  //resets the hand
    int card_count() const;

    friend class Dealer;         //dealer needs to see cards directly
};

#endif