#include "Card.h"

Card::Card(string rank, string suit, int value)
    : rank(rank), suit(suit), value(value) {}


Card::Card(const Card& other) {
    //copies all the data from another card into this one
    rank = other.rank;
    suit = other.suit;
    value = other.value;
}

string Card::get_rank() const {
    return rank;
}

string Card::get_suit() const {
    return suit;
}

int Card::get_value() const {
    return value;
}

ostream& operator<<(ostream& os, const Card& card) {
    //prints the card nicely like ace of spades instead ofjust numbers
    os << card.rank << " of " << card.suit;
    return os;
}