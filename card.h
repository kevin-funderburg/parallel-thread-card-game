//
// Created by Kevin Funderburg on 2019-10-24.
//

#ifndef CARD_H
#define CARD_H

enum Suit {SPADES = 0, CLUBS = 1, HEARTS = 2, DIAMONDS = 3};
enum Value {ACE = 1, TWO = 2, THREE = 3, FOUR = 4,
            FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8
            NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13};
struct Card
{
    int num;
    enum Suit suit;
    enum Value value; //remove if ineplicable
};

#endif //CARD_H
