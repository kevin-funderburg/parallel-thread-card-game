#include <iostream>
#include <fstream>
#include "deck.h"
#include "card.h"
#include "player.h"
using namespace std;

class Dealer
{
    Card hand;

public:
    Dealer();
    Card deal();
    void draw(Card);
};

Dealer::Dealer() {}

Card Dealer::deal() { return hand; }

void Dealer::draw(Card card) { hand = card; }

int main(int argc, char *argv[])
{
    int round = 0;
    bool winner = false;
    ofstream log("log.data",  ios::out | ios::app);    //output to text file for viewing

    Deck deck = Deck();
    Dealer dealer;
    Player player1(1);
    Player player2(2);
    Player player3(3);

    deck.show();
    deck.shuffle();
    deck.show();

    dealer.draw(deck.topCard());
    deck.popCard();

    player1.push(dealer.deal());
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