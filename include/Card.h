#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
private:
    string rank;
    string suit;
    int value;

public:
    Card(string rank, string suit, int value);

    string getRank() const;
    string getSuit() const;
    int getValue() const;

    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif