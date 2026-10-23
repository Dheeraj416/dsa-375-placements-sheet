/*
QUESTION:-

Given a binary matrix (every cell is 0 or 1), find the largest square sub-matrix
that contains only 1s, and return the length of its side.

Constraints:
1 <= rows, columns <= 100
matrix[i][j] is 0 or 1

Example 1:

Input:
matrix =
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0

Output:
3

Example 2:

Input:
matrix =
1 1
1 1

Output:
2
*/

/*
APPROACH:-

-> Let dp[r][c] be the side of the largest all-1 square whose bottom-right corner is the cell (r, c).
-> If the cell is 0, no square can end there, so dp[r][c] = 0.
-> If the cell is 1 and it is in the first row or the first column, the largest square is just the cell itself, so dp[r][c] = 1.
-> Otherwise, a square of side s ending at (r, c) needs squares of side s - 1 ending at the cell above, the cell on the left and the cell on the upper left. So dp[r][c] = 1 + min(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]).
-> Keep the largest value that appears in the table. That is the answer.
-> Let R and C be the number of rows and columns. Every cell is filled in constant time, so the time and the space are both R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int largestSquare(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int best = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (matrix[r][c] == 1)
            {
                if (r == 0 || c == 0)
                {
                    dp[r][c] = 1;
                }
                else
                {
                    dp[r][c] = 1 + min(dp[r - 1][c], min(dp[r][c - 1], dp[r - 1][c - 1]));
                }

                best = max(best, dp[r][c]);
            }
        }
    }

    return best;
}

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};

    cout << largestSquare(matrix) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
