/*
QUESTION:-

Given a directed graph with V vertices numbered 0 to V-1, stored as an adjacency
list adj (adj[u] contains every vertex v with an edge u -> v), check whether the
graph contains a cycle. The graph may be disconnected. Return true if there is a
cycle, otherwise return false.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000
The graph has no repeated edges.

Example 1:

Input:
V = 4
adj = [[1],[2],[3],[1]]
(edges: 0->1, 1->2, 2->3, 3->1)

Output:
true
(1 -> 2 -> 3 -> 1 is a cycle)

Example 2:

Input:
V = 4
adj = [[1,2],[3],[3],[]]
(edges: 0->1, 0->2, 1->3, 2->3)

Output:
false
(vertex 3 can be reached by two paths, but there is no cycle)
*/

/*
APPROACH:-

-> In a directed graph, meeting an already visited vertex is not enough to say there is a cycle, because it may belong to a different, finished path (like vertex 3 in Example 2).
-> So keep two arrays: visited (seen at any time) and onPath (currently inside the recursion path we are exploring).
-> Run DFS. When we enter a vertex, mark it visited and onPath.
-> For every neighbor: if it is not visited, run DFS on it and return true if that finds a cycle. If it is visited and also onPath, we came back to a vertex of the current path, so there is a cycle.
-> When all neighbors are done, set onPath of the vertex back to 0 because we are leaving the path.
-> Start a DFS from every vertex that is still unvisited, so disconnected parts are covered.
-> Let E be the number of edges. Every vertex and edge is processed once, so the time is V + E.
-> The two arrays and the recursion stack take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool dfsFindsCycle(int current, vector<vector<int>> &adj, vector<int> &visited, vector<int> &onPath)
{
    visited[current] = 1;
    onPath[current] = 1;

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            if (dfsFindsCycle(neighbor, adj, visited, onPath))
            {
                return true;
            }
        }
        else if (onPath[neighbor])
        {
            return true;
        }
    }

    onPath[current] = 0;
    return false;
}

bool hasCycle(int vertices, vector<vector<int>> &adj)
{
    vector<int> visited(vertices, 0);
    vector<int> onPath(vertices, 0);

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            if (dfsFindsCycle(i, adj, visited, onPath))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int vertices = 4;
    vector<vector<int>> adj = {{1}, {2}, {3}, {1}};

    bool answer = hasCycle(vertices, adj);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V)
*/
