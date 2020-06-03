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

  StackType temp;
  while (!this->IsEmpty()) {
    ItemType item = this->Top();
    this->Pop();
    if (item == oldItem) {
      item = newItem;
    }
    temp.Push(item);
  }

  while (!temp.IsEmpty()) {
    ItemType item = temp.Top();
    temp.Pop();
    this->Push(item);
  }
}
