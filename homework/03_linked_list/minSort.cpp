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

  NodeType *sorted = NULL;
  NodeType *tempSort = NULL;

  while (list != NULL) {

    if (sorted == NULL) { // first element of list
      sorted->info = list->info;
      list = list->next;
      tempSort->info = sorted->info;

    } else { // remaininng elements
      sorted = MinLoc(list, tempSort);
      list = list->next;
      tempSort->info = sorted->info;
    }
    list->info = tempSort->info;
  }
}

/*
  NodeType *sorted = NULL;
  NodeType *current = list;

  while (list != NULL) {

    if (sorted != NULL) {
      sorted = MinLoc(list, current);
      list->info = sorted->info;
      list = list->next;

    } else {
      sorted = MinLoc(list, current);
      current->info = sorted->info;
      current = list->next;
    }
  }
 */