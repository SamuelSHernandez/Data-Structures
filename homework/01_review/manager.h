/*************************************************************************
 *
 * Assignment 1: high score manager
 *
 * File Name: manager.h
 * Course:    CPTR 242
 * Date:      April 2, 2019
 */

#include <iostream>
#include <string>
using namespace std;

#include "player.h"

class Manager {
public:
  void addPlayer(int &numPlayers, Player *&players, string name, int score);
  int searchPlayers(int numPlayers, Player *players, string target);
  void removePlayer(int &numPlayers, Player *&players, string target);
};
