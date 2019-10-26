#include <iostream>
#include <fstream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>

#include "deck.h"
#include "card.h"
#include "player.h"
#include "dealer.h"
using namespace std;

#define NUM_THREADS 5
#define NUM_ROUNDS 3
// global variables
Deck deck;
bool winner;
ofstream logfile;
volatile int counter = 0;
pthread_mutex_t myMutex;

struct thread_data
{
    int  thread_id;
    Card card;
};

void init()
{
    deck = Deck();
    winner = false;
    logfile.open("log.data",  ios::out | ios::app);
}

void *mutex_testing(void *param)
{

    auto *arg = (thread_data *) param;  //cast param to thread_data structure
    Player player(arg->thread_id);  //create player object with thread id
    player.push(arg->card); //add card to players hand

    while (!winner)
    {
        pthread_mutex_lock(&myMutex);

        player.draw(deck.topCard());
        deck.popCard();

        if (player.isWinner()) {
            winner = true;
            player.exit();
        } else {
            deck.push(player.discard());
        }

        pthread_mutex_unlock(&myMutex);

    }

}

int main(int argc, char *argv[])
{
    for (int j = 0; j < NUM_ROUNDS; ++j)
    {
        cout << "----------------------------------------------\n"
             << "ROUND: " << j + 1 << endl
             << "----------------------------------------------\n";
        init();
        deck.show();
        deck.shuffle();
        deck.show();
        //TODO - Dealer should be made in a thread
        Dealer dealer;

        pthread_t player1, player2, player3;
//    pthread_t dealer, player1, player2, player3;

        // create the thread_data with the thread ID and the first card
        thread_data td[3];
        for (int i = 0; i < 3; ++i) {
            td[i].thread_id = i+1;
            dealer.draw(deck.topCard());
            td[i].card = dealer.deal();
            deck.popCard();
        }
        deck.show();

        pthread_mutex_init(&myMutex, nullptr);
        cout << "starting threads" << endl;
        pthread_create(&player1, nullptr, mutex_testing, (void*)&td[0]);
        pthread_create(&player2, nullptr, mutex_testing, (void*)&td[1]);
        pthread_create(&player3, nullptr, mutex_testing, (void*)&td[2]);
        pthread_join(player1, nullptr);
        pthread_join(player2, nullptr);
        pthread_join(player3, nullptr);
        pthread_mutex_destroy(&myMutex);
    }

    logfile.close();
    return 0;
}