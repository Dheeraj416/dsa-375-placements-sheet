/*
QUESTION:-

Given an undirected graph with V vertices numbered 0 to V-1, stored as an
adjacency list adj, check whether the graph contains a cycle. The graph may be
disconnected (it can have several components). Return true if there is a cycle,
otherwise return false.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000
The graph has no self loops and no repeated edges.

Example 1:

Input:
V = 5
adj = [[1],[0],[3,4],[2,4],[2,3]]

Output:
true
(vertices 2, 3, 4 form a triangle in the second component)

Example 2:

Input:
V = 4
adj = [[1,2],[0],[0,3],[2]]

Output:
false
(the graph is the path 1-0-2-3)
*/

/*
APPROACH:-

-> Use DFS (recursion) and pass the parent of the current vertex along with it.
-> Mark the current vertex visited and go through its neighbors.
-> If a neighbor is not visited, call DFS on it with the current vertex as its parent. If that call finds a cycle, return true.
-> If a neighbor is already visited and it is NOT the parent, we found a second way to reach it, so there is a cycle.
-> The parent is skipped because the edge back to the parent is the edge we just used.
-> The graph can be disconnected, so start a DFS from every vertex that is still unvisited (the first call uses parent -1).
-> Let E be the number of edges. Every vertex and edge is processed once overall, so the time is V + E.
-> The visited array and the recursion stack take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool dfsFindsCycle(int current, int parent, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[current] = 1;

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            if (dfsFindsCycle(neighbor, current, adj, visited))
            {
                return true;
            }
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }

    return false;
}

bool hasCycle(int vertices, vector<vector<int>> &adj)
{
    vector<int> visited(vertices, 0);

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            if (dfsFindsCycle(i, -1, adj, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj = {{1}, {0}, {3, 4}, {2, 4}, {2, 3}};

    bool answer = hasCycle(vertices, adj);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V)
*/
