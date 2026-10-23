/*
QUESTION:-

Given an integer array nums, find a contiguous non-empty subarray that has the
largest product, and return that product. The answer is guaranteed to fit in a
32-bit integer.

Constraints:
1 <= nums.length <= 20000
-10 <= nums[i] <= 10

Example 1:

Input:
nums = [2,3,-2,4]

Output:
6
(the subarray [2,3] has the largest product)

Example 2:

Input:
nums = [-2,0,-1]

Output:
0
(the result cannot be 2, because [-2,-1] is not a contiguous subarray)
*/

/*
APPROACH:-

-> Multiplying by a negative number turns the biggest product into the smallest one and the smallest into the biggest. So we must track both.
-> Keep maxEnding and minEnding: the largest and the smallest product of a subarray that ends at the current index.
-> For a new number x: if x is negative, swap maxEnding and minEnding first, because multiplying by x reverses their roles.
-> Then maxEnding = max(x, maxEnding * x) and minEnding = min(x, minEnding * x). The choice "x alone" starts a fresh subarray, which also handles zeros.
-> After each step, update the best answer with maxEnding.
-> A zero makes both values 0 and the next number starts a fresh subarray, so zeros are handled without any special case.
-> Let N be the size of the array. We make one pass, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxProductSubarray(vector<int> &nums)
{
    int maxEnding = nums[0];
    int minEnding = nums[0];
    int best = nums[0];

    for (int i = 1; i < (int)nums.size(); i++)
    {
        int value = nums[i];

        if (value < 0)
        {
            swap(maxEnding, minEnding);
        }

        maxEnding = max(value, maxEnding * value);
        minEnding = min(value, minEnding * value);

        best = max(best, maxEnding);
    }

    return best;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    int answer = maxProductSubarray(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
