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
#include <iostream>
#include <vector>
using namespace std;

#include "BinarySearch.h"
#include "ItemType.h"

// TODO implement search
static void Search(vector<ItemType> list, ItemType key, int &location,
                   int &comparisons) {

  enum RelationType { LESS, GREATER, EQUAL };
  
  ItemType midpoint;
  ItemType midValue;

  switch (0) {
  case LESS:
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