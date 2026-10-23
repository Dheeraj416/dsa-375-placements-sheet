/*
QUESTION:-

Given an array arr of integers, find the length of the longest subarray whose
sum is 0. If there is no such subarray, return 0.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [15,-2,2,-8,1,7,10,23]

Output:
5
Explanation: The subarray [-2,2,-8,1,7] has sum 0.

Example 2:

Input:
arr = [1,2,3]

Output:
0
*/

/*
APPROACH:-

-> Keep a running prefix sum while walking through the array.
-> If the prefix sum becomes 0, the subarray from index 0 to i has sum 0, so its length is i + 1.
-> If the same prefix sum was seen earlier at index p, the elements from p + 1 to i add up to 0.
-> Store the first index of every prefix sum in a hash map, because the earliest index gives the longest subarray.
-> Do not overwrite an existing entry in the map.
-> Use long long for the prefix sum to avoid overflow.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestZeroSumSubarray(vector<int> &arr)
{
    unordered_map<long long, int> firstIndex;
    long long prefixSum = 0;
    int longest = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        prefixSum += arr[i];

        if (prefixSum == 0)
        {
            longest = i + 1;
        }
        else if (firstIndex.find(prefixSum) != firstIndex.end())
        {
            longest = max(longest, i - firstIndex[prefixSum]);
        }
        else
        {
            firstIndex[prefixSum] = i;
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    int answer = longestZeroSumSubarray(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
