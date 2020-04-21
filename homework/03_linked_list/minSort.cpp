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
#include <list>

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
  NodeType *sorted = NULL;  // holds the sorted list
  NodeType *current = list; // used for iterating through the list

  while (list != NULL) {
    if (sorted != NULL) { // once sorted head is set, move to the next element
      sorted = sorted->next;
      list = list->next;
    } else {
      sorted = MinLoc(current, sorted);
      current->info = sorted->info; // copies the sorted element to the current

      current = list->next; // iterates
    }
  }
  list = sorted;
}
