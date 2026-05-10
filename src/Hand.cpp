#include "Hand.h"

void Hand::add_card(Card card) {
    cards.push_back(card);
}

// we wil recursively add up all card values starting from index 0
int Hand::calculate_total(int index) const {
    if (index == cards.size())
        return 0;
    return cards[index].get_value() +calculate_total(index + 1);
}

int Hand::get_total() const {
    int total = calculate_total(0);

    //count howmany aces we have so we can adjust if we bust
    int aces = 0;
    for (auto& card : cards)
        if (card.get_rank() == "A") aces++;

    //flip ace from 11 to 1 if we going over 21
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}



bool Hand::is_bust() const {
    return get_total() > 21;
}

bool Hand::is_blackjack() const {
    return cards.size() == 2 && get_total() == 21;
}

void Hand::display() const {
    for (auto& card : cards)
        cout << "  " << card <<endl;
    cout << "  Total: " << get_total() <<endl;
}

void Hand::clear() {
    cards.clear();
}

int Hand::card_count() const {
    return cards.size();
}