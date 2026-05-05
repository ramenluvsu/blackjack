#include "Deck.h"

Deck::Deck() {
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<string> ranks = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    vector<int>    values = {2,3,4,5,6,7,8,9,10,10,10,10,11};

    for (auto& suit : suits)
        for (int i = 0; i < ranks.size(); i++)
            cards.push_back(Card(ranks[i], suit, values[i]));
}

void Deck::shuffle() {
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::dealCard() {
    if (cards.empty())
        throw runtime_error("Deck is empty!");
    Card top = cards.back();
    cards.pop_back();
    return top;
}

int Deck::size() const {
    return cards.size();
}