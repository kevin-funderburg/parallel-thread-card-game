//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "card.h"
using namespace std;

class Player
{
    int num;
    int FULL_HAND = 3;
    Card *hand;
    int handSize;
    bool turn;

    Player(int);
    void draw(Card card);
    bool isPair();
    bool isTurn();
    void log(string);
    void out(string);
};

Player::Player(int n):num(n), hand(new Card[FULL_HAND]), handSize(0) {}

void Player::draw(Card card)
{
    hand[handSize] = card;
    handSize++;
}

/**
 * check if hand contains a pair
 * @return bool
 */
bool Player::isPair() {
    for (int i = 0; i < handSize; ++i) {
        for (int j = 0; j < handSize; ++j)
            if (j != i && hand[i].num == hand[j].num) return true;
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
