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

vector<int> Graph::dijkstra_dist(int a, int b) {
    vector<int> path;
    for (int i=1;i<=size;i++){
        nodes[i].distance = INT_MAX;
        nodes[i].visited = false;
        nodes[i].predecessor = -1;
    }
    nodes[a].distance = 0;
    MinHeap<int,int> h (size,-1);
    h.insert(a,nodes[a].distance);
    nodes[a].predecessor = a;
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
    path.push_back(b);
    while(b!=a){
        b = nodes[b].predecessor;
        if(b==-1){return {};}
        path.push_back(b);
    }
    reverse(path.begin(),path.end());
    return path;
}