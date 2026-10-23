/*
QUESTION:-

Given a directed graph with V vertices numbered 0 to V-1, stored as an adjacency
list adj (adj[u] contains every vertex v with an edge u -> v), return the number
of Strongly Connected Components (SCCs). An SCC is a maximal group of vertices
in which every vertex can reach every other vertex of the group.

Constraints:
1 <= V <= 10000
0 <= number of edges <= 10000

Example 1:

Input:
V = 5
adj = [[2,3],[0],[1],[4],[]]
(edges: 0->2, 0->3, 1->0, 2->1, 3->4)

Output:
3
(the components are {0,1,2}, {3} and {4})

Example 2:

Input:
V = 3
adj = [[1],[2],[0]]

Output:
1
(0 -> 1 -> 2 -> 0 is one big cycle)
*/

/*
APPROACH:-

-> Kosaraju's algorithm uses the fact that reversing all edges keeps the SCCs the same but stops one SCC from reaching another.
-> Step 1: run DFS on the original graph and push every vertex on a stack when it is finished. The vertex that finishes last is on top and belongs to a "source" component.
-> Step 2: build the reversed graph (for every edge u -> v add an edge v -> u).
-> Step 3: pop vertices from the stack. If a vertex is not visited yet, run DFS on the reversed graph from it. Everything reached is exactly one SCC, so increase the count.
-> It works because in the reversed graph a DFS started from the top of the stack cannot escape into another component, since the edges leaving this component now point backwards.
-> Let E be the number of edges. We run two full DFS passes and build the reversed graph, so the time is V + E.
-> The reversed graph, visited array and stack together take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void fillOrder(int current, vector<vector<int>> &adj, vector<int> &visited, stack<int> &finished)
{
    visited[current] = 1;

    for (int neighbor : adj[current])
    {
        if (!visited[neighbor])
        {
            fillOrder(neighbor, adj, visited, finished);
        }
    }

    finished.push(current);
}

void dfsOnReversed(int current, vector<vector<int>> &reversedAdj, vector<int> &visited)
{
    visited[current] = 1;

    for (int neighbor : reversedAdj[current])
    {
        if (!visited[neighbor])
        {
            dfsOnReversed(neighbor, reversedAdj, visited);
        }
    }
}

int countStronglyConnectedComponents(int vertices, vector<vector<int>> &adj)
{
    vector<int> visited(vertices, 0);
    stack<int> finished;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            fillOrder(i, adj, visited, finished);
        }
    }

    vector<vector<int>> reversedAdj(vertices);

    for (int u = 0; u < vertices; u++)
    {
        for (int v : adj[u])
        {
            reversedAdj[v].push_back(u);
        }
    }

    fill(visited.begin(), visited.end(), 0);

    int components = 0;

    while (!finished.empty())
    {
        int current = finished.top();
        finished.pop();

        if (!visited[current])
        {
            components++;
            dfsOnReversed(current, reversedAdj, visited);
        }
    }

    return components;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};

    int answer = countStronglyConnectedComponents(vertices, adj);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V + E)
*/
