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

  comparisons = 0; // make sure there comparison size = 0
  location = 0;

  if (list.size() != 0) {

    for (int i = 0; i < list.size(); i++) {
      comparisons++;
      if (comparisons > list.size()) {
        break;
      }
      switch (key.ComparedTo(list[i])) {
      case LESS:
        Search(list, key, location, comparisons);
        // Do something for less than
        break;
      case GREATER:
        Search(list, key, location, comparisons);

        // Do something for greater than
        break;
      case EQUAL:
        // Do something for equal
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
/*

  ItemType midpoint;
  ItemType midValue;
  for (int i = 0; i < list.size(); i++) {
    switch (key.ComparedTo(list[i])) {
    case LESS:
      comparisons++;
      Search(list, key, location, comparisons);
      location = i;
      // Do something for less than
      break;
    case GREATER:
      Search(list, key, location, comparisons);
      comparisons++;
      location = i;
      // Do something for greater than
      break;
    case EQUAL:
      // Do something for equal
      comparisons++;
      location = i + 1;
      break;
    }
  } */