/*
QUESTION:-

Given an array of distinct positive integers nums and a target integer, return
the number of possible sequences of numbers from nums that add up to target. A
number may be used any number of times, and different orders count as
different sequences.

Constraints:
1 <= nums.length <= 10
1 <= nums[i] <= 100 (all values are different)
1 <= target <= 40
The answer fits in a 64-bit signed integer.

Example 1:

Input:
nums = [1,2,3]
target = 4

Output:
7
(1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1)

Example 2:

Input:
nums = [9]
target = 3

Output:
0
*/

/*
APPROACH:-

-> Let ways[t] be the number of ordered sequences that add up to t. ways[0] = 1, because the empty sequence adds up to 0.
-> To build a sequence that adds up to t, look at its last number. It can be any number x from nums with x <= t, and before it comes a sequence that adds up to t - x.
-> So ways[t] is the sum of ways[t - x] over all numbers x in nums that are at most t.
-> Fill t from 1 up to target. The answer is ways[target].
-> Because the last number can be any of the numbers, the same numbers in a different order are counted as different sequences, which is what the question asks for.
-> Let N be the size of nums and T the target. For every value of t we look at all N numbers, so the time is N * T.
-> The table has T + 1 values, so the space is T.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long combinationSum4(vector<int> &nums, int target)
{
    vector<long long> ways(target + 1, 0);
    ways[0] = 1;

    for (int total = 1; total <= target; total++)
    {
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (nums[i] <= total)
            {
                ways[total] = ways[total] + ways[total - nums[i]];
            }
        }
    }

    return ways[target];
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int target = 4;

    cout << combinationSum4(nums, target) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * T)
SPACE COMPLEXITY = O(T)
*/
