# Pair War

Authors: Kevin Funderburg, Rob Murray

<details>
  <summary><strong>Table of Contents</strong> (click to expand)</summary>
<!-- TOC depthFrom:2 -->

- [About](#about)
- [Licensing & thanks](#licensing--thanks)
- [Changelog](#changelog)

<!-- /TOC -->
</details>

## About
In this project, we are going to build “Pair War”.
Pair War is a simple card game with one dealer, 3 players, and a single deck of cards. The game is composed of three rounds.
At the beginning of each round, the dealer shuffles the cards, deals the first three cards (one per player) and waits for the round to finish, before repeating the same process for the next round.
A winner in a round is the first player to get a “pair”. In each round, a different player is given the privilege to start. Initially, the dealer shuffles the deck of cards and hands each player a single card in a round robin fashion (say, starting from player 1 for round 1). Once the dealer is done handling the cards, the dealer places the remaining deck of cards on the table and the first round begins. Each player (starting from player 1), draws a card from the deck and compares it to the card he/she has. If they are a pair, the player shows the hand, declares him/herself a winner and the round ends. Otherwise, the player will discard one card (at random) by placing it at the bottom of the deck of cards on the table, and the next player proceeds.
Once a round ends, the dealer shuffles the deck again and hands a card to each player. In the second round, the second player starts drawing a card from the deck. In the third round, the third player starts drawing a card from the deck.

## Usage
Make commands
```shell
make
make clean
make cleanall
```

Command line structure:

```shell
sim [123] [average arrival rate] [average service time] [quantum interval]

1 : First-Come First-Served (_FCFS)
2 : Shortest Remaining Time First (_SRTF)
3 : Round Robin, with different quantum values (_RR)
```

Example: `./sim 1 1 0.06 0.01`



## Licensing & Thanks

This project is released under the [MIT License][mit].

## Changelog

- v1.0.0

[mit]: https://github.com/kevin-funderburg/discrete-time-event-simulator/blob/master/LICENSE.txt
