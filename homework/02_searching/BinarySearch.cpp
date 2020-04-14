/*************************************************************************
 *
 * Assignment: Binary Search
 *
 * File Name:   BinarySearch.cpp
 * Name:        hernsa
 * Course:      CPTR 242
 * Date:       4/12/20
 */
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include "BinarySearch.h"
#include "ItemType.h"

// TODO implement search
void BinarySearch::Search(vector<ItemType> list, ItemType key, int &location,
                          int &comparisons) {
  if (list.size() != 0) {
    int low = 0;
    int high = list.size() - 1;
    comparisons = 0;

    while (low <= high) {

      comparisons++;
      int midPoint = (low + high) / 2;

      if (key.ComparedTo(list[midPoint]) == EQUAL) {
        location = midPoint;
        break;
      } else if (key.ComparedTo(list[midPoint]) == LESS) {
        high = midPoint - 1;
      } else if (key.ComparedTo(list[0]) == LESS) {
        location = -1;
        break;

      }  else if (key.ComparedTo(list[midPoint]) == GREATER){
          location = -1;

      }else {
        low = midPoint + 1;
      }
    }
  }
}
