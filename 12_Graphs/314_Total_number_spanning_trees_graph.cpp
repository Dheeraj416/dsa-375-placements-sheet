/*
QUESTION:-

Given an undirected connected graph as an adjacency matrix, count the number of
different spanning trees of the graph. A spanning tree is a set of V - 1 edges
that connects all the V vertices without a cycle.

Constraints:
1 <= V <= 10
graph[i][j] is 0 or 1, graph[i][j] = graph[j][i], and graph[i][i] = 0

Example 1:

Input:
graph =
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

Output:
16

Example 2:

Input:
graph =
0 1 1
1 0 1
1 1 0

Output:
3
*/

/*
APPROACH:-

-> Use Kirchhoff's matrix tree theorem: the number of spanning trees of a graph is the determinant of any cofactor of its Laplacian matrix.
-> The Laplacian matrix L is built like this: L[i][i] = degree of the vertex i (the number of edges at i), and for i != j, L[i][j] = -1 if there is an edge between i and j, otherwise 0.
-> Remove the last row and the last column of L (a cofactor), which leaves a matrix of size (V - 1) x (V - 1).
-> Compute the determinant of this matrix by Gaussian elimination: for each column, choose the row with the largest absolute value as the pivot (swap rows, which changes the sign of the determinant), then subtract multiples of the pivot row from the rows below, and multiply the diagonal values at the end.
-> The answer is a whole number, so round the result to the nearest integer. If V is 1, there is exactly one spanning tree.
-> Let V be the number of vertices. Gaussian elimination takes V * V * V steps, so the time is V * V * V.
-> The matrix takes V * V space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countSpanningTrees(vector<vector<int>> &graph)
{
    int n = graph.size();

    if (n == 1)
    {
        return 1;
    }

    int m = n - 1;
    vector<vector<double>> laplacian(m, vector<double>(m, 0));

    for (int i = 0; i < m; i++)
    {
        int degree = 0;
        for (int j = 0; j < n; j++)
        {
            degree += graph[i][j];
        }

        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                laplacian[i][j] = degree;
            }
            else
            {
                laplacian[i][j] = -graph[i][j];
            }
        }
    }

    double determinant = 1;

    for (int col = 0; col < m; col++)
    {
        int pivot = col;
        for (int row = col + 1; row < m; row++)
        {
            if (fabs(laplacian[row][col]) > fabs(laplacian[pivot][col]))
            {
                pivot = row;
            }
        }

        if (fabs(laplacian[pivot][col]) < 1e-9)
        {
            return 0;
        }

        if (pivot != col)
        {
            swap(laplacian[pivot], laplacian[col]);
            determinant = -determinant;
        }

        determinant *= laplacian[col][col];

        for (int row = col + 1; row < m; row++)
        {
            double factor = laplacian[row][col] / laplacian[col][col];
            for (int j = col; j < m; j++)
            {
                laplacian[row][j] -= factor * laplacian[col][j];
            }
        }
    }

    return llround(determinant);
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};

    cout << countSpanningTrees(graph) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V * V * V)
SPACE COMPLEXITY = O(V * V)
*/
