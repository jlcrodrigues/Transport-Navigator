#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>
#include "Stop.h"

using namespace std;

class Graph {

public:
   Graph() = default;
    Graph(const int& size);

    /**
     * Add an edge to the graph in O(1) time complexity.
     * @param src The origin node.
     * @param dest The destination node.
     * @param line The line code connecting both nodes.
     */
    void addEdge(const int& src, const int& dest, const string& line);

    /**
     * Uses bfs to find the shortest path (less nodes). After the bfs, time complexity is O(n).
     * @param src The starting node.
     * @param dest The destination node.
     * @return A vector of integers that represent a path from src to dest.
     */
    vector<int> bfsPath(int src, int dest);

private:
   struct Edge {
       int dest;
       string line;
   };

   struct Node {
       int src;
       list<Edge> adj;
       bool visited;
       int distance;
       int predecessor;
   };

   vector<Node> nodes;
   int size;

   /**
    * Breadth-First search. Time complexity is O(V + E).
    * @param src The starting node for the search.
    */
   void bfs(int src);
};

#endif
