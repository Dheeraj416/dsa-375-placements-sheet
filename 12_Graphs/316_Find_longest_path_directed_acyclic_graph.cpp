/*
QUESTION:-

Given a weighted directed acyclic graph (DAG) with V vertices and a source
vertex, find the longest distance (the largest total weight of a path) from the
source to every other vertex. The weights can be negative. For a vertex that
cannot be reached from the source, print "NINF" (negative infinity).

Constraints:
1 <= V <= 100000
0 <= number of edges <= 200000
-1000 <= weight <= 1000

Example 1:

Input:
V = 6
edges = (0,1,5), (0,2,3), (1,3,6), (1,2,2), (2,4,4), (2,5,2), (2,3,7), (3,5,1), (3,4,-1), (4,5,-2)
source = 1

Output:
NINF 0 2 9 8 10

Example 2:

Input:
V = 3
edges = (0,1,4), (1,2,5)
source = 1

Output:
NINF 0 5
*/

/*
APPROACH:-

-> In a DAG we can process the vertices in topological order (every vertex comes after all the vertices that have an edge into it). Then when we process a vertex, its distance is already final.
-> Find a topological order with DFS: after all the neighbours of a vertex are visited, push the vertex on a list. The reverse of this list is a topological order.
-> Set dist[source] = 0 and all the other distances to negative infinity (we use the smallest int as the marker).
-> Go through the vertices in topological order. For a vertex u with a known distance, relax every edge (u, v, w): if dist[u] + w > dist[v], set dist[v] = dist[u] + w. (This is the usual shortest path relaxation, but with the sign reversed, because we want the longest path.)
-> Print the distances, writing NINF for the vertices that still have the marker.
-> Let V be the number of vertices and E the number of edges. The DFS and the relaxing each take V + E, so the time is V + E.
-> The graph, the order and the distance array take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void topologicalDfs(int u, vector<vector<pair<int, int>>> &graph, vector<bool> &visited, vector<int> &finish)
{
    visited[u] = true;

    for (int i = 0; i < (int)graph[u].size(); i++)
    {
        int v = graph[u][i].first;
        if (!visited[v])
        {
            topologicalDfs(v, graph, visited, finish);
        }
    }

    finish.push_back(u);
}

vector<int> longestPaths(int v, vector<vector<int>> &edges, int source)
{
    vector<vector<pair<int, int>>> graph(v);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    vector<bool> visited(v, false);
    vector<int> finish;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topologicalDfs(i, graph, visited, finish);
        }
    }

    vector<int> dist(v, INT_MIN);
    dist[source] = 0;

    for (int i = (int)finish.size() - 1; i >= 0; i--)
    {
        int u = finish[i];

        if (dist[u] == INT_MIN)
        {
            continue;
        }

        for (int j = 0; j < (int)graph[u].size(); j++)
        {
            int next = graph[u][j].first;
            int weight = graph[u][j].second;

            if (dist[u] + weight > dist[next])
            {
                dist[next] = dist[u] + weight;
            }
        }
    }

    return dist;
}

int main()
{
    int v = 6;
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {3, 5, 1}, {3, 4, -1}, {4, 5, -2}};

    vector<int> dist = longestPaths(v, edges, 1);

    for (int i = 0; i < v; i++)
    {
        if (dist[i] == INT_MIN)
        {
            cout << "NINF ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V + E)
*/
