#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

using namespace std;

class HumanPlayer : public Player {
public:
    HumanPlayer(string name);
    bool makeMove() override; // asks user to hit or stand
};

#endif