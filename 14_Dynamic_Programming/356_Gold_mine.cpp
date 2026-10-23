/*
QUESTION:-

A gold mine is given as an R x C grid, where mine[r][c] is the amount of gold in
that cell. A miner can start from any cell of the first column. From a cell
he can move to the right cell, to the right-up cell, or to the right-down cell
(always one column to the right). He collects the gold of every cell he visits.
Return the maximum amount of gold he can collect.

Constraints:
1 <= R, C <= 100
0 <= mine[r][c] <= 100

Example 1:

Input:
mine =
1 3 3
2 1 4
0 6 4

Output:
12
(start at 2, go right-down to 6, then right-up to 4: 2 + 6 + 4)

Example 2:

Input:
mine =
1 3 1 5
2 2 4 1
5 0 2 3
0 6 1 2

Output:
16
*/

/*
APPROACH:-

-> Let dp[r][c] be the maximum gold that can be collected when the miner stands in cell (r, c) and goes on to the right until the last column.
-> In the last column the miner cannot move any more, so dp[r][c] is just mine[r][c].
-> In the other columns, the miner takes the gold of the cell and then chooses the best of the (up to) three cells in the next column: right-up, right and right-down. Cells outside the grid are ignored.
-> So dp[r][c] = mine[r][c] + max(dp[r - 1][c + 1], dp[r][c + 1], dp[r + 1][c + 1]).
-> Fill the table column by column from the last column to the first column, so the next column is always ready.
-> The answer is the largest value in the first column, because the miner may start in any row.
-> The table has R * C cells and each is filled in constant time, so the time and the space are both R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxGold(vector<vector<int>> &mine)
{
    int rows = mine.size();
    int cols = mine[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int c = cols - 1; c >= 0; c--)
    {
        for (int r = 0; r < rows; r++)
        {
            int bestNext = 0;

            if (c + 1 < cols)
            {
                bestNext = dp[r][c + 1];

                if (r > 0)
                {
                    bestNext = max(bestNext, dp[r - 1][c + 1]);
                }

                if (r + 1 < rows)
                {
                    bestNext = max(bestNext, dp[r + 1][c + 1]);
                }
            }

            dp[r][c] = mine[r][c] + bestNext;
        }
    }

    int answer = 0;

    for (int r = 0; r < rows; r++)
    {
        answer = max(answer, dp[r][0]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> mine = {{1, 3, 3}, {2, 1, 4}, {0, 6, 4}};

    cout << maxGold(mine) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
