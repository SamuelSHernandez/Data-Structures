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
  // TO DO: Sort by score
  Player newArray[9];

  for (int i = 0; i < numPlayers; i++) {

    newArray[i] = players[i];
  }
  players[numPlayers + 1].setName(name);
  /* for (int i = 0; i < numPlayers; i++) {
players->setName(name);
players->setScore(score);
}
  */
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
  /* Player *addPlayerArray[8];

    for (int i = 0; i < numPlayers; i++) {

      addPlayerArray[i] = &players[i];
      cout << &addPlayerArray[i];
    }*/

  // TO DO: Copy array into array with size - 1.  if player-> do not copy
}
