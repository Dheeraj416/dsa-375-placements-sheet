/*
QUESTION:-

Given an undirected graph with V vertices numbered 0 to V-1, stored as an
adjacency list adj, check whether the graph is bipartite. A graph is bipartite if
its vertices can be colored with two colors so that no edge connects two
vertices of the same color. The graph may be disconnected. Return true if it is
bipartite, otherwise return false.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000
The graph has no self loops and no repeated edges.

Example 1:

Input:
V = 4
adj = [[1,3],[0,2],[1,3],[0,2]]

Output:
true
(color 0 and 2 with one color, and 1 and 3 with the other color)

Example 2:

Input:
V = 3
adj = [[1,2],[0,2],[0,1]]

Output:
false
(the triangle 0-1-2 needs three colors)
*/

/*
APPROACH:-

-> Try to color the graph with two colors (0 and 1). If a vertex gets forced to have the same color as its neighbor, the graph is not bipartite.
-> Keep a color array filled with -1 (not colored yet).
-> Use BFS: color the starting vertex 0 and push it into a queue.
-> For a vertex taken from the queue, look at every neighbor. If the neighbor is not colored, give it the opposite color (1 - color of the current vertex) and push it.
-> If the neighbor is already colored with the same color as the current vertex, two connected vertices have the same color, so return false.
-> The graph can be disconnected, so start a BFS from every vertex that is still uncolored.
-> If no conflict is found anywhere, return true.
-> Let E be the number of edges. Every vertex and edge is processed once, so the time is V + E.
-> The color array and the queue take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool bfsIsBipartite(int start, vector<vector<int>> &adj, vector<int> &color)
{
    queue<int> toVisit;

    toVisit.push(start);
    color[start] = 0;

    while (!toVisit.empty())
    {
        int current = toVisit.front();
        toVisit.pop();

        for (int neighbor : adj[current])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[current];
                toVisit.push(neighbor);
            }
            else if (color[neighbor] == color[current])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int vertices, vector<vector<int>> &adj)
{
    vector<int> color(vertices, -1);

    for (int i = 0; i < vertices; i++)
    {
        if (color[i] == -1)
        {
            if (!bfsIsBipartite(i, adj, color))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int vertices = 4;
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    bool answer = isBipartite(vertices, adj);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V)
*/
