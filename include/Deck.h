#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

using namespace std;

class Deck {
private:
    vector<Card> cards;  //holds all 52 cards

public:
    Deck();
    void shuffle();       //shuffles thedeck randomly
    Card deal_card();     //removes and returns the top card
    int size() const;     //how many cards are left in the deck
};

#endif