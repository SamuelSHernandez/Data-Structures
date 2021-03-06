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
  if (list.size() != 0) {

    location = 0;    // location starts at root of vector
    comparisons = 0; // make sure there comparison size = 0

    for (int i = 0; i < list.size(); i++) {
      comparisons++;

      if (key.ComparedTo(list[i]) == EQUAL) {
        location = i;
        break;
      } else if (key.ComparedTo(list[0]) == LESS) {
        location = -1;
        break;

      } else if (key.ComparedTo(list[i]) > key.ComparedTo(list[i + 1])) {
        location = -1;
        comparisons++;
        break;

      } else if (key.ComparedTo(list[i]) == GREATER) {
        location = -1;
      }
    }
  }
}
