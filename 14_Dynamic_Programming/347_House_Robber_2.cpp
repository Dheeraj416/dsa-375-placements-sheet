/*
QUESTION:-

A robber wants to rob houses placed in a circle. Every house has some money. Two
houses that are next to each other (the first and the last house are also
neighbors) cannot both be robbed, because the alarm would ring. Given the money
in each house, return the maximum amount that can be robbed.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000

Example 1:

Input:
nums = [2,3,2]

Output:
3
(we cannot rob house 1 and house 3 together because they are neighbors in the circle)

Example 2:

Input:
nums = [1,2,3,1]

Output:
4
(rob house 1 and house 3)
*/

/*
APPROACH:-

-> Because the houses form a circle, the first and the last house cannot both be robbed.
-> So there are only two cases: the first house is not robbed (use houses 1 to N-1), or the last house is not robbed (use houses 0 to N-2).
-> Each case is the normal "maximum sum of non-adjacent elements" problem on a straight line of houses.
-> For a line, keep two variables: the best total up to the previous house and the best total up to the house before that. For each house the best is max(skip it, rob it + the best from two houses back).
-> The answer is the larger result of the two cases.
-> Edge case: with only one house there is nothing to split, so return that house's money.
-> Let N be the number of houses. We run the line solution twice, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int robLine(vector<int> &nums, int start, int end)
{
    int previous = 0;
    int beforePrevious = 0;

    for (int i = start; i <= end; i++)
    {
        int current = max(previous, nums[i] + beforePrevious);

        beforePrevious = previous;
        previous = current;
    }

    return previous;
}

int robCircle(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    int withoutLast = robLine(nums, 0, n - 2);
    int withoutFirst = robLine(nums, 1, n - 1);

    return max(withoutLast, withoutFirst);
}

int main()
{
    vector<int> nums = {2, 3, 2};

    int answer = robCircle(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
