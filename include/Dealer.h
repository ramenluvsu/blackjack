#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

using namespace std;

class Dealer : public Player {
public:
    Dealer();
    bool makeMove() override; // dealer hits until 17+
    void showFirstCard() const; // shows only one card at start
};

#endif  