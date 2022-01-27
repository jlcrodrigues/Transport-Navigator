#include "graph.h"
#include "minHeap.h"

Graph::Graph(const int& size) : nodes(size + 1) {
    this->size = size;
}

void Graph::addEdge(const int& src, const int& dest, const double& dist, const string& line)
{
    if (src < 1 || src > size || dest < 1 || dest > size) return;
    nodes[src].adj.push_back({dest, dist, line});
}

void Graph::setNodeCode(const int& n, const string& code)
{
    nodes[n].code = code;
}

vector<string> Graph::bfsPath(int src, int dest)
{
    bfs(src);
    if (nodes[dest].predecessor == 0) return {};
    vector<string> path;
    while (nodes[dest].predecessor != 0)
    {
        path.push_back(nodes[dest].code);
        dest = nodes[dest].predecessor;
    }
    path.push_back(nodes[src].code);
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

vector<string> Graph::dijkstra_dist(const int& src, const int& dest) {
    for (int i=1;i<=size;i++){
        nodes[i].distance = INT_MAX;
        nodes[i].visited = false;
        nodes[i].predecessor = -1;
    }
    nodes[src].distance = 0;
    MinHeap<int,int> h (size,-1);
    h.insert(src, nodes[src].distance);
    nodes[src].predecessor = src;
    while(h.getSize()>0){
        int x = h.removeMin();
        nodes[x].visited = true;
        for (Edge e: nodes[x].adj){
            if(!nodes[e.dest].visited && nodes[e.dest].distance > nodes[x].distance + e.dist){
                nodes[e.dest].distance = nodes[x].distance + e.dist;
                nodes[e.dest].predecessor = x;
                if(!h.hasKey(e.dest)){
                    h.insert(e.dest, nodes[e.dest].distance);
                }
                else{
                    h.decreaseKey(e.dest, nodes[e.dest].distance);

                }
            }
        }
    }
    vector<string> path;
    int stop = dest;
    path.push_back(nodes[stop].code);
    while(stop != src){
        stop = nodes[stop].predecessor;
        if (stop == -1) {return {};}
        path.push_back(nodes[stop].code);
    }
    reverse(path.begin(),path.end());
    return path;
}