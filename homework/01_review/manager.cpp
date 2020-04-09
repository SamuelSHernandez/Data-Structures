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

  if (numPlayers > 10) {
    numPlayers += 1;
    Player *AddTemp = new Player[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
      AddTemp[i] = players[i];
      players[numPlayers].setName(name);
      players = AddTemp;
      delete[] AddTemp;
    }
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

    if (numPlayers > 10) {
      numPlayers -= 1;
      Player *AddTemp = new Player[numPlayers];
      for (int i = 0; i < numPlayers; i++) {
        AddTemp[i] = players[i];
        players = AddTemp;
        delete[] AddTemp;
      }
    }
  }
