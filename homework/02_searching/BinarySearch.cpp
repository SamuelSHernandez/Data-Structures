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
  int low = 0;
  int high = list.size() - 1;
  comparisons = 0;
  int midPoint = (low + high) / 2;
  while (low <= high) {
    comparisons++;
    switch (key.ComparedTo(list[midPoint])) {
    case LESS:
      // Do something for less than
      high = midPoint - 1;
      break;
    case GREATER:
      // Do something for greater than
      low = midPoint + 1;
      break;
    case EQUAL:
      // Do something for equal
      location = midPoint;
      break;
    }
  }
}