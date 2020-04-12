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
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
#include "ItemType.h"
#include "LinearSearch.h"

// TODO implement search;

void LinearSearch::Search(vector<ItemType> list, ItemType key, int &location,
                          int &comparisons) {
  comparisons = 0; // make sure there comparison size = 0
  assert(list.size() != 0);

  for (int i = 0; i < list.size(); i++) {
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
      // Do something for equal
      break;
    }
  }
}
