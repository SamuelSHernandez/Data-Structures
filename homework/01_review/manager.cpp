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

  int minScore = min(players[0].getScore(), players[numPlayers - 1].getScore());

  if (numPlayers < 10) {
    numPlayers += 1;
    Player *AddTemp = new Player[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
      AddTemp[i] = players[i];
    }
    players = AddTemp;

    players[numPlayers - 1].setName(name);
    if (cin.fail()) {
      players[numPlayers - 1].setScore(-1);

    } else {
      players[numPlayers - 1].setScore(score);
    }

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
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {

  int playerScore = 0;

  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
      playerScore = players[i].getScore();
    }
  }
  return playerScore;
}
void Manager::removePlayer(int &numPlayers, Player *&players, string target) {

  numPlayers -= 1;
  Player *AddTemp = new Player[numPlayers];
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
    }
    AddTemp[i] = players[i];
  }

  players = AddTemp;

  delete[] AddTemp;
}
