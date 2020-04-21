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
    if (minPtr->info.ComparedTo(list->info) == GREATER) {
      minPtr = list;
    }
    list = list->next;
  }

  return minPtr;
}

void Sort(NodeType *list) {
  NodeType *sorted = NULL;
  NodeType *current = list;

  while (list != NULL) {

    if (sorted == NULL) {
      sorted->info = list->info;
      list = list->next;
      // this works
    } else {
      current = MinLoc(list, sorted);
      current = current->next;
    }

    // outside
  }
}

/*





  --------
    NodeType *temp = NULL;
  NodeType *sorted = NULL;
  NodeType *current = list;

  while (list != NULL) {

    temp = MinLoc(list, sorted);
    current->info = temp->info;
    current = current->next;
  }
  list = sorted;
*/