#include "Dealer.h"

Dealer::Dealer() : Player("Dealer") {}

bool Dealer::make_move() {
    //dealer has to hit if under 17 its a casino rule
    return hand.get_total() < 17;

}

void Dealer::show_first_card() const {
    //hides the first card so player cant see it at the start
    cout << "Dealer's hand:" <<endl;
    cout << "  [Hidden Card]" <<endl;
    cout << "  " << hand.cards[1] <<endl;
}