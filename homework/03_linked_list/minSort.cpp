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
  if (list == NULL) {
    minPtr = list;
  } else {
    if (minPtr->info.ComparedTo(list->info) == LESS) {
      minPtr->info = list->info;
    }
    list = list->next;
  }
  /*
    NodeType *current = list;
    if (list == NULL) {
      minPtr->info = list->info;
    }

    do {
      if ((current->info.ComparedTo(minPtr->info) == GREATER) ||
          current->info.ComparedTo(minPtr->info) == EQUAL) {
        minPtr->info = current->info;
      }
      current = current->next;

    } while (current != list); */

  return minPtr;
}
// Searching Algorithm: Binary Search(Recursive)

void Sort(NodeType *list) {

  /*  // initialize sorted linked list
    NodeType *sorted = NULL;

    NodeType *current = list;

    while (current != NULL) {
      NodeType *next = current->next;

      MinLoc(list, current);
      // TO DO: ADD THE MINIMUM LOCATION THING
      current = next;
    }
    list = sorted; */
}
