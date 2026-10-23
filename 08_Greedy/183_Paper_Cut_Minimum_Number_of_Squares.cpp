/*
QUESTION:-

A rectangular paper of size a x b is given. Cut it into squares (of any sizes)
so that the number of squares is minimum. Return the minimum number of squares.

Constraints:
1 <= a, b <= 13

Example 1:

Input:
a = 13, b = 11

Output:
6
(the best tiling needs 6 squares, while cutting the largest square each time needs 8)

Example 2:

Input:
a = 5, b = 6

Output:
5
(two squares of side 3 and three squares of side 2)
*/

/*
APPROACH:-

-> The simple greedy idea is to repeatedly cut the biggest possible square. It is not always correct: for 13 x 11 it gives 8 squares, but the real answer is 6. So we use dynamic programming with a small special case.
-> Let dp[i][j] be the minimum number of squares for an i x j paper.
-> If i == j, the paper is already a square, so dp[i][j] = 1.
-> Otherwise try to cut the paper with one straight cut into two smaller papers. A horizontal cut after k rows gives dp[k][j] + dp[i - k][j], and a vertical cut after k columns gives dp[i][k] + dp[i][j - k]. Take the minimum over all cuts. (An upper bound is i * j squares of size 1.)
-> A straight cut across the whole paper cannot produce the best tiling of 13 x 11. That rectangle (and its rotation 11 x 13) is the only one with a side up to 13 which needs a special value, so we set dp[11][13] = dp[13][11] = 6.
-> Let A and B be the sides. There are A * B cells in the table and each one tries up to A + B cuts, so the time is A * B * (A + B).
-> The table has A * B cells, so the space is A * B.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minSquares(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if ((i == 11 && j == 13) || (i == 13 && j == 11))
            {
                dp[i][j] = 6;
            }
            else
            {
                int best = i * j;

                for (int k = 1; k < i; k++)
                {
                    best = min(best, dp[k][j] + dp[i - k][j]);
                }

                for (int k = 1; k < j; k++)
                {
                    best = min(best, dp[i][k] + dp[i][j - k]);
                }

                dp[i][j] = best;
            }
        }
    }

    return dp[a][b];
}

int main()
{
    int a = 13;
    int b = 11;

    cout << minSquares(a, b) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(A * B * (A + B))
SPACE COMPLEXITY = O(A * B)
*/
