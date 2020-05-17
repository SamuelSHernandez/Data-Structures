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
void GraphType<VertexType>::DeleteEdge(VertexType vertex_initial,
                                       VertexType vertex_final) {

  int row = IndexIs(vertex_initial);
  int column = IndexIs(vertex_final);

  edges[row][column] = NULL_EDGE;
}
// Keep this at the end of the file.
template class GraphType<int>;