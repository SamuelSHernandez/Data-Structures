/****************************************************************************
 *
 * Homework: Implement a two recursive functions on a linked unsorted list.
 *
 * File Name:  minSort.cpp
 * Name:       hernsa
 * Course:     CPTR 242
 * Date:       Today
 *
 */
#include "ItemType.h"
#include "unsorted.h"

using namespace std;

NodeType *MinLoc(NodeType *list, NodeType *&minPtr) {
  // TODO Add recursive MinLoc.
  NodeType *current = list;

  while (current != NULL) {
    if ((minPtr->info.ComparedTo(current->info) == EQUAL)) {
      minPtr->info = current->info;
      break;
    }
  }
  return minPtr;
}
// Searching Algorithm: Binary Search(Recursive)

void Sort(NodeType *list) {

  // initialize sorted linked list
  NodeType *sorted = NULL;

  NodeType *current = list;

  while (current != NULL) {
    NodeType *next = current->next;

    MinLoc(list, current);
    // TO DO: ADD THE MINIMUM LOCATION THING
    current = next;
  }
  list = sorted;
}

// Sorting Algorithm: Insertion Sort
/*else if((minPtr->info.ComparedTo(current->info) == LESS)){

    }else if((minPtr->info.ComparedTo(current->info) == GREATER)){

    } */