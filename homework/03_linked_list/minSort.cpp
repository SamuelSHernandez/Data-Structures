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
if(sorted != NULL){
    sorted = sorted->next;
}
    sorted = MinLoc(list,current);

    list = list->next;
  }
  list = sorted;
}

/*





NodeType *sorted = NULL;
NodeType *current = list;

  while (current != NULL) {

    NodeType *next = current->next;

    MinLoc(current, next);
sorted = list;
    current = next;
  }
  list = sorted;



++++++++3
  NodeType *sorted = NULL;
  NodeType *current = list;

  while (current != NULL) {
    NodeType *next = current->next;
    sorted = MinLoc(current, next);
    current = next;
  }
  list = sorted;
++++2

+++1
  NodeType *current = list;

  while (list != NULL) {

    sorted = MinLoc(list, current);

    list = list->next;
  }

  list = sorted; */