/*
QUESTION:-

Given an undirected graph with N vertices and a number M, determine whether the
graph can be colored with at most M colors so that no two adjacent vertices
have the same color. Return true if it is possible, otherwise return false.

Constraints:
1 <= N <= 20
1 <= M <= N

Example 1:

Input:
N = 4, M = 3, edges = (0,1), (1,2), (2,3), (3,0), (0,2)

Output:
true

Example 2:

Input:
N = 4, M = 2, edges = (0,1), (1,2), (2,3), (3,0), (0,2)

Output:
false
Explanation: Vertices 0, 1 and 2 form a triangle, which needs at least 3 colors.
*/

/*
APPROACH:-

-> Store the graph as an adjacency matrix, where graph[a][b] is 1 if there is an edge between a and b.
-> Color the vertices one by one starting from vertex 0, using recursion.
-> For the current vertex try every color from 1 to M.
-> A color is safe if none of the neighbours of the vertex already has that color.
-> If a color is safe, assign it and recurse for the next vertex. If the recursion succeeds, return true.
-> If it fails, reset the vertex color to 0 (backtrack) and try the next color.
-> If no color works for a vertex, return false. If all the vertices get colored, return true.
-> In the worst case every vertex tries M colors and every check scans N neighbours.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafeToColor(int node, vector<vector<int>> &graph, vector<int> &colors, int color)
{
    for (int neighbour = 0; neighbour < (int)graph.size(); neighbour++)
    {
        if (graph[node][neighbour] == 1 && colors[neighbour] == color)
        {
            return false;
        }
    }

    return true;
}

bool colorGraph(int node, vector<vector<int>> &graph, vector<int> &colors, int totalColors)
{
    if (node == (int)graph.size())
    {
        return true;
    }

    for (int color = 1; color <= totalColors; color++)
    {
        if (isSafeToColor(node, graph, colors, color))
        {
            colors[node] = color;

            if (colorGraph(node + 1, graph, colors, totalColors))
            {
                return true;
            }

            colors[node] = 0;
        }
    }

    return false;
}

bool canColorGraph(vector<vector<int>> &graph, int totalColors)
{
    vector<int> colors(graph.size(), 0);

    return colorGraph(0, graph, colors, totalColors);
}

int main()
{
    int n = 4;
    int totalColors = 3;
    int edges[5][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < 5; i++)
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    bool answer = canColorGraph(graph, totalColors);

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
TIME COMPLEXITY = O(M^N * N)
SPACE COMPLEXITY = O(N)
*/
