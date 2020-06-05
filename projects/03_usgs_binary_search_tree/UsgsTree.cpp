/*************************************************************************
 *
 * Project: UsgsTree implementation
 *
 * File Name: UsgsTree.cpp
 * Name:      hernsa
 * Course:    CPTR 242
 * Date:      june 3
 *
 */
#include "UsgsTree.h"
#include "BSTElement.h"
#include "Bridges.h"
#include "DataSource.h"
#include "bst.h"
#include "data_src/EarthquakeUSGS.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace bridges;

// Function: Finds the smallest quake magnitude in a BST.
// Pre:  BST has been initialized and populated.
// Post: The smallest quake will be visualized and returned.
EarthquakeUSGS
UsgsTree::getSmallestQuake(BSTElement<float, EarthquakeUSGS> *root,
                           string color) {

  BSTElement<float, EarthquakeUSGS> *current = root;

  while (current->getLeft() != NULL) {
    current = current->getLeft();
  }
  current->setColor(Color(color));
  return current->getValue();
}

// Function: Finds the largest quake magnitude in a BST.
// Pre:  BST has been initialized and populated.
// Post: The largest quake will be visualized and returned.
EarthquakeUSGS
UsgsTree::getLargestQuake(BSTElement<float, EarthquakeUSGS> *root,
                          string color) {

  BSTElement<float, EarthquakeUSGS> *current = root;

  while (current->getRight() != NULL) {
    current = current->getRight();
  }
  current->setColor(Color(color));
  return current->getValue();
}

// Function: Finds all nodes in the BST that are between the min and max
// parameters. Pre:  BST has been initialized and populated. Post: Returns the
// number of quakes in this range and visualizes them.
int UsgsTree::countRange(float min, float max,
                         BSTElement<float, EarthquakeUSGS> *root,
                         string color) {

  int count = 0;
  if (root == NULL) {
    return 0;
  }

  if (root->getKey() <= max && root->getValue() >= min) {
    root->setColor(Color(color));
    count++;
  }

  return count + countRange(min, max, root->getLeft(), color) +
         countRange(min, max, root->getRight(), color);
}

// Function:  Finds all nodes in the BST that in the specified location.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in this location and visualizes them.
int UsgsTree::countByLocation(string location,
                              BSTElement<float, EarthquakeUSGS> *root,
                              string color) {
  int count = 0;
  string compare = "";

  if (root == NULL) {
    return count;
  }

  compare = root->getValue().getLocation();
  size_t found = compare.find(location);

  if (found != = 1) {
    root->setColor(Color(color));
    count++
  }

  return count + countByLocation(location, root->getLeft(), color) +
         countByLocation(location, root->getRight(), color);
}

// Function: Updates all nodes and edges with a visualization.
// Pre:  BST has been initialized and populated.
// Post: Returns the number of quakes in the BST and visualizes them.
int UsgsTree::countWithStyle(BSTElement<float, EarthquakeUSGS> *root,
                             string colorVertex, string colorEdge) {
  LinkVisualizer *edge;

  // base case
  if (root == NULL) {
    return 0;
  }

  // vertex
  root->setColor(Color(colorVertex));
  // L edge
  if (root->getLeft() != NULL) {
    edge = root->getLinkVisualizer(root->getLeft());
    edge->setColor(Color(colorEdge));
  }

  // R edge
  if (root->getRight() != NULL) {
    edge = root->getLinkVisualizer(root->getRight());
    edge->setColor(Color(colorEdge));
  }

  return 1 + countWithStyle(root->getRight(), colorVertex, colorEdge) +
         countWithStyle(root->getLeft(), colorVertex, colorEdge)
}

// Function: Resets the BST visualization back to the defaults.
// Pre:  BST has been initialized and populated.
// Post: The BST has no visualizations.
void UsgsTree::resetVisualization(BSTElement<float, EarthquakeUSGS> *root) {

  LinkVisuyalizer *edge;

  root->setColor(Color("blue"));

  if (root->getLeft != NULL) {
    edge = root->getLinkVisualizer(root->getLeft());
    edge->setColor(Color("blue"));
    resetVisualization(root->getLeft());
  }

  if (root->getRight != NULL) {
    edge = root->getLinkVisualizer(root->getRight());
    edge->setColor(Color("blue"));
    resetVisualization(root->getRight());
  }
}
