/*************************************************************************
 *
 * Assignment: DeleteVertex
 *
 * File Name: DeleteVertex.cpp
 * Name:        hernsa
 * Course:      CPTR 242
 * Date:        today
 */

#include "GraphType.h"

// IMPLEMENTATION FOR DeleteVertex HERE
// Pre:  vertex1 and vertex2 are in the set of vertices.
// Post: (vertex1, vertex2) is not in the set of edges

// Pre: vertex1 is in the set of vertices
// Post: vertex1 is not in the set of vertices
void GraphType<VertexType>::DeleteEdge(VertexType vertex_initial,
                                       VertexType vertex_final) {

  int row = IndexIs(vertex_initial);
  int column = IndexIs(vertex_final);

  edges[row][column] = NULL_EDGE;
}

// Keep this at the end of the file.
template class GraphType<int>;