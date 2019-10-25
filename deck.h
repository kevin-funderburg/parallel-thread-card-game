//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <random>
#include "card.h"
using namespace std;

class Deck
{
    int FULL_DECK = 52;
    int size;
    Card *cards;

    Deck();
    void shuffle();
    void popCard();
    Card topCard();
    void showContents();
};


Deck::Deck() : size(FULL_DECK), cards(new Card[FULL_DECK])
{
    int cnt = 0;
    Suit s;
    for (int i = 0; i < 3; ++i) {
        switch (i) {
            case 0: s = SPADES; break;
            case 1: s = CLUBS; break;
            case 2: s = HEARTS; break;
            case 3: s = DIAMONDS; break;
            default: cerr << "invalid suit";
        }
        for (int j = 1; j < 14; ++j) {
            cards[cnt].num = j;
            cards[cnt].suit = s;
            cnt++;
        }
    }
}

/**
 * shuffle the deck
 */
void Deck::shuffle()
{
    Card *tmp = new Card[FULL_DECK];
    bool shuffled = false;
    int j = 0;
    while (!shuffled)
    {
        Card c = cards[(int) rand()/FULL_DECK];
        bool contains = false;
        for (int i = 0; i < FULL_DECK; ++i) {
            if (tmp[i].num == c.num && tmp[i].suit == c.suit) {
                contains = true;
                break;
            }
        }
        if (!contains) {
            tmp[j] = c;
            j++;
            if (j == FULL_DECK) shuffled = true;
        }
    }

}

/**
 * remove card at top of deck
 */
void Deck::popCard()
{
    Card *tmp = new Card[size-1];
    for (int i = 0; i < size-1; ++i)
        tmp[i] = cards[i+1];
    delete[] cards;
    cards = tmp;
    size--;
}

/**
 * get card at top of deck
 * @return card
 */
Card Deck::topCard() { return cards[0]; }

/**
 * log the contents of the deck
 */
void Deck::showContents()
{
    for (int i = 0; i < size; ++i) {
        if (i == 0) { cout << cards[i].num << endl; }
        else { cout << " " << cards[i].num << endl; }
    }
}
#endif //DECK_H
