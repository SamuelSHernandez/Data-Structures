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

  // TO DO: Copy array into array with size + 1
  int minScore = 0;
  minScore = min(players[0].getScore(), players[numPlayers - 1].getScore());

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
        players[numPlayers -1].setScore(score);
    }

    delete[] AddTemp;
  } else {

    for (int i = 0; i < numPlayers; i++) {
      if (players[i].getScore() == minScore) {
        players[i].setName(name);
        players[i].setScore(score);
      }
    }
  }
  // TO DO: else for greater than 10 (/)
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {

  int playerScore = 0;
  // TO DO: Return Player's score
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
      playerScore = players[i].getScore();
    }
  }
  return playerScore;
}
void Manager::removePlayer(int &numPlayers, Player *&players, string target) {
  // TO DO: Remove target

  if (numPlayers < 10) {

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
}
