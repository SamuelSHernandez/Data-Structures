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
      switch (key.ComparedTo(list[i])) {
      case LESS:
        break;
      case GREATER:
        break;
      case EQUAL:
        location = i;
        break;
      }

      if (key.ComparedTo(list[i]) == EQUAL) {
        break;
      } else if (key.ComparedTo(list[i]) == LESS ||
                 key.ComparedTo(list[i]) == GREATER) {
        location = -1;
        break;
      }
    }
  }
}
