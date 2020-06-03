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
  int k = 0;
  bool complete = false;
  if (numPlayers == 0) {
    Player *newArray = new Player[++numPlayers];
    *newArray = Player(score, name);
    players = newArray;
  } else if (numPlayers < 10) {
    Player *newArray = new Player[++numPlayers];

    for (int i = 0; i < numPlayers; ++i) {
      if (k < numPlayers - 1) {
        if (score > players[k].getScore() && !complete) {
          newArray[i] = Player(score, name);
          k--;
          complete = true;
        } else {
          newArray[i] = players[k];
        }
      } else if (!complete) {
        newArray[i] = players[k];
      } else {
        newArray[i] = players[k];
      }
      k++;
    }
    players = newArray;
  } else if (numPlayers == 10) {
    Player *newArray = new Player[numPlayers];
    int k = 0;
    bool complete = false;

    for (int i = 0; i < numPlayers; i++) {
      if (score > players[k].getScore() && !complete) {
        newArray[i] = Player(score, name);
        k--;
        complete = true;

      } else {
        newArray[i] = players[k];
      }
      k++;
    }
    players = newArray;
  }
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {
  return 0;
}
void Manager::removePlayer(int &numPlayers, Player *&players, string target) {}
