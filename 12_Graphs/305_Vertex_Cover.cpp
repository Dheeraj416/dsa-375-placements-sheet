/*
QUESTION:-

A vertex cover of an undirected graph is a set of vertices such that every edge
of the graph has at least one of its two end points in the set. Given a graph
with V vertices (numbered from 0) and a list of edges, find the size of the
smallest vertex cover.

Constraints:
1 <= V <= 20
0 <= number of edges <= 100

Example 1:

Input:
V = 7
edges = 0-1, 0-2, 1-3, 3-4, 4-5, 5-6

Output:
3
(for example the vertices 0, 3 and 5)

Example 2:

Input:
V = 3
edges = 0-1, 1-2, 0-2

Output:
2
*/

/*
APPROACH:-

-> V is at most 20, so we can try every subset of vertices. There are 2^V subsets, and each one can be written as a bitmask: bit i of the mask is 1 when the vertex i is in the subset.
-> For a mask, check all the edges (a, b). The edge is covered if the bit a or the bit b of the mask is set. If some edge is not covered, the subset is not a vertex cover.
-> For the masks that cover all the edges, count their set bits (the subset size) and keep the smallest one.
-> The empty set is checked too, so a graph without edges gives the answer 0.
-> Let V be the number of vertices and E the number of edges. There are 2^V masks and each is checked with E edges, so the time is 2^V * E.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minimumVertexCover(int v, vector<vector<int>> &edges)
{
    int best = v;

    for (int mask = 0; mask < (1 << v); mask++)
    {
        bool covered = true;

        for (int i = 0; i < (int)edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            if ((mask & (1 << a)) == 0 && (mask & (1 << b)) == 0)
            {
                covered = false;
                break;
            }
        }

        if (covered)
        {
            int size = __builtin_popcount(mask);
            best = min(best, size);
        }
    }

    return best;
}

int main()
{
    int v = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {4, 5}, {5, 6}};

    cout << minimumVertexCover(v, edges) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(2^V * E)
SPACE COMPLEXITY = O(1)
*/
