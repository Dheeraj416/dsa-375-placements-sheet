/*
QUESTION:-

You are given an array nums. You start at index 0, and nums[i] is the maximum
jump length from index i (you can jump any length from 1 to nums[i]). Return
true if you can reach the last index, otherwise return false.

Constraints:
1 <= nums.length <= 100000
0 <= nums[i] <= 100000

Example 1:

Input:
nums = [2,3,1,1,4]

Output:
true
(jump 1 step to index 1, then 3 steps to the last index)

Example 2:

Input:
nums = [3,2,1,0,4]

Output:
false
(every path ends at index 3, where the jump length is 0)
*/

/*
APPROACH:-

-> Walk through the array from left to right and keep farthest, the largest index that can be reached so far. At the start, only index 0 is reachable, so farthest = 0.
-> At index i, if i is larger than farthest, then index i cannot be reached at all, and neither can the last index. Return false.
-> Otherwise index i is reachable, and from it we can reach up to i + nums[i]. Update farthest if this is bigger.
-> If we get through the whole array without getting stuck, the last index is reachable, so return true.
-> This is the dynamic programming idea "an index is reachable if some earlier reachable index can jump to it", kept in a single number because the reachable indexes always form one block from 0 to farthest.
-> Let N be the size of the array. We make one pass, so the time is N.
-> Only one variable is used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int farthest = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (i > farthest)
        {
            return false;
        }

        farthest = max(farthest, i + nums[i]);
    }

    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << (canJump(nums) ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
