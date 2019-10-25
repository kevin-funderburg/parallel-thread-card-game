//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef CARD_H
#define CARD_H

enum Suit {SPADES = 0, CLUBS = 1, HEARTS = 2, DIAMONDS = 3};
struct Card
{
    int num;
    enum Suit suit;
};

#endif //CARD_H
