/*************************************************************************
 *
 * Assignment: Searching
 *
 * File Name:   LinearSearch.cpp
 * Name:        hernsa
 * Course:      CPTR 242
 * Date:        today
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#include "ItemType.h"
#include "LinearSearch.h"

// TODO implement search;

void LinearSearch::Search(vector<ItemType> list, ItemType key, int &location,
                          int &comparisons) {
  comparisons = 0; // make sure there comparison size = 0
  location = 0;

  for (int i = 0; i < list.size(); i++) {
    if (key.ComparedTo(list[i]) != LESS || key.ComparedTo(list[i]) != GREATER ||
        key.ComparedTo(list[i]) != EQUAL) {
      location = -1;
    } else {
      switch (key.ComparedTo(list[i])) {
      case LESS:
        // Do something for less than
        comparisons++;
        break;
      case GREATER:
        // Do something for greater than
        comparisons++;
        break;
      case EQUAL:
        comparisons++;
        location = i + 1;
        if (key.ComparedTo(list[i]) == EQUAL) {
          break;
        }
        // Do something for equal
        // TO DO: make the loop stop
        break;
      }
    }
  }
}