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

  if (list == NULL) {
    minPtr = list;
  } else {
    if (minPtr->info.ComparedTo(list->info) == GREATER) {
      minPtr = list;
    }
    list = list->next;
  }

  return minPtr;
}

void Sort(NodeType *list) {
  NodeType *sorted = NULL;  // hold sorted list
  NodeType *current = list; // transverse through the list

  while (list != NULL) { // make sure list is not empty
    if (sorted != NULL) {
      sorted = MinLoc(list, current);
      list->info = sorted->info;
      list = list->next;
    } else {
      sorted = MinLoc(list, current);
      list = list->next;
    }
  }
  list = sorted;
}
