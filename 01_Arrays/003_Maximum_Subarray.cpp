/*
QUESTION:-

Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return that sum.

Constraints:
1 <= nums.length <= 100000
-10000 <= nums[i] <= 10000

Example 1:

Input:
nums = [-2,1,-3,4,-1,2,1,-5,4]

Output:
6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input:
nums = [5,4,-1,7,8]

Output:
23
*/

/*
APPROACH:-

-> Walk through the array once and keep currentSum, the best sum of a subarray ending at the current index.
-> At every element choose the better of two options: start fresh from this element, or extend the previous subarray.
-> So currentSum = max(nums[i], currentSum + nums[i]).
-> Keep a second variable bestSum that stores the maximum currentSum seen so far.
-> Both variables start with nums[0], so an array of only negative numbers is also handled correctly.
-> A negative running sum can never help a later subarray, which is why restarting is safe.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &nums)
{
    int currentSum = nums[0];
    int bestSum = nums[0];

    for (int i = 1; i < (int)nums.size(); i++)
    {
        currentSum = max(nums[i], currentSum + nums[i]);
        bestSum = max(bestSum, currentSum);
    }

    return bestSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int answer = maxSubArraySum(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
