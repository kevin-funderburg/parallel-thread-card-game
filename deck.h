//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck
{
    Card cards[];
    Deck();
    void shuffle();
};


Deck::Deck()
{
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 13; ++j) {
            cards[cnt].num = j;
            cards[cnt].suit = i;
            cnt += 1;
        }
    }
}

void Deck::shuffle()
{
    Card tmp[52];
    for (int i = 0; i < 52; ++i) {
//        temp[i] = deck[rand()/RAND_MAX];
    }
}

#endif //DECK_H
