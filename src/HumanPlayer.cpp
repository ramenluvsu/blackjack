#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string name) : Player(name) {}

bool HumanPlayer::makeMove() {
    string choice;
    while (true) {
        cout << "Hit or Stand? (h/s): ";
        cin >> choice;
        if (choice == "h" || choice == "H") return true;
        if (choice == "s" || choice == "S") return false;
        cout << "Invalid input. Please enter h or s." << endl;
    }
}