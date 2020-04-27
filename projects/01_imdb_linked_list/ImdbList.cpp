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
  // clean everything
  length = 0;
  listData = NULL;
}

SLelement<string> *ImdbList::GetHead() { return listData; }

void ImdbList::PutActor(string actor, string movies, int count) {

  // create element
  SLelement<string> *newNode = new SLelement<string>(actor, movies);

  do {
    counter = 0;
    if (newNode > newNode->GetNextActor()) {
      temporary = newNode;
      newMode = next;
      newNode = temporary;
      // NICE
      counter++;
    }

  } while (counter != 0);

  string color = "";
  double size = 0.;

  if (count < 10) {
    color = "firebrick";
    size = 20.0;
  }

  else if (count < 50) {
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

  newNode->setNext(listData);
  listData = newNode;
  // update length
  length++;

  // TODO: Add element to the list
  int counter = length;
  SLelement<string> *temp = listData;
  SLelement<string> *prev = listData;
  // TODO:inserting at beginning, middle or end.
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
      if () {
      }
    }
  }
  // outside !!

  // TODO: make list sorted

  // compare current to next. if (current > next) swap them. Repeat until list
  // is sorted. add counter for loop to see if everything is sorted

  // adding visualization features
  // set size and color based on number of movies
}

void ImdbList::GetActor(string actor, string &movies, bool &found) {
  // TODO Add code here.

  //
  // No. 1

  // Pre:  List has been initialized.(DONE)
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned;
  // 	   otherwise found = false and item is returned.
  //       List is unchanged.
}

void ImdbList::DeleteActor(string actor) {
  // TODO Add code here.
  // No. 3
}

void ImdbList::ResetList() {
  // TODO Add code here.
  // No. 4
}

void ImdbList::GetNextActor(string &actor, string &movies) {
  // TODO Add code here.

  // No. 2
}

// that's all folks!