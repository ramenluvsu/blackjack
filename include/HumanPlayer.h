#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

using namespace std;

//this is the human player class it asks the user what to do
class HumanPlayer : public Player {
public:
    HumanPlayer(string name);
    bool make_move() override; //WIll ask user to hit or stand

};

#endif