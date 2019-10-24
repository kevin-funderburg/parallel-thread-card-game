#include <iostream>

enum Suit {SPADES = 0, CLUBS = 1, HEARTS = 2, DIAMONDS = 3};
struct Card
{
    int num;
    enum Suit suit;
};

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
    struct Card tmp[] = struct Card[52];
    for (int i = 0; i < 52; ++i) {
//        temp[i] = deck[rand()/RAND_MAX];
    }
}

class Player
{
    Card hand[3];
    bool turn;

    Player();
    void draw(Card card);
    bool isPair();
    bool isTurn;
};

Player::Player() {}

void Player::draw(Card card)
{

}

bool Player::isPair() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j != i)
                if (hand[i].num == hand[j].num) return true;
        }
    }
    return false;
}

class Dealer
{

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}