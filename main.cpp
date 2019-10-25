#include <iostream>
#include <fstream>
#include "deck.h"
#include "card.h"
#include "player.h"
using namespace std;

class Dealer
{
    Deck deck;

public:
    Dealer();
    Card deal();
};

Dealer::Dealer()
{
    deck = Deck();
}

Card Dealer::deal()
{
    Card c = deck.topCard();
    deck.popCard();
    return c;
}

int main(int argc, char *argv[])
{
    int round = 0;
    bool winner = false;
    ofstream log("log.data",  ios::out | ios::app);    //output to text file for viewing

    Dealer dealer;

    Deck deck = Deck();
    deck.show();
    deck.shuffle();
    deck.show();

    Player player1(1);
    Player player2(2);
    Player player3(3);

    player1.push(deck.topCard());
    deck.popCard();
    while (!winner)
    {
        player1.draw(deck.topCard());
        deck.popCard();

        if (player1.isWinner()) {
            winner = true;
            player1.exit();
        } else {
            deck.push(player1.discard());
        }
    }

//    player1.draw(c);
    return 0;
}