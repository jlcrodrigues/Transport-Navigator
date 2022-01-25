#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Navigator/graph.h"
#include <stack>

using testing::Eq;

TEST(graph, bfs)
{
    vector<int> path;

    Graph graph = Graph(6);

    graph.addEdge(1, 2, "a");
    graph.addEdge(2, 3, "a");
    graph.addEdge(3, 4, "a");
    graph.addEdge(4, 5, "a");
    graph.addEdge(1, 5, "b");

    path = {1, 2, 3, 4};
    EXPECT_EQ(path, graph.bfsPath(1, 4));

    path = {};
    EXPECT_EQ(path, graph.bfsPath(1, 6));

    path = {1, 5};
    EXPECT_EQ(path, graph.bfsPath(1, 5));
}