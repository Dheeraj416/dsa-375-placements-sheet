/*
QUESTION:-

Given an array of positive integers, choose some of its elements so that no two
chosen elements are next to each other in the array, and the sum of the chosen
elements is as large as possible. Return that maximum sum.

Constraints:
1 <= nums.length <= 100000
1 <= nums[i] <= 10000

Example 1:

Input:
nums = [2,1,4,9]

Output:
11
(choose 2 and 9)

Example 2:

Input:
nums = [1,2,3,1,3,5,8,1,9]

Output:
24
(choose 1, 3, 3, 8 and 9)
*/

/*
APPROACH:-

-> For every element we have two choices: take it or skip it. If we take it, we cannot take the previous element.
-> Let best(i) be the best sum using the elements up to index i. Then best(i) = max(nums[i] + best(i - 2), best(i - 1)).
-> The first part is "take nums[i]" (so we add the best answer that ends at least two places before). The second part is "skip nums[i]".
-> Start with best(0) = nums[0]. Go from left to right and fill the answers one by one (bottom-up DP).
-> best(i) uses only the two previous answers, so we keep just two variables instead of a whole array.
-> The answer is the last value. A single element array simply returns that element.
-> Let N be the size of the array. We visit every element once, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxNonAdjacentSum(vector<int> &nums)
{
    int previous = nums[0];
    int beforePrevious = 0;

    for (int i = 1; i < (int)nums.size(); i++)
    {
        int takeCurrent = nums[i] + beforePrevious;
        int skipCurrent = previous;
        int current = max(takeCurrent, skipCurrent);

        beforePrevious = previous;
        previous = current;
    }

    return previous;
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};

    int answer = maxNonAdjacentSum(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
