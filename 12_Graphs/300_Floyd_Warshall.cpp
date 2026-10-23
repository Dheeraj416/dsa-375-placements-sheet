/*
QUESTION:-

You are given a directed weighted graph as an n x n matrix, where matrix[i][j]
is the weight of the edge from i to j, matrix[i][i] = 0, and matrix[i][j] = -1
means there is no edge from i to j. Change the matrix in place so that
matrix[i][j] becomes the shortest distance from i to j. If j cannot be reached
from i, keep -1.

Constraints:
1 <= n <= 100
1 <= weight <= 1000 for every existing edge

Example 1:

Input:
matrix = [[0,25],[-1,0]]

Output:
[[0,25],[-1,0]]

Example 2:

Input:
matrix = [[0,1,43],[1,0,6],[-1,-1,0]]

Output:
[[0,1,7],[1,0,6],[-1,-1,0]]
(0 -> 2 is cheaper through vertex 1: 1 + 6 = 7 instead of 43)
*/

/*
APPROACH:-

-> Floyd-Warshall finds the shortest distance between every pair of vertices (all pairs shortest path).
-> First replace every -1 (no edge) by a very large number so that it never looks like a short path.
-> The idea: for every vertex "via", check whether going from i to j through "via" is shorter than the best known path from i to j.
-> So run three loops: via, then i, then j. If matrix[i][via] and matrix[via][j] both exist, then matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]).
-> The via loop must be the outermost loop. After handling vertex "via", all shortest paths that use only the vertices up to "via" as middle points are correct.
-> Skip the update when either part of the path does not exist, so we never add the large number twice.
-> At the end, change the large numbers back to -1.
-> There are three nested loops over n vertices, so the time is n * n * n.
-> The matrix is changed in place and only a few variables are used, so there is no extra space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    const int INF = 1000000000;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = INF;
            }
        }
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][via] != INF && matrix[via][j] != INF)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
            {
                matrix[i][j] = -1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};

    floydWarshall(matrix);

    for (vector<int> &row : matrix)
    {
        for (int x : row)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(n * n * n)
SPACE COMPLEXITY = O(1)
*/
