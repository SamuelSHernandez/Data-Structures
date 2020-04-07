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

void addPlayer(int &numPlayers, Player *&players, string name, int score) {

  ofstream Leaderboard_out;
  string PlayerName;
  int PlayerScore;
  int minimum = 1;

  Leaderboard_out.open("user_input.txt"); // open file
  PlayerName = name;
  if (!Leaderboard_out) {
    cout << "cannot open file: \" user_input.txt \" " << endl;
  }
  minimum = (score < minimum) ? score : minimum;

  if (numPlayers <= 10) {
    // TO DO: Add player to file
    for (int i = 0; i < numPlayers; i++) {

      if (players[i].getName() != name && score > minimum) {
        players[i].setName(name);
        Leaderboard_out << name;
      } else if (numPlayers > 10 || numPlayers < 0) {
        cout << "The number of players is invalid!";
      }
    }
  }

  Leaderboard_out.close();
}

int searchPlayers(int numPlayers, Player *players, string target) { 
    int playerIndex;
    for(int i = 0; i < numPlayers; i++){
        if(players[i].getName() == target){
            i = playerIndex;
        }
    }
    return playerIndex;
 }
void removePlayer(int &numPlayers, Player *&players, string target) {
  cout << target;
}
// TO DO: if no score provided, score = -1

// close file

/*if (numPlayers > 10) {


    */