#include "graph.h"

Graph::Graph(const int& size) : nodes(size) {
    this->size = size;
}

void Graph::addEdge(const int& src, const int& dest, const string& line)
{
    if (src < 0 || src > size - 1 || dest < 0 || dest > size - 1) return;
    nodes[src].adj.push_back({dest, line});
}