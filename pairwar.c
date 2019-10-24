//
// Created by Kevin Funderburg on 2019-10-24.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

enum Suit {SPADES = 0, CLUBS = 1, HEARTS = 2, DIAMONDS = 3};
struct Card
{
    int num;
    enum Suit suit;
};

struct Deck
{
    struct Card[] cards;
    void shuffle();
};
extern const struct DeckClass {
    struct Deck (*new)();
} Deck;

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
    struct Card[] tmp = struct Card[52];
    for (int i = 0; i < 52; ++i) {
        temp[i] = deck[rand()/RAND_MAX];
    }
}

class Player
        {
    struct Card[] hand = Card[3];
        };

bool isPair(struct Card []);

bool isPair(struct Card hand[3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j != i)
                if (hand[i].num == hand[j].num) return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    struct hand1 = Card[3];
    return 0;
}