//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    Card hand[3];
    bool turn;

    Player();
    void draw(Card card);
    bool isPair();
    bool isTurn;
};

Player::Player() {}

void Player::draw(Card card)
{

}

bool Player::isPair() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j != i)
                if (hand[i].num == hand[j].num) return true;
        }
    }
    return false;
}

#endif //PLAYER_H
