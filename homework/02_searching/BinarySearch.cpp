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

  if (list.size() != 0) {

    for (int i = 0; i < list.size(); i++) {
      comparisons++;

      switch (key.ComparedTo(list[i])) {
      case LESS:

        for (int l = 0; l < list.size() / 2; l++) {
          list.erase(list.begin(), list.begin() + (list.size() / 2));
        }

        // Do something for less than
        break;
      case GREATER:
        for (int g = 0; g < list.size() / 2; g++) {
          list.erase(list.begin() + (list.size() / 2), list.end());
        }
        // Do something for greater than
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
    }
  }
}
