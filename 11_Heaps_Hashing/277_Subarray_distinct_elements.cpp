/*
QUESTION:-

Given an array of integers, count the subarrays (contiguous blocks) in which all
the elements are distinct (no value appears twice). Subarrays at different
positions are counted separately, even if they contain the same values.

Constraints:
1 <= n <= 100000
1 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [1,2,1,3]

Output:
8
(the subarrays [1,2,1] and [1,2,1,3] are not counted; the other 8 are)

Example 2:

Input:
arr = [5,5,5]

Output:
3
(only the three single element subarrays)
*/

/*
APPROACH:-

-> Use a sliding window [left, i] that always contains distinct elements only. Keep a hash map lastIndex, which stores the last position where each value was seen.
-> Move the right end i from left to right. If arr[i] was seen before at a position that is inside the window (lastIndex[arr[i]] >= left), the window must start after that position, so set left = lastIndex[arr[i]] + 1.
-> Now the window [left, i] has distinct elements. Every subarray that ends at i and starts anywhere from left to i has distinct elements too. That makes i - left + 1 subarrays, so add this to the answer.
-> Update lastIndex[arr[i]] = i.
-> Use long long for the answer because it can be around N * N / 2.
-> Let N be the size of the array. Every element is handled once, so the time is N.
-> The map holds up to N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countDistinctSubarrays(vector<int> &arr)
{
    unordered_map<int, int> lastIndex;
    long long total = 0;
    int left = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (lastIndex.count(arr[i]) > 0 && lastIndex[arr[i]] >= left)
        {
            left = lastIndex[arr[i]] + 1;
        }

        total += i - left + 1;
        lastIndex[arr[i]] = i;
    }

    return total;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3};

    cout << countDistinctSubarrays(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
