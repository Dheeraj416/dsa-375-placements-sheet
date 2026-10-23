/*
QUESTION:-

Given a matrix of R rows and C columns, print its elements in zigzag (diagonal)
order: go through the anti-diagonals one by one starting from the top left
corner, and alternate the direction on every diagonal. The first diagonal is
just the first element, the second diagonal is traversed from top to bottom, the
third from bottom to top, and so on.

Constraints:
1 <= R, C <= 1000
-1000000 <= matrix[i][j] <= 1000000

Example 1:

Input:
matrix =
1 2 3
4 5 6
7 8 9

Output:
1 2 4 7 5 3 6 8 9

Example 2:

Input:
matrix =
1 2 3
4 5 6

Output:
1 2 4 5 3 6
*/

/*
APPROACH:-

-> All the cells on one anti-diagonal have the same value of row + column. This sum goes from 0 to R + C - 2, so there are R + C - 1 diagonals.
-> For a given sum, the cells are (row, sum - row). The smallest valid row is max(0, sum - C + 1) and the largest valid row is min(sum, R - 1).
-> If the sum is odd, walk the diagonal from the smallest row to the largest row (top to bottom). If the sum is even, walk it from the largest row to the smallest row (bottom to top).
-> This matches the pattern of the examples: the diagonal with sum 0 has one cell, the one with sum 1 goes down, the one with sum 2 goes up, and so on.
-> Let R and C be the number of rows and columns. Every cell is visited once, so the time is R * C.
-> The answer list holds all the cells (the output itself), and the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> zigzagTraversal(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> result;

    for (int sum = 0; sum <= rows + cols - 2; sum++)
    {
        int firstRow = max(0, sum - cols + 1);
        int lastRow = min(sum, rows - 1);

        if (sum % 2 == 0)
        {
            for (int row = lastRow; row >= firstRow; row--)
            {
                result.push_back(matrix[row][sum - row]);
            }
        }
        else
        {
            for (int row = firstRow; row <= lastRow; row++)
            {
                result.push_back(matrix[row][sum - row]);
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> answer = zigzagTraversal(matrix);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(1)
*/
