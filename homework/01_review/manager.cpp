/*************************************************************************
 *
 * Assignment 1: high score manager
 *
 * File Name: manager.cpp
 * Name:      hernsa
 * Course:    CPTR 242
 * Date:     4/2/20
 *
 */
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "manager.h"

void Manager::addPlayer(int &numPlayers, Player *&players, string name,
                        int score) {
  int minScore = 0;

  if (numPlayers < 10) {
    players->setName(name);
  } else {

    players->setName(name);
    // sets scores
    if (players->getScore() == minScore) {
      players->setName(name);
      players->setScore(score);
    }
  }
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {
  int playerScore = 0;
  // finds target player and returns score
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
      playerScore = players[i].getScore();
    }
  }
  return playerScore;
}
void Manager::removePlayer(int &numPlayers, Player *&players, string target) {}

/*

ADD PLAYER
++++++++++++++++++++++++++++
  // gets lowest score from players
  // add min function
  //check indexes

  if (numPlayers < 10) {
    // copies array into temporary dynamic array
    Player *AddTemp = new Player[numPlayers + 1];
    for (int i = 0; i < numPlayers; i++) {
      AddTemp[i] = players[i];
    }
    // refils player array
    players = AddTemp;
    // set name
    players[numPlayers].setName(name);
    // set score
    if (cin.fail()) {
      players[numPlayers].setScore(-1);

    } else {
      players[numPlayers].setScore(score);
    }
    // clears temporary array
    delete[] AddTemp;
  } else {
    // replace lowest score
    for (int i = 0; i < numPlayers; i++) {
      if (players[i].getScore() == minScore) {
        players[i].setName(name);
        players[i].setScore(score);
      }
    }
  }

++++++++++++++++++++++++++++
SEARCH PLAYER
++++++++++++++++++++++++++++
  int playerScore = 0;
  // finds target player and returns score
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
      playerScore = players[i].getScore();
    }
  }
  return playerScore;
++++++++++++++++++++++++++++
REMOVE PLAYER
++++++++++++++++++++++++++++

  // populate temporary array
  Player *AddTemp = new Player[numPlayers - 1];
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() != target) {
      AddTemp[i] = players[i];
    }
  }
  // copies temporary array back without target player
  players = AddTemp;

  delete[] AddTemp;
++++++++++++++++++++++++++++
 */