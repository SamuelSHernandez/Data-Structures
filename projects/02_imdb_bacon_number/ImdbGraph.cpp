/*************************************************************************
 *
 * Project: ImdbGraph implementation
 *
 * File Name: ImdbGraph.cpp
 * Name:      ??
 * Course:    CPTR 242
 * Date:      ??
 *
 */
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include "ImdbGraph.h"
#include "SLelement.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

// Constructor
ImdbGraph::ImdbGraph() {}

// Destructor
ImdbGraph::~ImdbGraph() {}

// Function: Adds a vertex to the graph.
// Pre:  Graph has been initialized.
// Post: The actor or movie will be added as a vertex.
//          No duplicate vertics will be created.
void ImdbGraph::AddVertex(string actorOrMovie) {
  // TODO Add code here.
  unordered_map<string, Element<string> *> *vertices = graph.getVertices();
  if (vertices->find(actorOrMovie) == vertices->end()) {
    graph.addVertex(actorOrMovie);
    graph.getVisualizer(actorOrMovie)->setColor(Color("green"));
    graph.getVisualizer(actorOrMovie)->setSize(20);
    graph.getVisualizer(actorOrMovie)->setOpacity(0.10);
  }
}

// Function: Adds a edge to the graph.
// Pre:  Graph has been initialized.
//          Vertics have been already added to the graph.
// Post: The actor movie edge will be added to the graph.
//          No duplicate edges will be created.
void ImdbGraph::AddEdge(string actorOrMovie, string movieOrActor) {
  // TODO Add code here.
  graph.addEdge(actorOrMovie, movieOrActor, "1");
  graph.addEdge(movieOrActor, actorOrMovie, "1");

  graph.getLinkVisualizer(actorOrMovie, movieOrActor)->setColor(Color("black"));
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)->setColor(Color("black"));

  graph.getLinkVisualizer(actorOrMovie, movieOrActor)->setThickness(1.0);
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)->setThickness(1.0);
}

// Function: Updates the visualization for to vertex.
// Pre:  Graph has been initialized.
//          Vertex is in the graph.
// Post: The vertex will display the new color.
void ImdbGraph::VisualizeVertex(string actorOrMovie, string color) {
  // TODO Add code here.
  graph.getVisualizer(actorOrMovie)->setColor(Color(color));
  graph.getVisualizer(actorOrMovie)->setSize(50);
  graph.getVisualizer(actorOrMovie)->setOpacity(1.0);
}

// Function: Updates the visualization for to edge.
// Pre:  Graph has been initialized.
//          Edge is in the graph.
// Post: The edge will display the new color.
void ImdbGraph::VisualizeEdge(string actorOrMovie, string movieOrActor2,
                              string color) {
  // TODO Add code here.

  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setThickness(5.0);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setThickness(5.0);

  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setColor(Color(color));
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setColor(Color(color));
}

// Function: Resets all visualizations to the default.
// Pre:  Graph has been initialized.
// Post: The vertics and edges will display the default color.
void ImdbGraph::ResetVisualizer() {
  // TODO Add code here.

  // reset vertex
  for (auto &vertex : *graph.getVertices()) {
    graph.getVisualizer(vertex.first)->setColor(Color("green"));
    graph.getVisualizer(vertex.first)->setSize(20);
    graph.getVisualizer(vertex.first)->setOpacity(0.10);

    // reset edges
    auto SLinkedList = graph.getAdjacencyList(vertex.first);

    for (auto ListElement = SLinkedList; ListElement != NULL;
         ListElement = ListElement->getNext()) {

      auto destination = ((Edge<string>)ListElement->getValue()).to();
      // reset color & thickness
      graph.getLinkVisualizer(vertex.first, destination)
          ->setColor(Color("black"));
      graph.getLinkVisualizer(vertex.first, destination)->setThickness(1.0);
    }
  }
}

// Function: Calculates the Bacon Number for two actors.
//           In addition to returning the number, the graph is update to
//           highlight the path.
//           https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon
// Pre:  Graph has been initialized.
//          Vertices are in the graph.
//          Edges connect the actors in the graph.
// Post: The number returned will be lowest number of actor connections used to
// connect them.
//          The graph will visually show the path to connect the actors.
int ImdbGraph::GetBaconNumber(string sourceActor, string destinationActor) {
  // TODO Add code here.
  queue<string> frontier;
  set<string> discovered;
  map<string, int> path;
  bool found = false;
  string curr_node, initial_vertex, final_vertex;

  // add starting point
  frontier.push(sourceActor);
  discovered.insert(sourceActor);
  path.emplace(sourceActor, 0);

  while (!frontier.empty() && !found) {
    curr_node = frontier.front();
    frontier.pop();
    auto links = graph.getAdjacencyList(curr_node);

    for (auto edge = links; edge != NULL; edge = edge->getNext()) {
      initial_vertex = edge->getValue().to();
      if (discovered.count(initial_vertex) == 0) {
        discovered.insert(initial_vertex);
        frontier.push(initial_vertex);
        path.emplace(initial_vertex, path.at(curr_node) + 1);

        if (initial_vertex == destinationActor) {
          found = true;
          break;
        }
      }
    }
  }

  // depth track

  // visualize

  if (path.count(destinationActor) > 0) {
    curr_node = destinationActor;

    for (int i = path.at(destinationActor); i > 0; i--) {
      auto links = graph.getAdjacencyList(curr_node);

      for (auto edge = links; edge != NULL; edge = edge->getNext()) {
        initial_vertex = edge->getValue().to();
        final_vertex = ed->getValue().from();
        if (path.count(initial_vertex) > 0 && path.at(initial_vertex) < i) {
          VisualizeEdge(final_vertex, final_vertex, "red");
          VisualizeVertex(final_vertex, "red");
          break;
        }
      }
      VisualizeVertex(sourceActor, "green");
      VisualizeVertex(destinationActor, "blue");
    }
    return path.at(destinationActor);
  }

  return -1;
}
