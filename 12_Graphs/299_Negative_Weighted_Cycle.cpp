/*
QUESTION:-

Given a weighted directed graph with V vertices (numbered from 0) and a list of
edges (u, v, w), where w can be negative, check whether the graph contains a
cycle whose total weight is negative. Return true if there is such a cycle and
false otherwise. (A cycle of total weight 0 is not a negative cycle.)

Constraints:
1 <= V <= 1000
1 <= number of edges <= 10000
-1000 <= w <= 1000

Example 1:

Input:
V = 3
edges = (0,1,-1), (1,2,-2), (2,0,1)

Output:
true
(the cycle 0 -> 1 -> 2 -> 0 has the weight -2)

Example 2:

Input:
V = 3
edges = (0,1,1), (1,2,-1), (2,0,0)

Output:
false
(the cycle has the weight 0)
*/

/*
APPROACH:-

-> Use the Bellman-Ford algorithm. It relaxes every edge V - 1 times: if dist[u] + w < dist[v], then set dist[v] = dist[u] + w. After V - 1 rounds, all the shortest distances are final when there is no negative cycle.
-> To find a negative cycle in any part of the graph (not only one reachable from one source), start with dist = 0 for all the vertices. This is like adding a hidden source that reaches every vertex with an edge of weight 0.
-> After the V - 1 rounds, do one more round over the edges. If any edge can still be relaxed, then a distance is still getting smaller, which is only possible when there is a negative cycle. Return true.
-> If no edge can be relaxed in the extra round, there is no negative cycle, so return false.
-> Let V be the number of vertices and E the number of edges. There are V rounds over E edges, so the time is V * E.
-> The distance array takes V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool hasNegativeCycle(int v, vector<vector<int>> &edges)
{
    vector<int> dist(v, 0);

    for (int round = 0; round < v - 1; round++)
    {
        for (int i = 0; i < (int)edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];

            if (dist[from] + weight < dist[to])
            {
                dist[to] = dist[from] + weight;
            }
        }
    }

    for (int i = 0; i < (int)edges.size(); i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];

        if (dist[from] + weight < dist[to])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int v = 3;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, 1}};

    bool answer = hasNegativeCycle(v, edges);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(V * E)
SPACE COMPLEXITY = O(V)
*/
