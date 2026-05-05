#include <iostream>
#include <stdexcept>
#include "Game.h"

using namespace std;

int main() {
    try {
        string name;
        cout << "Enter your name: ";
        cin >> name;

        Game game(name);
        game.run();

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}