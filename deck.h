//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <queue>
#include "card.h"

class Deck
{
    int size;
    Card * cards = new Card[52];

    Deck(int);
    void shuffle();
    Card popCard();
    void showContents();
};


Deck::Deck(int s) : size(s)
{
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 13; ++j) {
            cards[cnt].num = j;
            cards[cnt].suit = i;
            cnt++;
        }
    }
}

/**
 * shuffle the deck
 */
void Deck::shuffle()
{
    Card tmp[52];
    for (int i = 0; i < 52; ++i) {
//        temp[i] = deck[rand()/RAND_MAX];
    }
}

Card Deck::popCard()
{
    Card c = cards[0];
    Card * tmp = new Card[size-1];
    for (int i = 0; i < size-1; ++i)
        tmp[i] = cards[i+1];
    delete[] cards;
    cards = tmp;
    size--;
    return c;
}
/**
 * log the contents of the deck
 */
void Deck::showContents()
{

}
#endif //DECK_H
