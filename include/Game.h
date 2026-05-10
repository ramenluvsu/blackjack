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
    GameStack<Card> discard_pile;  //tracks cards played this round
    map<string, int> leaderboard;  //maps name to wins

    void deal_initial_cards();
    void player_turn();
    void dealer_turn();
    string determine_winner();
    void update_leaderboard();
    void show_leaderboard();

public:
    Game(string player_name);
    void play();    //plays one full round
    void run();    //keeps asking if u wanna play again

};

#endif