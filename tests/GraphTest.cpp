#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Navigator/graph.h"
#include <stack>

using testing::Eq;

TEST(graph, bfs)
{
    vector<int> path;

    Graph graph = Graph(6);

    graph.addEdge(1, 2,1, "a");
    graph.addEdge(2, 3,1, "a");
    graph.addEdge(3, 4,1, "a");
    graph.addEdge(4, 5,1, "a");
    graph.addEdge(1, 5,1, "b");

    path = {1, 2, 3, 4};
    EXPECT_EQ(path, graph.bfsPath(1, 4));

    path = {};
    EXPECT_EQ(path, graph.bfsPath(1, 6));

    path = {1, 5};
    EXPECT_EQ(path, graph.bfsPath(1, 5));
}

TEST(graph,dijkstra)
{
    vector<int> path;

    Graph graph = Graph(6);

    graph.addEdge(1, 2,5, "a");
    graph.addEdge(2, 3,6, "a");
    graph.addEdge(1,3,9,"c");
    graph.addEdge(2,4,15,"d");
    graph.addEdge(3, 4,7, "a");
    graph.addEdge(4, 5,8, "a");
    graph.addEdge(1, 5,9, "b");

    path = {1,5};
    EXPECT_EQ(path,graph.dijkstra_dist(1,5));

    path = {1,3,4};
    EXPECT_EQ(path,graph.dijkstra_dist(1,4));

    path = {2,3,4};
    EXPECT_EQ(path,graph.dijkstra_dist(2,4));
}