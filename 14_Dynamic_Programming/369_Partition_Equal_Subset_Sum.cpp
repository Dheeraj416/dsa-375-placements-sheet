/*
QUESTION:-

Given an array of positive integers nums, return true if the array can be split
into two subsets whose sums are equal, otherwise return false.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100

Example 1:

Input:
nums = [1,5,11,5]

Output:
true
([1,5,5] and [11])

Example 2:

Input:
nums = [1,2,3,5]

Output:
false
(the total is 11, which is odd)
*/

/*
APPROACH:-

-> If the total sum of the array is odd, it cannot be split into two equal halves, so return false.
-> Otherwise each half must have the sum target = total / 2. So we only need to check whether some subset has the sum target. The other elements then also have the sum target.
-> Let reachable[s] be true if some subset of the numbers seen so far has the sum s. reachable[0] is true (the empty subset).
-> For each number x, go through the sums from target down to x. If reachable[s - x] is true, then reachable[s] becomes true (we add x to that subset). Going downwards makes sure that each number is used only once.
-> The answer is reachable[target].
-> Let N be the size of the array and S the target (half of the total sum). For each number we go through up to S sums, so the time is N * S.
-> The reachable array has S + 1 values, so the space is S.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &nums)
{
    int total = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        total = total + nums[i];
    }

    if (total % 2 == 1)
    {
        return false;
    }

    int target = total / 2;
    vector<bool> reachable(target + 1, false);
    reachable[0] = true;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        for (int s = target; s >= nums[i]; s--)
        {
            if (reachable[s - nums[i]])
            {
                reachable[s] = true;
            }
        }
    }

    return reachable[target];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    cout << (canPartition(nums) ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * S)
SPACE COMPLEXITY = O(S)
*/
