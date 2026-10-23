/*
QUESTION:-

An undirected graph with n vertices (numbered from 0) and a list of edges is
given. Check whether the graph is a tree. A graph is a tree if it is connected
and has no cycle. Return true if it is a tree, and false otherwise.

Constraints:
1 <= n <= 100000
0 <= number of edges <= 100000
There are no self loops and no repeated edges.

Example 1:

Input:
n = 5
edges = [[0,1],[0,2],[0,3],[3,4]]

Output:
true

Example 2:

Input:
n = 5
edges = [[0,1],[1,2],[2,0],[3,4]]

Output:
false
(there is a cycle 0-1-2 and the vertices 3, 4 are not connected to it)
*/

/*
APPROACH:-

-> A tree with n vertices always has exactly n - 1 edges. So if the number of edges is not n - 1, return false at once.
-> A connected graph with n vertices and n - 1 edges has no cycle (otherwise it could not reach all n vertices with so few edges). So we only need to check that the graph is connected.
-> Build the adjacency list, then run a BFS from vertex 0 and count how many vertices were visited.
-> If all n vertices are visited, the graph is connected, so it is a tree. Otherwise it is not.
-> Let V be the number of vertices and E the number of edges. The BFS visits every vertex and edge once, so the time is V + E.
-> The adjacency list and the visited array take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isTree(int n, vector<vector<int>> &edges)
{
    if ((int)edges.size() != n - 1)
    {
        return false;
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, false);
    queue<int> pending;
    pending.push(0);
    visited[0] = true;
    int count = 1;

    while (!pending.empty())
    {
        int node = pending.front();
        pending.pop();

        for (int i = 0; i < (int)graph[node].size(); i++)
        {
            int next = graph[node][i];

            if (!visited[next])
            {
                visited[next] = true;
                count++;
                pending.push(next);
            }
        }
    }

    return count == n;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {3, 4}};

    bool answer = isTree(n, edges);

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
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V + E)
*/
