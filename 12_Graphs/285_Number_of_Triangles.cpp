/*
QUESTION:-

Given an undirected graph as an adjacency matrix, count the number of
triangles in it. A triangle is a set of three vertices such that every two of
them are connected by an edge.

Constraints:
3 <= V <= 100
graph[i][j] is 0 or 1, graph[i][j] = graph[j][i], and graph[i][i] = 0

Example 1:

Input:
graph =
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

Output:
4

Example 2:

Input:
graph =
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

Output:
0
*/

/*
APPROACH:-

-> A triangle is a group of three different vertices i, j and k with the three edges i-j, j-k and i-k.
-> To count every triangle exactly once, take the vertices in increasing order i < j < k.
-> Use three loops. For every i, choose j > i, and for every j, choose k > j. If graph[i][j], graph[j][k] and graph[i][k] are all 1, increase the count.
-> Let V be the number of vertices. There are about V * V * V / 6 triples to check, so the time is V * V * V.
-> Only a counter is used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countTriangles(vector<vector<int>> &graph)
{
    int n = graph.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                continue;
            }

            for (int k = j + 1; k < n; k++)
            {
                if (graph[j][k] == 1 && graph[i][k] == 1)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};

    cout << countTriangles(graph) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V * V * V)
SPACE COMPLEXITY = O(1)
*/
