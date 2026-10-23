/*
QUESTION:-

Given a connected, weighted, undirected graph with V vertices numbered 0 to V-1
and a list of edges where every edge is [u, v, weight], find the weight of its
Minimum Spanning Tree (MST). An MST is a set of V - 1 edges that connects all
the vertices with the smallest possible total weight.

Constraints:
1 <= V <= 1000
V - 1 <= number of edges <= 10000
1 <= weight <= 1000

Example 1:

Input:
V = 5
edges = [[0,1,2],[0,2,1],[1,2,1],[2,3,2],[3,4,1],[4,2,2]]

Output:
5
(the MST uses edges 0-2, 1-2, 3-4 and 2-3 with weights 1 + 1 + 1 + 2)

Example 2:

Input:
V = 3
edges = [[0,1,5],[1,2,3],[0,2,1]]

Output:
4
*/

/*
APPROACH:-

-> Kruskal's algorithm looks at the edges from the cheapest to the most expensive and takes an edge only if it does not create a cycle.
-> Copy every edge as (weight, u, v) and sort the list, so the cheapest edges come first.
-> To check for a cycle quickly we use Disjoint Set Union (DSU). Every vertex starts in its own set (its own parent).
-> For an edge (u, v): find the root of u and the root of v. If the roots are the same, u and v are already connected, so this edge would make a cycle and we skip it.
-> If the roots are different, join the two sets (the smaller set goes under the bigger one) and add the edge weight to the answer.
-> The find function uses path compression (it points every visited vertex directly to the root), which keeps the sets very flat.
-> Taking the cheapest edge that connects two different components is always safe, so the total weight is the minimum.
-> Let E be the number of edges. Sorting costs E * log E and the DSU operations are almost constant, so the time is E * log E.
-> The sorted edge copy takes E and the DSU arrays take V, so the space is V + E.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }

    parent[node] = findParent(parent[node], parent);
    return parent[node];
}

bool joinSets(int first, int second, vector<int> &parent, vector<int> &setSize)
{
    int rootFirst = findParent(first, parent);
    int rootSecond = findParent(second, parent);

    if (rootFirst == rootSecond)
    {
        return false;
    }

    if (setSize[rootFirst] < setSize[rootSecond])
    {
        swap(rootFirst, rootSecond);
    }

    parent[rootSecond] = rootFirst;
    setSize[rootFirst] += setSize[rootSecond];
    return true;
}

int kruskalMst(int vertices, vector<vector<int>> &edges)
{
    vector<vector<int>> sortedEdges;

    for (vector<int> &edge : edges)
    {
        sortedEdges.push_back({edge[2], edge[0], edge[1]});
    }

    sort(sortedEdges.begin(), sortedEdges.end());

    vector<int> parent(vertices);
    vector<int> setSize(vertices, 1);

    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    int totalWeight = 0;

    for (vector<int> &edge : sortedEdges)
    {
        if (joinSets(edge[1], edge[2], parent, setSize))
        {
            totalWeight += edge[0];
        }
    }

    return totalWeight;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    int answer = kruskalMst(vertices, edges);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(E * log E)
SPACE COMPLEXITY = O(V + E)
*/
