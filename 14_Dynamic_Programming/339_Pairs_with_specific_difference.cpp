/*
QUESTION:-

Given an array of integers and a number K, you can pair two elements of the
array if the difference between them is strictly less than K. Every element can
be used in at most one pair. Find the maximum possible sum of the elements of
the chosen pairs.

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 10000
1 <= K <= 10000

Example 1:

Input:
arr = [3,5,10,15,17,12,9], K = 4

Output:
62
(the best pairs are (17,15), (12,10) and (5,3); the element 9 stays alone)

Example 2:

Input:
arr = [5,15,10,300], K = 12

Output:
25
(pair (10,15); 5 and 300 stay alone)
*/

/*
APPROACH:-

-> Sort the array. If two elements can be paired with each other, it is always best to pair elements that are next to each other in the sorted order, because neighbours have the smallest difference.
-> Let dp[i] be the best sum using the first i + 1 sorted elements (indexes 0 to i). dp[0] = 0, because one element alone cannot form a pair.
-> For index i, first assume element i is not paired: dp[i] = dp[i - 1].
-> If arr[i] - arr[i - 1] < K, we can pair element i with element i - 1. Then the sum is arr[i] + arr[i - 1] plus the best sum of the elements before them, dp[i - 2] (use 0 when i is 1). Take the larger of the two choices.
-> The answer is dp[n - 1].
-> Let N be the size of the array. Sorting takes N * log(N) and the DP takes N, so the time is N * log(N).
-> The dp array has N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxPairSum(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];

        if (arr[i] - arr[i - 1] < k)
        {
            int before = 0;

            if (i >= 2)
            {
                before = dp[i - 2];
            }

            dp[i] = max(dp[i], before + arr[i] + arr[i - 1]);
        }
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr = {3, 5, 10, 15, 17, 12, 9};
    int k = 4;

    cout << maxPairSum(arr, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log(N))
SPACE COMPLEXITY = O(N)
*/
