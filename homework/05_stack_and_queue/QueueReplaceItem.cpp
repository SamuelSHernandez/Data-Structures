/*************************************************************************
 *
 * Assignment: ReplaceItemQueue
 *
 * File Name: ReplaceItemQueue.cpp
 * Name:        hernsa
 * Course:      CPTR 242
 * Date:        today
 */
#include "QueueType.h"

// TODO: Implement ReplaceItem for the queue implementation
// in QueueReplaceItem.cpp. A cpp file has been provided for you with a function
// header.

void QueueType::ReplaceItem(ItemType oldItem, ItemType newItem) {
  // Function: Replaces item in
  // copy the head of old to tail of new
  QueueType tempQueue;

  while (!this->IsEmpty()) {
    ItemType tempItem;
    this->Dequeue(tempItem);
    if (oldItem == newItem) {
      tempItem = newItem;
    }
    tempQueue.Enqueue(tempItem);
  }

  while (!tempQueue.IsEmpty()) {
    ItemType tempItem;
    tempQueue.Dequeue(tempItem);
    this->Enqueue(newItem);
  }
}
