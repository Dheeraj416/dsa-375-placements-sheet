/*
QUESTION:-

You are given N pairs of numbers. In every pair, the first number is smaller than
the second number. A pair (c, d) can follow a pair (a, b) if b < c. A chain of
pairs is a list of pairs in which every pair follows the one before it. Find the
length of the longest chain that can be made from the given pairs. You can pick
the pairs in any order.

Constraints:
1 <= N <= 1000
-1000 <= a < b <= 1000

Example 1:

Input:
pairs = [[5,24],[39,60],[15,28],[27,40],[50,90]]

Output:
3
([5,24] -> [27,40] -> [50,90])

Example 2:

Input:
pairs = [[1,2],[2,3],[3,4]]

Output:
2
([1,2] -> [3,4]; the pair [2,3] cannot be used with [1,2] because 2 < 2 is false)
*/

/*
APPROACH:-

-> Sort the pairs by their first number. Now a pair can only follow pairs that come before it in the sorted order, so the problem looks like the longest increasing subsequence.
-> Let dp[i] be the length of the longest chain that ends with the pair i. A chain with only this pair has length 1, so dp[i] starts at 1.
-> For every earlier pair j, if pair i can follow it (the second number of j is smaller than the first number of i), then dp[i] = max(dp[i], dp[j] + 1).
-> The answer is the largest value in the dp array.
-> Let N be the number of pairs. Sorting takes N * log(N), and the two loops take N * N, so the time is N * N.
-> The dp array has N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxChainLength(vector<vector<int>> pairs)
{
    sort(pairs.begin(), pairs.end());

    int n = pairs.size();
    vector<int> dp(n, 1);
    int answer = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pairs[j][1] < pairs[i][0])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};

    cout << maxChainLength(pairs) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
