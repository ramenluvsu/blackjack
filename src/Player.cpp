#include "Player.h"

Player::Player(string name) : name(name), wins(0), losses(0) {}

void Player::receive_card(Card card) {
    hand.add_card(card);
}

void Player::show_hand() const {
    cout << name << "'s hand:" <<endl;
    hand.display();
}

bool Player::is_bust() const {
    return hand.is_bust();
}

bool Player::is_blackjack() const {
    return hand.is_blackjack();
}

int Player::get_total() const {
    return hand.get_total();
}

string Player::get_name() const {
    return name;
}

void Player::record_win() {
    wins++;
}

void Player::record_loss() {
    losses++;
}

int Player::get_wins() const {
    return wins;
}

int Player::get_losses() const {
    return losses;
}

void Player::reset_hand() {
    hand.clear();
}