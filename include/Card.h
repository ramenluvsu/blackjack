#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
private:
    string rank;  //the rank like 2 to 10 then j q k a
    string suit;  //hearts diamonds clubs spades
    int value;    //numeric value used tocalculate score

public:
    Card(string rank, string suit, int value);

    string get_rank() const;
    string get_suit() const;
    int get_value() const;

    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif