/*
QUESTION:-

Given a weighted undirected graph with V vertices numbered 0 to V-1 and a source
vertex S, find the shortest distance from S to every vertex. The graph is stored
as an adjacency list where adj[u] holds pairs (v, w), meaning there is an edge
between u and v with weight w. If a vertex cannot be reached from S, its
distance is -1.

Constraints:
1 <= V <= 1000
0 <= number of edges <= 10000
1 <= w <= 1000 (all weights are positive)

Example 1:

Input:
V = 3
adj = [[(1,1),(2,6)],[(0,1),(2,3)],[(1,3),(0,6)]]
S = 2

Output:
[4,3,0]
(shortest path from 2 to 0 is 2 -> 1 -> 0 with cost 3 + 1 = 4)

Example 2:

Input:
V = 2
adj = [[(1,9)],[(0,9)]]
S = 0

Output:
[0,9]
*/

/*
APPROACH:-

-> Dijkstra's algorithm always finalizes the closest unfinished vertex first. It works only when all weights are non-negative.
-> Keep a distance array filled with infinity, except distance[S] = 0.
-> Use a min heap of pairs (distance, vertex). Push (0, S).
-> Repeat: take the pair with the smallest distance. If its distance is larger than the best known distance of that vertex, it is an old entry, so skip it.
-> Otherwise try every edge (current, neighbor, weight). If distance[current] + weight is smaller than distance[neighbor], update it and push the new pair into the heap.
-> The first time a vertex comes out of the heap, its distance is the shortest possible, because every other path would have to go through a vertex that is at least as far.
-> At the end, vertices that were never reached still have infinity, so we change them to -1.
-> Let E be the number of edges. Each edge can add one entry to the heap and each heap operation costs log V, so the time is (V + E) * log V.
-> The distance array takes V and the heap can hold up to E entries, so the space is V + E.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int vertices, vector<vector<pair<int, int>>> &adj, int source)
{
    vector<int> distance(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    distance[source] = 0;
    minHeap.push({0, source});

    while (!minHeap.empty())
    {
        int currentDistance = minHeap.top().first;
        int current = minHeap.top().second;
        minHeap.pop();

        if (currentDistance > distance[current])
        {
            continue;
        }

        for (pair<int, int> edge : adj[current])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (currentDistance + weight < distance[neighbor])
            {
                distance[neighbor] = currentDistance + weight;
                minHeap.push({distance[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (distance[i] == INT_MAX)
        {
            distance[i] = -1;
        }
    }

    return distance;
}

int main()
{
    int vertices = 3;
    vector<vector<pair<int, int>>> adj = {
        {{1, 1}, {2, 6}},
        {{0, 1}, {2, 3}},
        {{1, 3}, {0, 6}}};
    int source = 2;

    vector<int> answer = dijkstra(vertices, adj, source);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O((V + E) * log V)
SPACE COMPLEXITY = O(V + E)
*/
