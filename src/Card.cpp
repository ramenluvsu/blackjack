#include "Card.h"

Card::Card(string rank, string suit, int value)
    : rank(rank), suit(suit), value(value) {}

string Card::getRank() const { return rank; }
string Card::getSuit() const { return suit; }
int Card::getValue() const { return value; }

ostream& operator<<(ostream& os, const Card& card) {
    os << card.rank << " of " << card.suit;
    return os;
}