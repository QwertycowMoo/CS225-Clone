/**
 * @file NetworkFlow.cpp
 * CS 225: Data Structures
 */

#include <vector>
#include <algorithm>
#include <set>

#include "graph.h"
#include "edge.h"

#include "NetworkFlow.h"
#include <iostream>

int min(int a, int b) {
  if (a<b)
    return a;
  else return b;
}

NetworkFlow::NetworkFlow(Graph & startingGraph, Vertex source, Vertex sink) :
  g_(startingGraph), residual_(Graph(true,true)), flow_(Graph(true,true)), source_(source), sink_(sink) {

  // YOUR CODE HERE
  for (Vertex v : g_.getVertices()) {
    residual_.insertVertex(v);
    flow_.insertVertex(v);
  }
  for (Edge e : startingGraph.getEdges()) {
    residual_.insertEdge(e.source, e.dest);
    residual_.setEdgeWeight(e.source, e.dest, startingGraph.getEdgeWeight(e.source, e.dest));

    flow_.insertEdge(e.source, e.dest);
    flow_.setEdgeWeight(e.source, e.dest, 0);

    residual_.insertEdge(e.dest, e.source);
    residual_.setEdgeWeight(e.dest, e.source, 0);
  }

}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the helper function.
   *
   * @param source  The starting (current) vertex
   * @param sink    The destination vertex
   * @param path    The vertices in the path
   * @param visited A set of vertices we have visited
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, 
  std::vector<Vertex> &path, std::set<Vertex> &visited) {

  if (visited.count(source) != 0)
    return false;
  visited.insert(source);

  if (source == sink) {
    return true;
  }

  vector<Vertex> adjs = residual_.getAdjacent(source);
  for(auto it = adjs.begin(); it != adjs.end(); it++) {
    if (visited.count(*it) == 0 && residual_.getEdgeWeight(source,*it) > 0) {
      path.push_back(*it);
      if (findAugmentingPath(*it,sink,path,visited))
        return true;
      else {
        path.pop_back();
      }
    }
  }

  return false;
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the main function.  It initializes a set to keep track of visited vertices.
   *
   * @param source The starting (current) vertex
   * @param sink   The destination vertex
   * @param path   The vertices in the path
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, std::vector<Vertex> &path) {
   std::set<Vertex> visited;
   path.clear();
   path.push_back(source);
   return findAugmentingPath(source,sink,path,visited);
}

  /**
   * pathCapacity - Determine the capacity of a path in the residual graph.
   *
   * @param path   The vertices in the path
   */

int NetworkFlow::pathCapacity(const std::vector<Vertex> & path) const {
  // YOUR CODE HERE
  int minCap = INT_MAX;
  Vertex begin = path[0];
  for (size_t i = 1; i < path.size(); i++) {
    Vertex end = path[i];
    int weight = residual_.getEdgeWeight(begin, end);
    minCap = min(minCap, weight);
    begin = end;
  }
  return minCap;
}

  /**
   * calculuateFlow - Determine the capacity of a path in the residual graph.
   * Sets the member function `maxFlow_` to be the flow, and updates the
   * residual graph and flow graph according to the algorithm.
   *
   * @return The network flow graph.
   */

const Graph & NetworkFlow::calculateFlow() {
  // YOUR CODE HERE
  maxFlow_ = 0;
  std::vector<Vertex> path;
  while (findAugmentingPath(source_, sink_, path)) {
    
    int capacity = pathCapacity(path);
    
    maxFlow_ += capacity;
    Vertex src = path[0];
    for (size_t i = 1; i < path.size(); i++) {
      Vertex dest = path[i];
      if (flow_.getEdgeWeight(src, dest) == Graph::InvalidWeight) {
        //going through a path that doesn't exist on regular graph, only on residual
        int f_edge = flow_.getEdgeWeight(dest, src);
        flow_.setEdgeWeight(dest, src, f_edge - capacity);
        int r_edge_with = residual_.getEdgeWeight(src, dest);
        int r_edge_against = residual_.getEdgeWeight(dest, src);
        residual_.setEdgeWeight(src, dest, r_edge_with - capacity);
        residual_.setEdgeWeight(dest, src, r_edge_against + capacity);
      } else {
        //going through a regular path
        int f_edge = flow_.getEdgeWeight(src, dest);
        flow_.setEdgeWeight(src, dest, f_edge + capacity);
        int r_edge_with = residual_.getEdgeWeight(src, dest);
        int r_edge_against = residual_.getEdgeWeight(dest, src);
        residual_.setEdgeWeight(src, dest, r_edge_with - capacity);
        residual_.setEdgeWeight(dest, src, r_edge_against + capacity);
      }
      src = dest;
    }
  }
  
  return flow_;
}

int NetworkFlow::getMaxFlow() const {
  return maxFlow_;
}

const Graph & NetworkFlow::getGraph() const {
  return g_;
}

const Graph & NetworkFlow::getFlowGraph() const {
  return flow_;
}

const Graph & NetworkFlow::getResidualGraph() const {
  return residual_;
}

