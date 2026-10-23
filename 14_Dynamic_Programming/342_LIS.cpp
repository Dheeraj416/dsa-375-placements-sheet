/*
QUESTION:-

Given an integer array nums, return the length of the longest strictly
increasing subsequence. A subsequence is obtained by deleting some elements
(possibly none) without changing the order of the remaining elements.

Constraints:
1 <= nums.length <= 2500
-10000 <= nums[i] <= 10000

Example 1:

Input:
nums = [10,9,2,5,3,7,101,18]

Output:
4
(one longest increasing subsequence is [2,3,7,101])

Example 2:

Input:
nums = [0,1,0,3,2,3]

Output:
4
(for example [0,1,2,3])
*/

/*
APPROACH:-

-> Keep an array tails where tails[i] is the smallest possible last value of an increasing subsequence of length i + 1 found so far.
-> The array tails is always sorted in increasing order, so we can use binary search on it.
-> For each number x, find the first position in tails whose value is greater than or equal to x (lower_bound).
-> If no such position exists, x is bigger than every tail, so it extends the longest subsequence: push x at the end.
-> Otherwise replace that position with x. This keeps the tail of that length as small as possible, which leaves more room for future numbers.
-> The answer is the final size of tails. Note that tails is not the real subsequence, only a helper that has the right length.
-> Let N be the size of the array. Each number needs one binary search, so the time is N * log N.
-> The tails array can grow up to N elements, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> tails;

    for (int x : nums)
    {
        int position = lower_bound(tails.begin(), tails.end(), x) - tails.begin();

        if (position == (int)tails.size())
        {
            tails.push_back(x);
        }
        else
        {
            tails[position] = x;
        }
    }

    return tails.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int answer = lengthOfLIS(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
