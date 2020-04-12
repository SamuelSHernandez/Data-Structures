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
static void Search(vector<ItemType> list, ItemType key, int &location,
                   int &comparisons) {

  comparisons = 0; // make sure there comparison size = 0
  assert(list.size() != 0);

  ItemType midpoint;
  ItemType midValue;
  for (int i = 0; i < list.size(); i++) {
    switch (key.ComparedTo(list[i])) {
    case LESS:
      midpoint = list.at(i);
      // Do something for less than
      break;
    case GREATER:
      // Do something for greater than
      break;
    case EQUAL:
      // Do something for equal
      break;
    }
  }
}