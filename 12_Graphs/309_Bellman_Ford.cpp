/*
QUESTION:-

Given a weighted directed graph with V vertices numbered 0 to V-1, a list of
edges where every edge is [from, to, weight], and a source vertex S, find the
shortest distance from S to every vertex. Edge weights may be negative. If the
graph has a negative weight cycle that can be reached from S, return [-1]. A
vertex that cannot be reached from S has distance 100000000.

Constraints:
1 <= V <= 500
1 <= number of edges <= V * (V - 1)
-1000 <= weight <= 1000

Example 1:

Input:
V = 6
edges = [[0,1,5],[1,5,-3],[1,2,-2],[5,3,1],[3,2,6],[2,4,3]]
S = 0

Output:
[0,5,3,3,6,2]

Example 2:

Input:
V = 3
edges = [[0,1,1],[1,2,-1],[2,1,-1]]
S = 0

Output:
[-1]
(the cycle 1 -> 2 -> 1 has total weight -2, so the distance can keep getting smaller)
*/

/*
APPROACH:-

-> Dijkstra fails with negative weights, so we use Bellman-Ford, which simply relaxes every edge many times.
-> Relaxing an edge (from, to, weight) means: if distance[from] + weight is smaller than distance[to], update distance[to].
-> Start with distance 100000000 (infinity) for all vertices and 0 for the source.
-> A shortest path without cycles has at most V - 1 edges, so repeating the relaxation of all edges V - 1 times is enough to find all shortest distances.
-> Only relax an edge when distance[from] is not infinity, otherwise we would build values from an unreachable vertex.
-> Do one more pass over all edges. If some edge can still be relaxed, there is a negative cycle reachable from the source (the distances would keep decreasing), so return [-1].
-> Otherwise return the distance array.
-> Let E be the number of edges. We go through all edges V times, so the time is V * E.
-> Only the distance array is stored, so the space is V.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int vertices, vector<vector<int>> &edges, int source)
{
    const int INF = 100000000;
    vector<int> distance(vertices, INF);

    distance[source] = 0;

    for (int round = 1; round < vertices; round++)
    {
        for (vector<int> &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];

            if (distance[from] != INF && distance[from] + weight < distance[to])
            {
                distance[to] = distance[from] + weight;
            }
        }
    }

    for (vector<int> &edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];

        if (distance[from] != INF && distance[from] + weight < distance[to])
        {
            return {-1};
        }
    }

    return distance;
}

int main()
{
    int vertices = 6;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 5, -3}, {1, 2, -2}, {5, 3, 1}, {3, 2, 6}, {2, 4, 3}};
    int source = 0;

    vector<int> answer = bellmanFord(vertices, edges, source);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V * E)
SPACE COMPLEXITY = O(V)
*/
