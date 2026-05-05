#include "Hand.h"

void Hand::addCard(Card card) {
    cards.push_back(card);
}

// Recursively adds up card values
int Hand::calculateTotal(int index) const {
    if (index == cards.size())
        return 0;
    return cards[index].getValue() + calculateTotal(index + 1);
}

int Hand::getTotal() const {
    int total = calculateTotal(0); // start recursion from index 0

    // Adjust for Aces: if bust and we have an Ace, count it as 1 instead of 11
    int aces = 0;
    for (auto& card : cards)
        if (card.getRank() == "A") aces++;

    while (total > 21 && aces > 0) {
        total -= 10; // flip Ace from 11 to 1
        aces--;
    }

    return total;
}

bool Hand::isBust() const {
    return getTotal() > 21;
}

bool Hand::isBlackjack() const {
    return cards.size() == 2 && getTotal() == 21;
}

void Hand::display() const {
    for (auto& card : cards)
        cout << "  " << card << endl;
    cout << "  Total: " << getTotal() << endl;
}

void Hand::clear() {
    cards.clear();
}

int Hand::cardCount() const {
    return cards.size();
}