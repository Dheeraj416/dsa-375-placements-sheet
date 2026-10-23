/*
QUESTION:-

The permutation coefficient P(n, k) is the number of ways to arrange k items
chosen from n different items, where the order matters. It is equal to
n! / (n - k)!. Given n and k, return P(n, k).

Constraints:
1 <= k <= n <= 20

Example 1:

Input:
n = 10, k = 2

Output:
90
(10 * 9)

Example 2:

Input:
n = 10, k = 3

Output:
720
(10 * 9 * 8)
*/

/*
APPROACH:-

-> Let dp[i][j] be P(i, j): the number of ordered arrangements of j items from i items.
-> If j = 0, there is exactly one arrangement (the empty one), so dp[i][0] = 1.
-> Look at the last item among the i items. Either it is not used: then we arrange j items from the other i - 1 items, which is dp[i - 1][j].
-> Or it is used: it can be placed in any of the j positions, and the other j - 1 positions are filled by items chosen from the i - 1 other items, which is j * dp[i - 1][j - 1].
-> So dp[i][j] = dp[i - 1][j] + j * dp[i - 1][j - 1].
-> We fill the table for i up to n and j up to k. A cell with j larger than i stays 0, because we cannot choose more items than we have.
-> The table has (n + 1) * (k + 1) cells and each is filled in constant time, so the time and the space are both n * k.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long permutationCoefficient(int n, int k)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + j * dp[i - 1][j - 1];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int n = 10;
    int k = 2;

    cout << permutationCoefficient(n, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n * k)
SPACE COMPLEXITY = O(n * k)
*/
