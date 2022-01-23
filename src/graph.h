#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <iostream>
#include <climits>
#include "Stop.h"

using namespace std;

class Graph {
    struct Edge {
        int dest;
        string line;
    };

    struct Node {
        int src;
        list<Edge> adj;
        bool visited;
    };

    vector<Node> nodes;
    int size;

public:
   Graph() = default;
    Graph(const int& size);

    /**
     * Add an edge to the graph.
     * @param src The origin node.
     * @param dest The destination node.
     * @param line The line code connecting both nodes.
     */
    void addEdge(const int& src, const int& dest, const string& line);
};

#endif
