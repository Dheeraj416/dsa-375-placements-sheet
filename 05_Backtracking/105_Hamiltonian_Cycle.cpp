/*
QUESTION:-

A Hamiltonian cycle in an undirected graph is a cycle that visits every vertex
exactly once and returns to the starting vertex. Given a graph as an adjacency
matrix (graph[i][j] = 1 if there is an edge between i and j), find a Hamiltonian
cycle that starts at vertex 0 and print it. If no such cycle exists, print "No
solution".

Constraints:
2 <= V <= 15
graph[i][j] is 0 or 1, and graph[i][j] == graph[j][i]

Example 1:

Input:
graph =
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

Output:
0 1 2 4 3 0

Example 2:

Input:
graph =
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0

Output:
No solution
*/

/*
APPROACH:-

-> Fix vertex 0 as the starting point and build the path one vertex at a time with backtracking. The array path[] holds the vertices chosen so far.
-> For the next position, try every vertex v from 1 to V - 1. The vertex is allowed only if there is an edge from the previous vertex of the path to v and v is not already in the path.
-> If v is allowed, put it into the path and call the function for the next position. If that call succeeds, we are done. Otherwise remove v and try the next vertex.
-> When the path has V vertices, we need one last check: there must be an edge from the last vertex back to the starting vertex 0 to close the cycle.
-> If no vertex works for some position, return false so that the previous position tries a different vertex.
-> Print the path followed by vertex 0 again. If the search from position 1 fails, there is no Hamiltonian cycle.
-> Let V be the number of vertices. In the worst case we try every ordering of the vertices, so the time is V!.
-> The path array and the recursion take V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int vertex, vector<vector<int>> &graph, vector<int> &path, int position)
{
    if (graph[path[position - 1]][vertex] == 0)
    {
        return false;
    }

    for (int i = 0; i < position; i++)
    {
        if (path[i] == vertex)
        {
            return false;
        }
    }

    return true;
}

bool buildCycle(vector<vector<int>> &graph, vector<int> &path, int position)
{
    int vertices = graph.size();

    if (position == vertices)
    {
        return graph[path[position - 1]][path[0]] == 1;
    }

    for (int vertex = 1; vertex < vertices; vertex++)
    {
        if (isSafe(vertex, graph, path, position))
        {
            path[position] = vertex;

            if (buildCycle(graph, path, position + 1))
            {
                return true;
            }

            path[position] = -1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}};

    int vertices = graph.size();
    vector<int> path(vertices, -1);
    path[0] = 0;

    if (buildCycle(graph, path, 1))
    {
        for (int vertex : path)
        {
            cout << vertex << " ";
        }
        cout << path[0] << "\n";
    }
    else
    {
        cout << "No solution\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(V!)
SPACE COMPLEXITY = O(V)
*/
