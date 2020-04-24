/*************************************************************************
 *
 * Project 1: ImdbList implemented using linked list
 *
 * File Name: ImdbList.cpp
 * Name:      ??
 * Course:    CPTR 242
 * Date:      ??
 *
 */
#include "ImdbList.h"
#include "Array.h"
#include "Bridges.h"
#include "DataSource.h"
#include "SLelement.h"

using namespace bridges;

ImdbList::ImdbList() {
  // Class constructor
  length = 0;
  listData = NULL;
}

ImdbList::~ImdbList() {
  // Post: List is empty; all items have been deallocated.
  MakeEmpty();
}

bool ImdbList::IsFull() const {
  // Returns true if there is no room for another actor
  //  on the free store; false otherwise.
  SLelement<string> *location;
  try {
    location = new SLelement<string>;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

int ImdbList::GetLength() const {
  // Post: Number of items in the list is returned.
  return length;
}

void ImdbList::MakeEmpty() {
  // TODO Add code here.
}

SLelement<string> *ImdbList::GetHead() { return listData; }

void ImdbList::PutActor(string actor, string movies, int count) {
  // TODO Add code here.

  // create element
  SLelement<string> *newNode = new SLelement<string>(actor, movies);

  // adding visualization features
  // set size and color based on number of movies
  string color = "";
  double size = 0.;

  if (count < 10) {
    color = "antiquewhite";
    size = 10.0;
  }
  // NICE
  else if (count < 50) {
    color = "cornflowerblue";
    size = 10.0;
  } else if (count < 100) {
    color = "darkseagreen";
    size = 10.0;
  } else {
    color = "darkolivegreen";
    size = 10.0;
  }

  newNode->setSize(size);
  newNode->setColor(Color(color));
  // add the element to the list
  newNode->setNext(listData);
  listData = newNode;
  // update length
  length++;
}

void ImdbList::GetActor(string actor, string &movies, bool &found) {
  // TODO Add code here.
}

void ImdbList::DeleteActor(string actor) {
  // TODO Add code here.
}

void ImdbList::ResetList() {
  // TODO Add code here.
}

void ImdbList::GetNextActor(string &actor, string &movies) {
  // TODO Add code here.
}
