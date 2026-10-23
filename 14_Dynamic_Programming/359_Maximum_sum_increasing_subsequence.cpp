/*
QUESTION:-

Given an array of positive integers, find the maximum sum of an increasing
subsequence. A subsequence is increasing if every element is strictly greater
than the element before it. The elements of a subsequence are taken in the same
order as in the array, but they need not be next to each other.

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 100000

Example 1:

Input:
arr = [1,101,2,3,100,4,5]

Output:
106
(1 + 2 + 3 + 100)

Example 2:

Input:
arr = [10,5,4,3]

Output:
10
(no two elements are in increasing order, so the best is the single element 10)
*/

/*
APPROACH:-

-> Let dp[i] be the maximum sum of an increasing subsequence that ends at index i. A subsequence with only arr[i] has the sum arr[i], so dp[i] starts as arr[i].
-> Look at every earlier index j. If arr[j] < arr[i], element i can be added after the best subsequence that ends at j, giving dp[j] + arr[i].
-> Keep the largest such value in dp[i]. This is the longest increasing subsequence idea, but instead of adding 1 we add the value of the element.
-> The answer is the largest value in the dp array, because the best subsequence can end at any index.
-> Let N be the size of the array. For every index we look at all earlier indexes, so the time is N * N.
-> The dp array has N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumIncreasingSubsequence(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main()
{
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};

    cout << maxSumIncreasingSubsequence(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
