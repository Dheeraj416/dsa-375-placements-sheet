/*
QUESTION:-

Given a connected undirected graph with V vertices numbered 0 to V-1, stored as
an adjacency list adj, return the Depth First Search (DFS) traversal of the
graph starting from vertex 0. Visit the neighbors of a vertex in the same order
in which they appear in its list.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000
The graph has no self loops and no repeated edges.

Example 1:

Input:
V = 5
adj = [[2,3,1],[0],[0,4],[0],[2]]

Output:
[0,2,4,3,1]

Example 2:

Input:
V = 5
adj = [[1,2],[0,2],[0,1,3,4],[2],[2]]

Output:
[0,1,2,3,4]
*/

/*
APPROACH:-

-> DFS goes as deep as possible along one path before coming back, so use recursion (the call stack works like a stack).
-> Keep a visited array so that a vertex is never visited twice.
-> Start at vertex 0: mark it visited and add it to the answer.
-> Then go through its neighbors in list order. For every neighbor that is not visited, call DFS on it.
-> When all neighbors of a vertex are finished, the function returns and the traversal continues from the previous vertex.
-> Example 1: 0 goes to 2, 2 goes to 4, then we come back to 0 and visit 3 and finally 1.
-> Let E be the number of edges. Every vertex is visited once and every edge is checked twice, so the time is V + E.
-> The visited array and the recursion stack take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int current, vector<vector<int>> &adj, vector<int> &visited, vector<int> &order)
{
    visited[current] = 1;
    order.push_back(current);

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, order);
        }
    }
}

vector<int> dfsOfGraph(int vertices, vector<vector<int>> &adj)
{
    vector<int> visited(vertices, 0);
    vector<int> order;

    dfs(0, adj, visited, order);

    return order;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> answer = dfsOfGraph(vertices, adj);

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
