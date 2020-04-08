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

void Manager::addPlayer(int &numPlayers, Player *&players, string name, int score) {

  ofstream Leaderboard_out;
  string PlayerName;
  int minimum = 1;
//TO DO: Delete file i/o
//TO DO: Copy array into array with size + 1
//TO DO: Sort by score 
  Leaderboard_out.open("user_input.txt"); // open file
  PlayerName = name;
  if (!Leaderboard_out) {
    cout << "cannot open file: \" user_input.txt \" " << endl;
  }
  minimum = (score < minimum) ? score : minimum;

  if (numPlayers <= 10) {

    for (int i = 0; i < numPlayers; i++) {

      if (players[i].getName() != name && score > minimum) {
        players[i].setName(name);
        Leaderboard_out << name << " " << score;
      } else if (numPlayers > 10 || numPlayers < 0) {
        cout << "The number of players is invalid!";
      }
    }
    Player(score, name);
  }

  Leaderboard_out.close();
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {
    //TO DO: Return Player's score
  int playerIndex = 0;
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
      i = playerIndex;
    }
  }
  return playerIndex;
}
void Manager::removePlayer(int &numPlayers, Player *&players, string target) {

//TO DO: Copy array into array with size - 1.  if player-> do not copy
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].getName() == target) {
      players[i].setName("");
    }
  }
}
