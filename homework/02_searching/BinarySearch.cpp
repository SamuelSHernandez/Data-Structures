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
  location = 0;
  comparisons = 0; // make sure there comparison size = 0
  int i = 0;
  bool iterate = false;
  if (list.size() != 0) {
    do {
      i++;
      comparisons++;
      switch (key.ComparedTo(list[i])) {
      case LESS:

        // Do something for less than
        // Suposed to modify the searching bounds
        break;
      case GREATER:

        // Do something for greater than
        // Suposed to modify the searching bounds
        break;
      case EQUAL:
        location = i;
        break;
      }

      if (key.ComparedTo(list[i]) == EQUAL) {
        break;
      } else if (!key.ComparedTo(list[i])) {
        location = -1;
      }
    } while (iterate != false);
    // do while loop insted of for loop
  }
}
