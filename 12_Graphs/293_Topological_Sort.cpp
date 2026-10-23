/*
QUESTION:-

Given a Directed Acyclic Graph (DAG) with V vertices numbered 0 to V-1, stored
as an adjacency list adj (adj[u] contains every vertex v with an edge u -> v),
return any valid topological ordering. In a topological ordering, for every edge
u -> v the vertex u comes before the vertex v.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000
The graph is guaranteed to have no cycle.

Example 1:

Input:
V = 6
adj = [[],[],[3],[1],[0,1],[2,0]]
(edges: 2->3, 3->1, 4->0, 4->1, 5->2, 5->0)

Output:
[5,4,2,3,1,0]
(any valid topological order is accepted)

Example 2:

Input:
V = 4
adj = [[1],[2],[3],[]]

Output:
[0,1,2,3]
*/

/*
APPROACH:-

-> A vertex must come before everything it points to. DFS gives us this if we record a vertex only AFTER all the vertices reachable from it are finished.
-> Run DFS from every unvisited vertex (the graph may have several components).
-> In the DFS of a vertex, first visit all its unvisited neighbors, and only then push the vertex on a stack.
-> So a vertex is pushed after everything that depends on it, which means the stack holds the vertices in reverse topological order.
-> Popping the stack one by one gives the topological order. Since the graph is acyclic, this order is always valid.
-> Let E be the number of edges. Every vertex and edge is processed once, so the time is V + E.
-> The visited array, the stack and the recursion take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int current, vector<vector<int>> &adj, vector<int> &visited, stack<int> &finished)
{
    visited[current] = 1;

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, finished);
        }
    }

    finished.push(current);
}

vector<int> topologicalSort(int vertices, vector<vector<int>> &adj)
{
    vector<int> visited(vertices, 0);
    stack<int> finished;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, finished);
        }
    }

    vector<int> order;

    while (!finished.empty())
    {
        order.push_back(finished.top());
        finished.pop();
    }

    return order;
}

int main()
{
    int vertices = 6;
    vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {2, 0}};

    vector<int> answer = topologicalSort(vertices, adj);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V)
*/
