#include "Dealer.h"

Dealer::Dealer() : Player("Dealer") {}

bool Dealer::makeMove() {
    // Dealer must hit below 17, stand at 17+
    return hand.getTotal() < 17;
}

void Dealer::showFirstCard() const {
    cout << "Dealer's hand:" << endl;
    cout << "  [Hidden Card]" << endl;
    cout << "  " << hand.cards[1] << endl;
}