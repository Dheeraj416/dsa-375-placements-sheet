/*
QUESTION:-

Given an array arr where arr[i] is the maximum number of steps you can jump
forward from index i, return the minimum number of jumps needed to reach the last
index, starting from index 0. If the last index cannot be reached, return -1.

Constraints:
1 <= arr.length <= 1000
0 <= arr[i] <= 1000

Example 1:

Input:
arr = [1,3,5,8,9,2,6,7,6,8,9]

Output:
3
(index 0 -> index 1 -> index 3 -> the last index)

Example 2:

Input:
arr = [1,4,3,2,6,7]

Output:
2
(index 0 -> index 1 -> the last index)
*/

/*
APPROACH:-

-> Let dp[i] be the minimum number of jumps needed to reach index i from index 0. dp[0] = 0, and the other values start with a very large number that means "not reachable yet".
-> For an index i, look at every earlier index j. If j is reachable (its dp value is not the large number) and j can jump far enough to reach i (j + arr[j] >= i), then i can be reached with dp[j] + 1 jumps.
-> Keep the smallest such value in dp[i].
-> At the end, if dp[n - 1] is still the large number, the last index cannot be reached, so return -1. Otherwise return dp[n - 1].
-> Let N be the size of the array. For every index we look at all earlier indexes, so the time is N * N.
-> The dp array has N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr)
{
    int n = arr.size();
    int INF = 1000000000;

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INF && j + arr[j] >= i)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[n - 1] == INF)
    {
        return -1;
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << minJumps(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
