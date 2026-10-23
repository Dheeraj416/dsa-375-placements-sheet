/*
QUESTION:-

Given an array of integers and a number k, choose k elements of the array such
that the difference between the maximum and the minimum of the chosen elements
is as small as possible. Return this minimum difference.

Constraints:
1 <= k <= n <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [10,100,300,200,1000,20,30]
k = 3

Output:
20
(choose 10, 20, 30)

Example 2:

Input:
arr = [1,4,7,9,2,10]
k = 3

Output:
3
(choose 1, 2, 4 or 9, 10, 7)
*/

/*
APPROACH:-

-> The chosen k elements should be close to each other in value. If we sort the array, the best k elements are always k consecutive elements of the sorted array.
-> Why: if we pick some k elements, then all the elements between their smallest and their largest value could be used as well, and a block of k consecutive sorted elements inside that range has a smaller or equal difference.
-> So sort the array and look at every block of k consecutive elements. The difference of a block starting at index i is arr[i + k - 1] - arr[i].
-> The answer is the smallest difference over all the blocks. Use long long for the difference, because the values can be as far apart as 2 * 10^9.
-> Let N be the size of the array. Sorting costs N * log N and the scan costs N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minimumDifference(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    long long best = LLONG_MAX;

    for (int i = 0; i + k - 1 < (int)arr.size(); i++)
    {
        long long difference = (long long)arr[i + k - 1] - arr[i];
        best = min(best, difference);
    }

    return best;
}

int main()
{
    vector<int> arr = {10, 100, 300, 200, 1000, 20, 30};
    int k = 3;

    cout << minimumDifference(arr, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
