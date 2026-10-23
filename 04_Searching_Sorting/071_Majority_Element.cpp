/*
QUESTION:-

Given an array nums of size n, return the majority element. The majority
element is the element that appears more than floor(n / 2) times. You may
assume that the majority element always exists in the array.

Constraints:
1 <= n <= 50000
-1000000000 <= nums[i] <= 1000000000

Example 1:

Input:
nums = [2,2,1,1,1,2,2]

Output:
2

Example 2:

Input:
nums = [3,2,3]

Output:
3
*/

/*
APPROACH:-

-> Use the Boyer-Moore Voting Algorithm.
-> Keep one candidate and a counter.
-> If the counter is 0, make the current element the new candidate.
-> If the current element equals the candidate, increase the counter, otherwise decrease it.
-> Every time we decrease the counter, a majority element is cancelled by a different element.
-> The majority element appears more than half the time, so it can never be cancelled out completely.
-> Whatever candidate survives at the end is the answer. No hash map is needed.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }

        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int answer = majorityElement(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
