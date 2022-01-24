#include "graph.h"

Graph::Graph(const int& size) : nodes(size + 1) {
    this->size = size;
}

void Graph::addEdge(const int& src, const int& dest, const string& line)
{
    if (src < 1 || src > size || dest < 1 || dest > size) return;
    nodes[src].adj.push_back({dest, line});
}

vector<int> Graph::bfsPath(int src, int dest)
{
    bfs(src);
    if (nodes[dest].predecessor == 0) return {};
    vector<int> path;
    while (nodes[dest].predecessor != 0)
    {
        path.push_back(dest);
        dest = nodes[dest].predecessor;
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

void Graph::bfs(int src) {
    for (int v=1; v <= size; v++) {
        nodes[v].visited = false;
        nodes[v].predecessor = 0;
    }
    queue<int> q;
    q.push(src);
    nodes[src].visited = true;
    nodes[src].distance = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto e : nodes[u].adj)
        {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                nodes[w].predecessor = u;
            }
        }
    }
}