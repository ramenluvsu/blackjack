#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "Deck.h"

using namespace std;

//abstract base class all players inherit from this
class Player {
protected:
    string name;
    Hand hand;
    int wins;
    int losses;

public:
    Player(string name);
    virtual ~Player() {}

    //pure virtual so every derived class has to make their own version
    virtual bool make_move() = 0;

    void receive_card(Card card);
    void show_hand() const;
    bool is_bust() const;
    bool is_blackjack() const;
    int get_total() const;
    string get_name() const;
    void record_win();
    void record_loss();
    int get_wins() const;
    int get_losses() const;
    void reset_hand();

};

#endif