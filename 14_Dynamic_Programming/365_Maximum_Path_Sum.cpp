/*
QUESTION:-

Given a matrix of positive integers with R rows and C columns, you start from any
cell of the first row. From a cell (r, c) you can move to (r + 1, c),
(r + 1, c - 1) or (r + 1, c + 1), as long as the new cell is inside the matrix.
Return the largest possible sum of the cells on a path that goes from the first
row to the last row.

Constraints:
1 <= R, C <= 100
1 <= matrix[r][c] <= 1000

Example 1:

Input:
matrix =
3 1 4
2 9 2
6 5 7

Output:
20
(4 -> 9 -> 7)

Example 2:

Input:
matrix =
348 391
618 193

Output:
1009
(391 -> 618)
*/

/*
APPROACH:-

-> Let dp[r][c] be the largest sum of a path that starts in the first row and ends in the cell (r, c).
-> In the first row, a path is just the cell itself, so dp[0][c] = matrix[0][c].
-> A path reaches (r, c) from the cell above, the cell above-left or the cell above-right. So dp[r][c] = matrix[r][c] + the largest of those dp values (cells outside the matrix are ignored).
-> Fill the table row by row from the top.
-> The path can end in any cell of the last row, so the answer is the largest value in the last row.
-> Let R and C be the number of rows and columns. Each cell is filled with at most 3 comparisons, so the time and the space are both R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp = matrix;

    for (int r = 1; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int best = dp[r - 1][c];

            if (c > 0)
            {
                best = max(best, dp[r - 1][c - 1]);
            }

            if (c + 1 < cols)
            {
                best = max(best, dp[r - 1][c + 1]);
            }

            dp[r][c] = matrix[r][c] + best;
        }
    }

    int answer = 0;

    for (int c = 0; c < cols; c++)
    {
        answer = max(answer, dp[rows - 1][c]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> matrix = {{3, 1, 4}, {2, 9, 2}, {6, 5, 7}};

    cout << maxPathSum(matrix) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
