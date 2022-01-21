#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <iostream>
#include <climits>

using namespace std;

class Graph {
    struct Edge {
        int dest;
        int weight
    };

    struct Node {
        list<Edge> adj;
        int dist;
        int pred;
        bool visited;
        string name;
    };

    int n;
    bool hasDir
    vector<Node> nodes;

public:
    Graph(int nodes, bool dir = false);

    void addEdge(int src, int dest, int weight = 1);
};

#endif
