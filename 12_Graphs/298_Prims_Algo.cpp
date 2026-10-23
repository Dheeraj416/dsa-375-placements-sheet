/*
QUESTION:-

Given a connected, weighted, undirected graph with V vertices numbered 0 to V-1,
find the weight of its Minimum Spanning Tree (MST). An MST is a set of V - 1
edges that connects all the vertices with the smallest possible total weight.
The graph is stored as an adjacency list where adj[u] holds pairs (v, w),
meaning there is an edge between u and v with weight w.

Constraints:
1 <= V <= 1000
V - 1 <= number of edges <= 10000
1 <= w <= 1000

Example 1:

Input:
V = 5
edges = [(0,1,2),(0,2,1),(1,2,1),(2,3,2),(3,4,1),(4,2,2)]

Output:
5
(the MST uses edges 0-2, 1-2, 2-3 and 3-4 with weights 1 + 1 + 2 + 1)

Example 2:

Input:
V = 3
edges = [(0,1,5),(1,2,3),(0,2,1)]

Output:
4
(the MST uses edges 0-2 and 1-2 with weights 1 + 3)
*/

/*
APPROACH:-

-> Prim's algorithm grows one tree from a starting vertex. At every step it adds the cheapest edge that connects the tree to a new vertex.
-> Use a min heap of pairs (edge weight, vertex). Start by pushing (0, 0), which means vertex 0 is reached with cost 0.
-> Repeat: take the cheapest pair from the heap. If its vertex is already in the tree, skip it.
-> Otherwise add the vertex to the tree and add the weight to the answer.
-> Then push all edges from this vertex that lead to vertices outside the tree.
-> Taking the cheapest edge that leaves the tree is always safe (the cut property), so the final tree has the minimum total weight.
-> Let E be the number of edges. Every edge is pushed at most twice and each heap operation costs log E, so the time is E * log E, which is the same as E * log V.
-> The inTree array takes V and the heap can hold up to E entries, so the space is V + E.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int primMst(int vertices, vector<vector<pair<int, int>>> &adj)
{
    vector<int> inTree(vertices, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    minHeap.push({0, 0});
    int totalWeight = 0;

    while (!minHeap.empty())
    {
        int weight = minHeap.top().first;
        int current = minHeap.top().second;
        minHeap.pop();

        if (inTree[current])
        {
            continue;
        }

        inTree[current] = 1;
        totalWeight += weight;

        for (pair<int, int> edge : adj[current])
        {
            if (!inTree[edge.first])
            {
                minHeap.push({edge.second, edge.first});
            }
        }
    }

    return totalWeight;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    vector<vector<pair<int, int>>> adj(vertices);

    for (vector<int> &edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    int answer = primMst(vertices, adj);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(E * log V)
SPACE COMPLEXITY = O(V + E)
*/
