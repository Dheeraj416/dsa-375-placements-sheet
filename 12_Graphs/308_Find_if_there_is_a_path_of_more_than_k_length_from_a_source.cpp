/*
QUESTION:-

Given a weighted undirected graph, a source vertex and a number k, check whether
there is a simple path (a path that does not visit any vertex twice) starting at
the source whose total length is strictly more than k. Return true if such a
path exists and false otherwise.

Constraints:
1 <= V <= 20
0 <= number of edges <= 100
1 <= weight <= 1000

Example 1:

Input:
V = 4
edges = (0,1,5), (1,2,10), (2,3,20)
src = 0, k = 30

Output:
true
(the path 0 -> 1 -> 2 -> 3 has the length 35)

Example 2:

Input:
V = 4
edges = (0,1,5), (1,2,10), (2,3,20)
src = 0, k = 35

Output:
false
(the longest simple path from 0 has the length 35, which is not more than 35)
*/

/*
APPROACH:-

-> Use DFS with backtracking. Walk from the source along the edges and keep a visited mark for the vertices on the current path.
-> Instead of adding up the length, keep the remaining amount k that the path still has to exceed. When we go over an edge of weight w, the remaining amount becomes k - w.
-> If the remaining amount is below 0 at some vertex, the path so far is longer than the original k, so return true.
-> At a vertex, try every neighbour that is not on the current path. If any recursive call returns true, return true.
-> When all the neighbours fail, remove the vertex from the current path (backtrack), so that other paths can use it, and return false.
-> Let V be the number of vertices. In the worst case every simple path is tried, so the time is V! (factorial).
-> The recursion goes at most V deep, so the space is V.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool longerThanK(vector<vector<pair<int, int>>> &graph, int node, int remaining, vector<bool> &onPath)
{
    if (remaining < 0)
    {
        return true;
    }

    onPath[node] = true;

    for (int i = 0; i < (int)graph[node].size(); i++)
    {
        int next = graph[node][i].first;
        int weight = graph[node][i].second;

        if (onPath[next])
        {
            continue;
        }

        if (longerThanK(graph, next, remaining - weight, onPath))
        {
            return true;
        }
    }

    onPath[node] = false;
    return false;
}

int main()
{
    int v = 4;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 10}, {2, 3, 20}};
    int src = 0;
    int k = 30;

    vector<vector<pair<int, int>>> graph(v);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<bool> onPath(v, false);
    bool answer = longerThanK(graph, src, k, onPath);

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
TIME COMPLEXITY = O(V!)
SPACE COMPLEXITY = O(V)
*/
