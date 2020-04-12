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
    comparisons++;
    switch (key.ComparedTo(list[i])) {
    case LESS:
      // Do something for less than
      break;
    case GREATER:
      // Do something for greater than
      break;
    case EQUAL:

      location = i;

      // Do something for equal
      // TO DO: make the loop stop
      break;
    }

    if (key.ComparedTo(list[i]) == EQUAL) {
      break;
    } else if (!key.ComparedTo(list[i])) {
      location = -1;
    }
  }
}
