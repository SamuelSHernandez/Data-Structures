/*************************************************************************
 *
 * Project 1: ImdbList implemented using linked list
 *
 * File Name: ImdbList.cpp
 * Name:      hernsa
 * Course:    CPTR 242
 * Date:      4/27
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
  // Empty list
  ResetList();
  while (currentPos != NULL) {
    SLelement<string> *temp = currentPos;
    currentPos = currentPos->getNext();
    temp = NULL;
  }
  length = 0;
  listData = NULL;
}

SLelement<string> *ImdbList::GetHead() { return listData; }

void ImdbList::PutActor(string actor, string movies, int count) {
  ResetList();
  SLelement<string> *newNode = new SLelement<string>(actor, movies);

  string color = "";
  double size = 0.0;
  // NICE
  if (count < 10) {
    color = "firebrick";
    size = 20.0;
  } else if (count < 50) {
    color = "cornflowerblue";
    size = 30.0;
  } else if (count < 100) {
    color = "darkseagreen";
    size = 40.0;
  } else {
    color = "darkolivegreen";
    size = 50.0;
  }

  newNode->setSize(size);
  newNode->setColor(Color(color));

  int counter = length;
  SLelement<string> *temp = listData;
  SLelement<string> *prev = listData;

  if (length == 0) {
    newNode->setNext(listData);
    listData = newNode;
  } else {
    while (counter > 0) {

      if (temp->getValue() > newNode->getValue()) {
        if (counter == length) {
          newNode->setNext(listData);
          listData = newNode;
        } else {
          newNode->setNext(temp);
          prev->setNext(newNode);
        }
        break;
      }

      if (temp->getNext() == NULL) {
        temp->setNext(newNode);
        break;
      }
      counter--;
      prev = temp;
      temp = temp->getNext();
    }
  }
  length++;
}

void ImdbList::GetActor(string actor, string &movies, bool &found) {

  SLelement<string> *current = listData;

  for (int i = 0; i < length; i++) {
    if (current->getValue() == actor) {
      found = true;
      movies = current->getLabel();

      return;
    }
    current = current->getNext();
  }

  found = false;
}

void ImdbList::DeleteActor(string actor) {
  SLelement<string> *current = listData;
  SLelement<string> *previous = listData;

  while (current->getValue() != actor) {
    previous = current;
    current = current->getNext();
  }

  previous->setNext(current->getNext());
  length--;
}

void ImdbList::ResetList() { currentPos = listData; }

void ImdbList::GetNextActor(string &actor, string &movies) {
  if (currentPos == NULL) {
    return;
  }
  actor = currentPos->getValue();
  movies = currentPos->getLabel();
  currentPos = currentPos->getNext();
}

// that's all folks!