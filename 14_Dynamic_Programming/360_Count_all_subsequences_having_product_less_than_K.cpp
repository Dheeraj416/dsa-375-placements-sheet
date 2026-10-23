/*
QUESTION:-

Given an array of positive integers and a number K, count the non-empty
subsequences of the array whose product of elements is strictly less than K.
Subsequences are counted by positions, so equal values at different positions
make different subsequences.

Constraints:
1 <= arr.length <= 40
1 <= arr[i] <= 1000
1 <= K <= 1000
The answer fits in a 64-bit signed integer.

Example 1:

Input:
arr = [1,2,3,4], K = 10

Output:
11
({1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {1,2,3}, {1,2,4})

Example 2:

Input:
arr = [4,8,7,2], K = 50

Output:
9
*/

/*
APPROACH:-

-> A product is less than K exactly when it is at most K - 1, so we count subsequences with product at most a limit j, for every limit j from 1 to K - 1.
-> Let dp[i][j] be the number of non-empty subsequences of the first i elements with product at most j.
-> For element i, the subsequences either do not use it, which gives dp[i - 1][j], or they use it.
-> If a subsequence uses element x = arr[i - 1] (possible only when x <= j), the other elements must have a product of at most j / x (integer division). So there are dp[i - 1][j / x] such non-empty subsequences, and one more subsequence, which is {x} alone.
-> So dp[i][j] = dp[i - 1][j] + (dp[i - 1][j / x] + 1 when x <= j). All the numbers are positive integers, so the integer division is exact for this comparison.
-> The answer is dp[n][K - 1].
-> Let N be the size of the array. The table has N * K cells, each filled in constant time, so the time and the space are both N * K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countSubsequences(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(k, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i][j] + dp[i - 1][j / arr[i - 1]] + 1;
            }
        }
    }

    return dp[n][k - 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 10;

    cout << countSubsequences(arr, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * K)
SPACE COMPLEXITY = O(N * K)
*/
