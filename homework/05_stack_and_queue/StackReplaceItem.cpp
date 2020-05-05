/*************************************************************************
 *
 * Assignment: ReplaceItemStack
 *
 * File Name: ReplaceItemStack.cpp
 * Name:        hernsa
 * Course:      CPTR 242
 * Date:        today
 */
#include "StackType.h"

void StackType::ReplaceItem(ItemType oldItem, ItemType newItem) {
  // TO DO: put head of the stack into head of new stack.
  int stackIndex;

  for (stackIndex = top; stackIndex >= 0; stackIndex++) {
    if (items[stackIndex] == oldItem) {
      break;
    }
  }
  items[stackIndex] = newItem;
}
