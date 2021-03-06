#include "graph.h"

Graph::Graph(const int& size) : nodes(size + 1) {
    this->size = size;
}

void Graph::addEdge(const int& src, const int& dest, const double& dist, const string& line)
{
    if (src < 1 || src > size || dest < 1 || dest > size) return;
    nodes[src].adj.push_back({dest, dist, line});
}

void Graph::setNodeCode(const int& n, const string& code, const string& zone)
{
    nodes[n].code = code;
    nodes[n].predecessor = {0, ""};
    nodes[n].zone = zone;
}

bool Graph::connected(const int &src, const int &dest)
{
    for (auto e: nodes[src].adj)
    {
        if (e.dest == dest) return true;
    }
    return false;
}

void Graph::updateWalkingEdges(const int& src, const double &max_distance)
{
    list<Edge>::iterator it = nodes[src].adj.begin();
    while (it != nodes[src].adj.end())
    {
        if (max_distance < it->dist && it->line == "_WALK")
        {
            it = nodes[src].adj.erase(it);
        }
        else
            ++it;
    }
}

vector<pair<string, string> > Graph::bfsPath(const int& src, const int& dest)
{
    if (!validStop(nodes[src].code)) return {};
    for (int v=1; v <= size; v++) {
        nodes[v].visited = false;
        nodes[v].predecessor = {0, ""};
        nodes[v].distance_walked = 0;
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
            if (!nodes[w].visited && validLine(e.line) && validStop(nodes[w].code)) {
                if (!(walking_distance < nodes[u].distance_walked && e.line == "_WALK")) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    nodes[w].predecessor = {u, chooseLine(u, w, e.line, nodes[u].predecessor.second)};
                    nodes[w].distance_walked = nodes[u].distance_walked;
                    if (e.line == "_WALK") nodes[w].distance_walked += e.dist;
                }
            }
        }
    }
    return getPath(src, dest);
}

vector<pair<string, string> > Graph::dijkstraPath(const int &src, const int &dest) {
    if (!validStop(nodes[src].code)) return {};
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
            if (!nodes[e.dest].visited
                    && nodes[e.dest].distance > nodes[x].distance + e.dist
                    && validLine(e.line) && validStop(nodes[e.dest].code)) {
                if (nodes[x].predecessor.second != "_WALK" || e.line != "_WALK") {
                    nodes[e.dest].distance = nodes[x].distance + e.dist;
                    nodes[e.dest].predecessor = {x, chooseLine(x, e.dest, e.line, nodes[x].predecessor.second)};
                    if (!h.hasKey(e.dest)) {
                        h.insert(e.dest, nodes[e.dest].distance);
                    } else {
                        h.decreaseKey(e.dest, nodes[e.dest].distance);
                    }
                }
            }
        }
    }
    return getPath(src, dest);
}

vector<pair<string, string> > Graph::leastLinesPath(const int &src, const int &dest) {
    if (!validStop(nodes[src].code)) return {};
    for (int i=1;i<=size;i++){
        nodes[i].distance = INT_MAX;
        nodes[i].visited = false;
        nodes[i].predecessor = {0, ""};
        nodes[i].distance_walked = 0;
    }
    nodes[src].distance = 0;
    MinHeap<int,int> h (size,-1);
    h.insert(src, nodes[src].distance);
    while(h.getSize()>0)
    {
        int x = h.removeMin();
        nodes[x].visited = true;
        for (Edge e: nodes[x].adj)
        {
            if(!nodes[e.dest].visited
                    && nodes[e.dest].distance > nodes[x].distance
                    && validLine(e.line) && validStop(nodes[e.dest].code))
            {
                if (!(walking_distance < nodes[x].distance_walked && e.line == "_WALK"))
                {
                    nodes[e.dest].distance = nodes[x].distance;
                    if (e.line != nodes[x].predecessor.second) {
                        nodes[e.dest].distance = nodes[x].distance + 1;
                    }
                    nodes[e.dest].predecessor = {x, chooseLine(x, e.dest, e.line, nodes[x].predecessor.second)};
                    if (!h.hasKey(e.dest)) {
                        h.insert(e.dest, nodes[e.dest].distance);
                    } else {
                        h.decreaseKey(e.dest, nodes[e.dest].distance);
                    }
                    nodes[e.dest].distance_walked = nodes[x].distance_walked;
                    if (e.line == "_WALK") nodes[e.dest].distance_walked += e.dist;
                }
            }
        }
    }
    return getPath(src, dest);
}

vector<pair<string, string> > Graph::leastZonesPath(const int &src, const int &dest) {
    if (!validStop(nodes[src].code)) return {};
    for (int i=1;i<=size;i++){
        nodes[i].distance = INT_MAX;
        nodes[i].visited = false;
        nodes[i].predecessor = {0, ""};
        nodes[i].distance_walked = 0;
    }
    nodes[src].distance = 0;
    MinHeap<int,int> h (size,-1);
    h.insert(src, nodes[src].distance);
    while(h.getSize()>0){
        int x = h.removeMin();
        nodes[x].visited = true;
        for (Edge e: nodes[x].adj){
            if(!nodes[e.dest].visited && nodes[e.dest].distance > nodes[x].distance
                && validLine(e.line) && validStop(nodes[e.dest].code)){
                if (!(walking_distance < nodes[x].distance_walked && e.line == "_WALK")) {
                    nodes[e.dest].distance = nodes[x].distance;
                    if (nodes[x].zone != nodes[e.dest].zone) {
                        nodes[e.dest].distance = nodes[x].distance + 1;
                    }
                    nodes[e.dest].predecessor = {x, chooseLine(x, e.dest, e.line, nodes[x].predecessor.second)};
                    if (!h.hasKey(e.dest)) {
                        h.insert(e.dest, nodes[e.dest].distance);
                    } else {
                        h.decreaseKey(e.dest, nodes[e.dest].distance);
                    }
                    nodes[e.dest].distance_walked = nodes[x].distance_walked;
                    if (e.line == "_WALK") nodes[e.dest].distance_walked += e.dist;
                }
            }
        }
    }
    return getPath(src, dest);
}

void Graph::setTime(const bool &time) {day_travel = time;}

void Graph::setWalkingDistance(const double &distance) {walking_distance = distance;}

void Graph::setBlockedSet(set<string> *lines, set<string>* stops)
{
    this->blocked_lines = lines;
    this->blocked_stops = stops;
}

string Graph::chooseLine(const int& src, const int& dest, const string& current, const string& prev) const
{
    for (auto e: nodes[src].adj)
    {
        if (e.dest == dest)
        {
            if (e.line == prev) return prev;
        }
    }
    return current;
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

bool Graph::validLine(const string &code)
{
    if (day_travel == (code.back() == 'M')) return false;

    auto it = blocked_lines->begin();
    for (; it != blocked_lines->end(); it++)
    {
        if (code == *it) return false;
    }
    return true;
}

bool Graph::validStop(const string &code)
{
    auto it = blocked_stops->begin();
    for (; it != blocked_stops->end(); it++)
    {
        if (code == *it) return false;
    }
    return true;
}
