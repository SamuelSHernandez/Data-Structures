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
  if (minPtr->info.ComparedTo(list->info) == GREATER) {
    minPtr = list;
  }

  if (list->next == NULL) {
    return minPtr;
  } else {
    return MinLoc(list->next, minPtr);
  }
}

void Sort(NodeType *list) {

  NodeType *minPtr = new NodeType;
  minPtr->info = list->info;
  minPtr->next = NULL;
  ItemType currentMin = MinLoc(list, minPtr)->info;

  if (currentMin.ComparedTo(list->info) == LESS) {
    ItemType temp = list->info;
    list->info = minPtr->info;
    minPtr->info = temp;
  }

  if (list->next == NULL) {

    return;
  } else {
    Sort(list->next);
  }
}