#include "Game.h"

Game::Game(string playerName) : player(playerName) {}

void Game::dealInitialCards() {
    deck = Deck();
    deck.shuffle();
    player.resetHand();
    dealer.resetHand();

    // Deal 2 cards each, alternating like real blackjack
    player.receiveCard(deck.dealCard());
    dealer.receiveCard(deck.dealCard());
    player.receiveCard(deck.dealCard());
    dealer.receiveCard(deck.dealCard());
}

void Game::playerTurn() {
    cout << "\n--- Your Turn ---" << endl;
    player.showHand();

    if (player.isBlackjack()) {
        cout << "BLACKJACK! Amazing!" << endl;
        return;
    }

    while (!player.isBust()) {
        bool hit = player.makeMove();
        if (!hit) break;

        Card card = deck.dealCard();
        player.receiveCard(card);
        discardPile.push(card);
        cout << "You drew: " << card << endl;
        player.showHand();

        if (player.isBust()) {
            cout << "BUST! You went over 21." << endl;
            break;
        }
    }
}

void Game::dealerTurn() {
    cout << "\n--- Dealer's Turn ---" << endl;
    dealer.showHand();

    while (dealer.makeMove()) {
        Card card = deck.dealCard();
        dealer.receiveCard(card);
        discardPile.push(card);
        cout << "Dealer drew: " << card << endl;
        dealer.showHand();
    }

    if (dealer.isBust())
        cout << "Dealer BUST!" << endl;
}

string Game::determineWinner() {
    int playerTotal = player.getTotal();
    int dealerTotal = dealer.getTotal();

    if (player.isBust())                          return "dealer";
    if (dealer.isBust())                          return "player";
    if (player.isBlackjack() && !dealer.isBlackjack()) return "player";
    if (dealer.isBlackjack() && !player.isBlackjack()) return "dealer";
    if (playerTotal > dealerTotal)                return "player";
    if (dealerTotal > playerTotal)                return "dealer";
    return "tie";
}

void Game::updateLeaderboard() {
    leaderboard[player.getName()] = player.getWins();
    leaderboard[dealer.getName()] = dealer.getWins();
}

void Game::showLeaderboard() {
    cout << "\n--- Leaderboard ---" << endl;

    // Copy map to vector and sort by wins (descending)
    vector<pair<string, int>> sorted(leaderboard.begin(), leaderboard.end());
    sort(sorted.begin(), sorted.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    for (auto& entry : sorted)
        cout << "  " << entry.first << ": " << entry.second << " wins" << endl;
}

void Game::play() {
    dealInitialCards();

    cout << "\n=============================" << endl;
    cout << "   BLACKJACK" << endl;
    cout << "=============================" << endl;

    dealer.showFirstCard();
    playerTurn();

    if (!player.isBust())
        dealerTurn();

    cout << "\n--- Result ---" << endl;
    cout << "Your total:   " << player.getTotal() << endl;
    cout << "Dealer total: " << dealer.getTotal() << endl;

    string winner = determineWinner();
    if (winner == "player") {
        cout << "YOU WIN!" << endl;
        player.recordWin();
        dealer.recordLoss();
    } else if (winner == "dealer") {
        cout << "DEALER WINS!" << endl;
        dealer.recordWin();
        player.recordLoss();
    } else {
        cout << "IT'S A TIE!" << endl;
    }

    updateLeaderboard();
    showLeaderboard();
}

void Game::run() {
    cout << "=============================" << endl;
    cout << "   WELCOME TO BLACKJACK" << endl;
    cout << "=============================" << endl;

    string choice;
    do {
        play();
        cout << "\nPlay again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");

    cout << "\nThanks for playing!" << endl;
}