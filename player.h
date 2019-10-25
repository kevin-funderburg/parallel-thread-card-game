//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
    int num;
    Card hand[3];
    bool turn;

    Player(int);
    void draw(Card card);
    bool isPair();
    bool isTurn;
    void log(string);
    void out(string);
};

Player::Player(int n):num(n) {}

void Player::draw(Card card)
{

}

/**
 * check if hand contains a pair
 * @return bool
 */
bool Player::isPair() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j != i)
                if (hand[i].num == hand[j].num) return true;
        }
    }
    return false;
}

/**
 * output to log file
 */
void Player::log(string str)
{
    cout << "PLAYER " << num << ": " << str << endl;
}

/**
 * output to console
 */
void Player::out(string str)
{
    cout << "PLAYER " << num << ": " << str << endl;
}

#endif //PLAYER_H
