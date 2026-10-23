/*
QUESTION:-

Given an array of positive integers, check whether the array can be split into
two subsets that have the same sum. Return true if it is possible, otherwise
return false.

Constraints:
1 <= nums.length <= 20
1 <= nums[i] <= 100

Example 1:

Input:
nums = [1,5,11,5]

Output:
true
([1,5,5] and [11] both have the sum 11)

Example 2:

Input:
nums = [1,2,3,5]

Output:
false
*/

/*
APPROACH:-

-> If the total sum is odd, it can never be split into two equal halves, so return false.
-> Otherwise we need to find a subset with the sum total / 2. The rest of the elements then also add up to total / 2.
-> Use backtracking: for each element there are two choices, put it in the subset or leave it out. The function canReach(index, remaining) asks: can the elements from index onwards make the sum remaining?
-> If remaining is 0, we found the subset, so return true. If remaining is negative or there are no elements left, return false.
-> Try "take nums[index]" (remaining decreases) and "skip nums[index]". If either choice returns true, the answer is true.
-> This is a backtracking solution that tries all the subsets, so the time is 2^N. (The dynamic programming version of this problem is solved in the DP section.)
-> The recursion goes N levels deep, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canReach(int index, int remaining, vector<int> &nums)
{
    if (remaining == 0)
    {
        return true;
    }

    if (remaining < 0 || index == (int)nums.size())
    {
        return false;
    }

    if (canReach(index + 1, remaining - nums[index], nums))
    {
        return true;
    }

    return canReach(index + 1, remaining, nums);
}

bool canPartition(vector<int> &nums)
{
    int total = 0;

    for (int x : nums)
    {
        total = total + x;
    }

    if (total % 2 != 0)
    {
        return false;
    }

    return canReach(0, total / 2, nums);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    bool answer = canPartition(nums);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(2^N)
SPACE COMPLEXITY = O(N)
*/
