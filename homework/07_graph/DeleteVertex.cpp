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

// Pre: vertex1 is in the set of vertices
// Post: vertex1 is not in the set of vertices
template <class VertexType>
void GraphType<VertexType>::DeleteVertex(VertexType vertex) {
  int index = 0;
  int index_initial = 0;
  int index_final = 0;

  // TO DO:find vertex index
  for (int i = 0; i < numVertices; i++) {
    if (vertices[i] == vertex) {
      index = i;
    }
  }

  // TO DO:delete connections
  index_final = IndexIs(vertex);
  for (index_initial = 0; index_initial < numVertices; index_final++) {
    if (edges[index_initial][index_final] != NULL_EDGE) {
      DeleteEdge(index_initial, vertices[index_initial]);
      DeleteEdge(vertices[index_final], index_initial);
    }
  }

  // TO DO: add to unused vertices and delete it
  AddUnusedVertex(index);
  vertices[index] = 0;
}

// Keep this at the end of the file.
template class GraphType<int>;