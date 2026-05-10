#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string name) : Player(name) {}

bool HumanPlayer::make_move() {
    string choice;
    while (true) {
        cout << "Hit or Stand? (h/s): ";
        cin >> choice;
        if (choice == "h" || choice == "H") return true;
        if (choice == "s" || choice == "S") return false;
        //if they type something wrong just ask again
        cout << "Invalid input. Please enter h or s." <<endl;
    }
}