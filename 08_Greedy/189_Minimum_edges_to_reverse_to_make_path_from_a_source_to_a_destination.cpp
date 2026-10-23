/*
QUESTION:-

You are given a directed graph with n nodes (numbered from 0) and a list of
directed edges. Find the minimum number of edges that must be reversed so that
there is at least one path from the source node to the destination node. If
there is no way to get a path even after reversing edges, return -1.

Constraints:
1 <= n <= 100000
0 <= number of edges <= 200000

Example 1:

Input:
n = 7
edges = [0->1, 2->1, 2->3, 5->1, 4->5, 6->4, 6->3]
source = 0, destination = 6

Output:
2
(use 0->1, reverse 2->1 to go 1->2, use 2->3, reverse 6->3 to go 3->6)

Example 2:

Input:
n = 3
edges = [0->1, 1->2]
source = 2, destination = 0

Output:
2
(both edges have to be reversed)
*/

/*
APPROACH:-

-> Change the problem into a shortest path problem. For every directed edge u -> v, add an edge u -> v with weight 0 (using it as it is costs nothing), and an edge v -> u with weight 1 (using it means we reverse the original edge).
-> The answer is the shortest distance from the source to the destination in this weighted graph.
-> All the weights are 0 or 1, so we can use 0-1 BFS, which is a BFS with a deque. When we relax an edge with weight 0 we push the neighbour at the front of the deque. When the weight is 1 we push it at the back.
-> Keep a dist array with a very large value at the start and dist[source] = 0. A neighbour is pushed only when its distance gets smaller.
-> If dist[destination] is still very large at the end, the destination cannot be reached, so return -1.
-> Let V be the number of nodes and E the number of edges. Each node and edge is handled a constant number of times, so the time is V + E.
-> The adjacency lists and the distance array take V + E space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minimumReversals(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 1});
    }

    const int INF = 1000000000;
    vector<int> dist(n, INF);
    deque<int> pending;

    dist[source] = 0;
    pending.push_back(source);

    while (!pending.empty())
    {
        int u = pending.front();
        pending.pop_front();

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;

                if (weight == 0)
                {
                    pending.push_front(v);
                }
                else
                {
                    pending.push_back(v);
                }
            }
        }
    }

    if (dist[destination] == INF)
    {
        return -1;
    }

    return dist[destination];
}

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int source = 0;
    int destination = 6;

    cout << minimumReversals(n, edges, source, destination) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V + E)
*/
