/*
QUESTION:-

A clique is a set of vertices in which every two vertices are connected by an
edge. Given an undirected graph as an adjacency matrix, check whether its
vertices can be divided into two cliques (every vertex belongs to exactly one of
the two sets, and either set may be empty). Return true if it is possible and
false otherwise.

Constraints:
1 <= V <= 100
graph[i][j] is 0 or 1, graph[i][j] = graph[j][i], and graph[i][i] = 0

Example 1:

Input:
graph =
0 1 1 0 0
1 0 1 0 0
1 1 0 1 0
0 0 1 0 1
0 0 0 1 0

Output:
true
(the cliques are {0,1,2} and {3,4})

Example 2:

Input:
graph =
0 1 0 0 1
1 0 1 0 0
0 1 0 1 0
0 0 1 0 1
1 0 0 1 0

Output:
false
(the graph is a cycle of 5 vertices)
*/

/*
APPROACH:-

-> Build the complement graph: it has an edge between i and j (i != j) exactly when the original graph has no edge between them.
-> A set of vertices is a clique in the original graph exactly when there is no edge of the complement graph inside the set. So dividing the vertices into two cliques means dividing them into two sets with no complement edge inside any set.
-> That is exactly the condition for the complement graph to be bipartite (two colorable). So check if the complement graph is bipartite.
-> Check bipartite with BFS coloring: color a start vertex 0, give every neighbour the opposite color, and if a neighbour already has the same color as the current vertex, the graph is not bipartite. Repeat from every vertex that is still not colored (the graph can be disconnected).
-> Let V be the number of vertices. We look at all the V * V pairs, so the time is V * V.
-> The color array and the queue take V space (the matrix itself is the input).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canSplitInTwoCliques(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++)
    {
        if (color[start] != -1)
        {
            continue;
        }

        queue<int> pending;
        color[start] = 0;
        pending.push(start);

        while (!pending.empty())
        {
            int u = pending.front();
            pending.pop();

            for (int v = 0; v < n; v++)
            {
                if (v == u || graph[u][v] == 1)
                {
                    continue;
                }

                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    pending.push(v);
                }
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};

    bool answer = canSplitInTwoCliques(graph);

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
TIME COMPLEXITY = O(V * V)
SPACE COMPLEXITY = O(V)
*/
