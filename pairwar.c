//
// Created by Kevin Funderburg on 2019-10-24.
//
#include <stdbool.h>
#include <stdlib.h>

enum Suit {SPADES = 0, CLUBS = 1, HEARTS = 2, DIAMONDS = 3};
struct Card
{
    int num;
    enum Suit suit;
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