/*
QUESTION:-

Given an array of integers, find the length of the longest subsequence such that
the absolute difference between every two adjacent elements of the subsequence
is exactly 1.

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 100000

Example 1:

Input:
arr = [10,9,4,5,4,8,6]

Output:
3
(for example 10, 9, 8 or 4, 5, 4)

Example 2:

Input:
arr = [1,2,3,2,3,7,2,1]

Output:
7
(1, 2, 3, 2, 3, 2, 1)
*/

/*
APPROACH:-

-> Let dp[i] be the length of the longest valid subsequence that ends at index i. Every element alone is a subsequence of length 1, so dp[i] starts at 1.
-> For index i, look at every earlier index j. If the absolute difference of arr[i] and arr[j] is exactly 1, then element i can be added after the subsequence that ends at j, giving dp[j] + 1.
-> Keep the largest such value in dp[i]. This is the same idea as the longest increasing subsequence, only the rule for joining two elements is different.
-> The answer is the largest value in the dp array.
-> Let N be the size of the array. For every index we look at all earlier indexes, so the time is N * N.
-> The dp array has N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    int answer = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
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
    vector<int> arr = {10, 9, 4, 5, 4, 8, 6};

    cout << longestSubsequence(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
