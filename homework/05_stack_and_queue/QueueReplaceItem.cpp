/*************************************************************************
 *
 * Assignment: ReplaceItemQueue
 *
 * File Name: ReplaceItemQueue.cpp
 * Name:        hernsa
 * Course:      CPTR 242
 * Date:        today
 */
#include "ItemType.h"
#include "QueueType.h"

// TODO: Implement ReplaceItem for the queue implementation
// in QueueReplaceItem.cpp. A cpp file has been provided for you with a function
// header.

void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {

  QueueType temp;
  while (!this->IsEmpty()) {
    ItemType item;
    this->Dequeue(item);
    if (item == oldItem) {
      item = newItem;
    }
    temp.Enqueue(item);
  }

  while (!temp.IsEmpty()) {
    ItemType item;
    temp.Dequeue(item);
    this->Enqueue(item);
  }
}
