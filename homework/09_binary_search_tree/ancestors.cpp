/****************************************************************************
 *
 * Homework: Implement a three functions for printing tree ancestors.
 *
 * File Name:  ancestors.cpp
 * Name:       hernsa
 * Course:     CPTR 242
 * Date:       1 June 2020
 *
 */
#include "TreeType.h"

void TreeType::AncestorsIterative(ItemType value, std::ofstream &outFile) {
  // TODO implement ancestors iterative print
  TreeNode *cur;
  cur = root;

  while (cur->info != value) {
    outFile << cur->info;

    if (value != cur->info) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }
}

void PrintAncestorsRecursive(TreeNode *tree, ItemType value,
                             std::ofstream &outFile) {

  // TODO implement ancestors recursive print
  if (tree->info == value) {
    return;
  }
  outFile << tree->info;

  if (value < tree->info) {
    PrintAncestorsRecursive(tree->left, value, outFile);
  } else {
    PrintAncestorsRecursive(tree->right, value, outFile);
  }
}

void PrintAncestorsReverse(TreeNode *tree, ItemType value,
                           std::ofstream &outFile) {
  // TODO implement ancestors reverse print
  outFile << tree->info;
  return;
}