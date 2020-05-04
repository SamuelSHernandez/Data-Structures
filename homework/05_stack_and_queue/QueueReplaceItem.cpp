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
    int size = 0;

    if(front < rear){
        size = rear - front;
    }

  ItemType tempItem = items[front];
  // TO DO: Iterate through both queues and transfer head to tail
  for (int i = 0; i < size ; i++) {
      Enqueue(newItem);
  }

}
