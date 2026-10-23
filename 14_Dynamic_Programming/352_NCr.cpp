/*
QUESTION:-

Given two integers n and r, return nCr, the number of ways to choose r items
from n different items (the order does not matter). Use the rule of Pascal's
triangle instead of factorials.

Constraints:
0 <= r <= n <= 60
The answer fits in a 64-bit signed integer.

Example 1:

Input:
n = 5, r = 2

Output:
10

Example 2:

Input:
n = 6, r = 3

Output:
20
*/

/*
APPROACH:-

-> Let dp[i][j] be iCj, the number of ways to choose j items from i items.
-> Choosing 0 items, or choosing all i items, can be done in exactly one way. So dp[i][0] = 1 and dp[i][i] = 1.
-> For the other cells, look at one special item. Either it is chosen: then we choose j - 1 more items from the other i - 1 items, which is dp[i - 1][j - 1]. Or it is not chosen: then we choose all j items from the other i - 1 items, which is dp[i - 1][j].
-> So dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]. This is exactly how Pascal's triangle is built.
-> We only need columns up to r, so the table has (n + 1) * (r + 1) cells and each is filled in constant time.
-> The time and the space are both n * r.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(r + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][r];
}

int main()
{
    int n = 5;
    int r = 2;

    cout << nCr(n, r) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n * r)
SPACE COMPLEXITY = O(n * r)
*/
