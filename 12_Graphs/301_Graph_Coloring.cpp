/*
QUESTION:-

Color the vertices of an undirected graph so that no two adjacent vertices (two
vertices joined by an edge) have the same color. Use the greedy method: process
the vertices in the order 0, 1, 2, ..., and give each vertex the smallest color
number (starting from 0) that is not used by any of its already colored
neighbours. Print the color of every vertex. (The greedy method does not always
use the smallest possible number of colors, but it always gives a valid coloring.)

Constraints:
1 <= V <= 1000
0 <= number of edges <= 10000

Example 1:

Input:
V = 5
edges = 0-1, 0-2, 1-2, 1-3, 2-3, 3-4

Output:
0 1 2 0 1

Example 2:

Input:
V = 3
edges = 0-1, 1-2

Output:
0 1 0
*/

/*
APPROACH:-

-> Keep an array color of size V, filled with -1 (not colored yet). Give the vertex 0 the color 0.
-> For every next vertex u, mark the colors of all its neighbours that are already colored as "used" in a boolean array (the colors are never more than V).
-> Then choose the smallest color number that is not marked as used, and give it to u.
-> Clear the marks before the next vertex. A vertex with d neighbours never needs more than d + 1 colors, so a free color always exists among the first d + 1 numbers.
-> Let V be the number of vertices and E the number of edges. Every vertex looks at its neighbours and at up to V color numbers, so the time is V * V + E.
-> The adjacency list and the arrays take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> greedyColoring(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(v);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> color(v, -1);

    for (int u = 0; u < v; u++)
    {
        vector<bool> used(v + 1, false);

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int neighbour = graph[u][i];
            if (color[neighbour] != -1)
            {
                used[color[neighbour]] = true;
            }
        }

        int chosen = 0;
        while (used[chosen])
        {
            chosen++;
        }

        color[u] = chosen;
    }

    return color;
}

int main()
{
    int v = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 4}};

    vector<int> answer = greedyColoring(v, edges);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V * V + E)
SPACE COMPLEXITY = O(V + E)
*/
