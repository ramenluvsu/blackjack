#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();           // builds a full 52-card deck
    void shuffle();   // shuffles the deck
    Card dealCard();  // removes and returns top card
    int size() const; // how many cards left
};

#endif