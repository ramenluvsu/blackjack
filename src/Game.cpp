#include "Game.h"

Game::Game(string player_name) : player(player_name) {}

void Game::deal_initial_cards() {
    deck = Deck();
    deck.shuffle();
    player.reset_hand();
    dealer.reset_hand();

    //deal 2 cards each alternating like real blackjack
    player.receive_card(deck.deal_card());
    dealer.receive_card(deck.deal_card());
    player.receive_card(deck.deal_card());
    dealer.receive_card(deck.deal_card());
}

void Game::player_turn() {
    cout << "\n--- Your Turn ---" <<endl;
    player.show_hand();

    if (player.is_blackjack()) {
        cout << "BLACKJACK! Amazing!" <<endl;
        return;
    }

    while (!player.is_bust()) {
        bool hit = player.make_move();
        if (!hit) break;

        Card card = deck.deal_card();
        player.receive_card(card);
        discard_pile.push(card);
        cout << "You drew: " << card <<endl;
        player.show_hand();

        if (player.is_bust()) {
            //player went over 21 so i will stop the turn
            cout << "BUST! You went over 21." <<endl;
            break;
        }
    }
}

void Game::dealer_turn() {
    cout << "\n--- Dealer's Turn ---" <<endl;
    dealer.show_hand();

    while (dealer.make_move()) {
        Card card = deck.deal_card();
        dealer.receive_card(card);
        discard_pile.push(card);
        cout << "Dealer drew: " << card <<endl;
        dealer.show_hand();
    }

    if (dealer.is_bust())
        cout << "Dealer BUST!" <<endl;
}

string Game::determine_winner() {
    int player_total = player.get_total();
    int dealer_total = dealer.get_total();

    //check all the possible outcomes in order
    if (player.is_bust())                                   return "dealer";
    if (dealer.is_bust())                                   return "player";
    if (player.is_blackjack() && !dealer.is_blackjack())   return "player";
    if (dealer.is_blackjack() && !player.is_blackjack())   return "dealer";
    if (player_total > dealer_total)                        return "player";
    if (dealer_total > player_total)                        return "dealer";
    return "tie";
}

void Game::update_leaderboard() {
    leaderboard[player.get_name()] = player.get_wins();
    leaderboard[dealer.get_name()] = dealer.get_wins();
}

void Game::show_leaderboard() {
    cout << "\n___ Leaderboard ___" <<endl;

    //copy map into vector so we can sort it by wins
    vector<pair<string, int>> sorted(leaderboard.begin(), leaderboard.end());
    sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    for (auto& entry : sorted)
        cout << "  " << entry.first << ": " << entry.second << " wins" <<endl;
}


void Game::play() {
    deal_initial_cards();
    cout << "   BLACKJACK" <<endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!" <<endl;

    dealer.show_first_card();
    player_turn();

    if (!player.is_bust())
        dealer_turn();

    cout << "\n--- Result ---" <<endl;
    cout << "Your total:   " << player.get_total() <<endl;
    cout << "Dealers total: " << dealer.get_total() <<endl;

    string winner = determine_winner();
    if (winner == "player") {
        cout << "YOU WIN BRO!" <<endl;
        player.record_win();
        dealer.record_loss();
    } else if (winner == "dealer") {
        cout << "DEALER WINS DUDE!" <<endl;
        dealer.record_win();
        player.record_loss();
    } else {
        cout << "IT'S A TIE...." <<endl;
    }

    update_leaderboard();
    show_leaderboard();

}

void Game::run() {
    cout << "   WELCOME TO BLACKJACK" <<endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl;

    string choice;
    do {
        play();
        cout << "\nWanna play again??: ";
        cin >> choice;
    } while (choice == "yes" || choice == "Yes");

    //game is over
    cout << "\nthanku for playing bro!" <<endl;
}