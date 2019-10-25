//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include "card.h"
using namespace std;

class Deck
{
    static const int FULL_DECK = 52;
    int size;
    Card *cards = new Card[FULL_DECK];

public:
    Deck();
    void shuffle();
    void popCard();
    void push(Card);
    Card topCard();
    void show();
};


Deck::Deck() : size(FULL_DECK)
{
    int cnt = 0;
    Suit s;
    for (int i = 0; i < 4; ++i) {
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
//            cout << "cards[cnt].num: " << cards[cnt].num << endl;
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
        int r = 0;
        while (r < 1 || r > FULL_DECK)
            r = rand() % FULL_DECK + 1;
        Card c = cards[r];
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
            if (j == FULL_DECK-1) shuffled = true;
        }

    }
    delete[] cards;
    cards = tmp;
}

/**
 * remove card at top of deck
 */
void Deck::popCard()
{
    Card *tmp = new Card[FULL_DECK];
    for (int i = 0; i < size; ++i)
        tmp[i] = cards[i+1];
    delete[] cards;
    cards = tmp;
    size--;
}

void Deck::push(Card c)
{
    cards[size+1] = c;
    size++;
    show();
}

/**
 * get card at top of deck
 * @return card
 */
Card Deck::topCard() { return cards[0]; }

/**
 * log the contents of the deck
 */
void Deck::show()
{
    ofstream logger("log.data",  ios::out | ios::app);    //output to text file for viewing

    if (logger.is_open()) {
        for (int i = 0; i < size; ++i) {
            if (i == 0) { logger << "DECK: " << setw(3) << cards[i].num; }
            else { logger << setw(3) << cards[i].num; }
        }
        logger << endl;
    }
}
#endif //DECK_H
