/*
QUESTION:-

Given an integer array nums and an integer k, return the number of non-empty
contiguous subarrays whose sum is divisible by k.

Constraints:
1 <= nums.length <= 30000
-10000 <= nums[i] <= 10000
2 <= k <= 10000

Example 1:

Input:
nums = [4,5,0,-2,-3,1]
k = 5

Output:
7
([4,5,0,-2,-3,1], [5], [5,0], [5,0,-2,-3], [0], [0,-2,-3], [-2,-3])

Example 2:

Input:
nums = [5]
k = 9

Output:
0
*/

/*
APPROACH:-

-> Let prefix[i] be the sum of the first i elements. The sum of a subarray from j to i - 1 is prefix[i] - prefix[j].
-> That sum is divisible by k exactly when prefix[i] and prefix[j] leave the same remainder when divided by k.
-> So keep a count array of how many prefixes had each remainder 0 to k - 1. The empty prefix (sum 0) counts as remainder 0, so start with count[0] = 1.
-> For each element, update the running sum and find its remainder. In C++ the remainder of a negative number is negative, so fix it with ((sum % k) + k) % k.
-> Every earlier prefix with the same remainder forms one valid subarray with the current position, so add count[remainder] to the answer, then increase count[remainder] by 1.
-> Let N be the size of the array and K the divisor. One pass gives a time of N.
-> The count array has K cells, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    vector<int> count(k, 0);
    count[0] = 1;

    int sum = 0;
    int answer = 0;

    for (int x : nums)
    {
        sum = sum + x;
        int remainder = ((sum % k) + k) % k;

        answer = answer + count[remainder];
        count[remainder]++;
    }

    return answer;
}

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int answer = subarraysDivByK(nums, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(K)
*/
