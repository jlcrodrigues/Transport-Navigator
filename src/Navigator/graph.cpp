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
    nodes[n].predecessor = {0, ""};
}

vector<pair<string, string> > Graph::getPath(const int& src, int dest)
{
    if (nodes[dest].predecessor.first == 0) return {};
    vector<pair<string, string> > path;
    do {
        path.push_back({nodes[dest].code, nodes[dest].predecessor.second});
        dest = nodes[dest].predecessor.first;
    } while (dest != 0);
    reverse(path.begin(), path.end());
    return path;

}

vector<pair<string, string> > Graph::bfsPath(const int& src, const int& dest)
{
    for (int v=1; v <= size; v++) {
        nodes[v].visited = false;
        nodes[v].predecessor = {0, ""};
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
                nodes[w].predecessor = {u, e.line};
            }
        }
    }
    return getPath(src, dest);
}

vector<pair<string, string> > Graph::dijkstraPath(const int& src, const int& dest) {
    for (int i=1;i<=size;i++){
        nodes[i].distance = INT_MAX;
        nodes[i].visited = false;
        nodes[i].predecessor = {0, ""};
    }
    nodes[src].distance = 0;
    MinHeap<int,int> h (size,-1);
    h.insert(src, nodes[src].distance);
    while(h.getSize()>0){
        int x = h.removeMin();
        nodes[x].visited = true;
        for (Edge e: nodes[x].adj){
            if(!nodes[e.dest].visited && nodes[e.dest].distance > nodes[x].distance + e.dist){
                nodes[e.dest].distance = nodes[x].distance + e.dist;
                nodes[e.dest].predecessor = {x, e.line};
                if(!h.hasKey(e.dest)){
                    h.insert(e.dest, nodes[e.dest].distance);
                }
                else{
                    h.decreaseKey(e.dest, nodes[e.dest].distance);

                }
            }
        }
    }
    return getPath(src, dest);
}