#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

using namespace std;

//dealer class follows fixed rules doesnt ask for input
class Dealer : public Player {
public:

    Dealer();
    bool make_move() override;      //hits until 17 then stops
    void show_first_card() const;   //only shows one card at the start

};

#endif