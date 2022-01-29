#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>

#include "Stop.h"
#include "minHeap.h"

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
    void addEdge(const int& src, const int& dest, const double& dist, const string& line);

    /**
     * Set a node's stop code.
     * @param n An integer referring to a node.
     * @param code A stop's code.
     */
    void setNodeCode(const int& n, const string& code);

    /**
     * Determine if a node connects to another node.
     * @param src The origin node.
     * @param dest The destination node.
     * @return Returns true if node src connects to node dest and false otherwise.
     */
    bool connected(const int& src, const int& dest);

    /**
     * Removes edges that are over the maximum walking distance.
     * @param src The node to be inspected.
     * @param max_distance Maximum distance allowed.
     */
    void updateWalkingEdges(const int& src, const double& max_distance);

    /**
     * Uses breadth-first search to find the shortest path (less nodes).
     * The bfs' time complexity is O(V + E) and after that its O(n) to get the path.
     * @param src The starting node.
     * @param dest The destination node.
     * @return A vector of integers that represent a path from src to dest.
     */
    vector<pair<string, string> > bfsPath(const int& src, const int& dest);

    /**
     * Uses the algorithm of Dijkstra to find the shortest path (less distance).
     * The algorithm of Dijkstra's time complexity is O(E log|V|).
     * @param src The starting node.
     * @param dest The destination node.
     * @return A vector of integers that represent a path from src to dest.
     */
    vector<pair<string, string> > dijkstraPath(const int& src, const int& dest);

    /**
     * Uses the algorithm of Dijkstra to fin the shortest path (less distance).
     * @param src The starting node.
     * @param dest The destination node.
     * @return A vector of integers that represent a path from src to dest.
     */
    vector<pair<string, string> > leastLinesPath(const int& src, const int& dest);

private:
   /**
    * Chooses which line to take between to stops in order to avoid unnecessary changes.
    * @param src The starting node.
    * @param dest The destination node.
    * @param current The line being used.
    * @param prev The last line used in the path.
    * @return Returns the best line between current prev so it doesn't change unnecessarily.
    */
   string chooseLine(const int& src, const int& dest, const string& current, const string& prev) const;

   /**
    * Makes a path vector from each node's predecessor. Time complexity is O(n).
    * @param src The starting node.
    * @param dest The destination node.
    * @return Returns a vector of pairs containing the stop code and the line used.
    */
   vector<pair<string, string> > getPath(const int& src, int dest);

   struct Edge {
       int dest;
       double dist;
       string line;
   };

   struct Node {
       string code;
       list<Edge> adj;
       bool visited;
       double distance;
       pair<int, string> predecessor; //predecessor's int and code
   };

   vector<Node> nodes;
   int size;

};

#endif
