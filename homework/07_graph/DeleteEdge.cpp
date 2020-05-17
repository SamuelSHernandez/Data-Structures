/*************************************************************************
 *
 * Assignment: DeleteEdge
 *
 * File Name: DeleteEdge.cpp
 * Name:        Hernsa
 * Course:      CPTR 242
 * Date:        today
 */

#include "GraphType.h"

// IMPLEMENTATION FOR DeleteEdge HERE
// Pre:  vertex1 and vertex2 are in the set of vertices.
// Post: (vertex1, vertex2) is not in the set of edges
template <class VertexType>

void GraphType<VertexType>::DeleteEdge(VertexType vertex_initial,
                                       VertexType vertex_final) {
  int row = IndexIs(vertex_initial);
  int col = IndexIs(vertex_final);

  edges[row][col] = NULL_EDGE;
}

// Keep this at the end of the file.
template class GraphType<int>;