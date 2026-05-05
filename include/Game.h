#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <algorithm>
#include "Deck.h"
#include "HumanPlayer.h"
#include "Dealer.h"
#include "GameStack.h"

using namespace std;

class Game {
private:
    Deck deck;
    HumanPlayer player;
    Dealer dealer;
    GameStack<Card> discardPile;
    map<string, int> leaderboard;  // name -> wins

    void dealInitialCards();
    void playerTurn();
    void dealerTurn();
    string determineWinner();
    void updateLeaderboard();
    void showLeaderboard();

public:
    Game(string playerName);
    void play();         // plays one full round
    void run();          // main loop - keeps asking to play again
};

#endif