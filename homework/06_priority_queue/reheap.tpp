/****************************************************************************
 *
 * Homework 09: Implement ReheapDown and ReheapUp functions using iteration.
 *
 * File Name:  reheap.tpp
 * Name:       hernsa
 * Course:     CPTR 242
 * Date:       Today
 * Time Taken: long, probably.
 */
#include "Heap.h"

using namespace std;

template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom) {
  // TODO Implement a Iterative ReheapDown Function.

  bool done = false;
  int max_child = 0;
  int left_child = root * 2 + 1;
  int right_child = root * 2 + 2;

  while (left_child <= bottom && !done) {
    if (left_child == bottom) {
      max_child = left_child;
    } else {
      if (elements[left_child] <= elements[right_child]) {
        max_child = right_child;
      } else {
        max_child = left_child;
      }
    }

    if (elements[root] < elements[max_child]) {
      Swap(elements[root], elements[max_child]);
      root = max_child;

      left_child = root * 2 + 1;
      right_child = root * 2 + 2;

    } else {
      done = true;
    }
  }
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom) {
  // TODO Implement a Iterative ReheapUp Function.
  bool done = false;

  int parent = 0;

  do {
    parent = (bottom - 1) / 2;
    if (elements[parent] < elements[bottom]) {
      Swap(elements[parent], elements[bottom]);
      bottom = parent;
    } else {
      done = true;
    }
  } while (parent != root && !done);
}
