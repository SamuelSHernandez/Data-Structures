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

  while (list != NULL) {
    if ((list->info.ComparedTo(minPtr->info) == GREATER) ||
        list->info.ComparedTo(minPtr->info) == EQUAL) {
      minPtr->info = list->info;
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
