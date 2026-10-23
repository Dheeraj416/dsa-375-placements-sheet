/*
QUESTION:-

Given an array nums, find the next smaller element for every element. The next
smaller element of x is the first element to the right of x that is strictly
smaller than x. If no such element exists, the answer for x is -1.

Constraints:
1 <= nums.length <= 100000
-1000000000 <= nums[i] <= 1000000000

Example 1:

Input:
nums = [4,8,5,2,25]

Output:
[2,5,2,-1,-1]

Example 2:

Input:
nums = [13,7,6,12]

Output:
[7,6,-1,-1]
*/

/*
APPROACH:-

-> Traverse the array from right to left and keep a stack of candidates for the next smaller element.
-> For the current element, pop every value from the stack that is greater than or equal to it. Such values cannot be the next smaller element for it or for any element on its left.
-> If the stack is not empty after popping, its top is the next smaller element. Otherwise the answer is -1.
-> Push the current element on the stack for the elements on its left.
-> The stack stays in increasing order from bottom to top.
-> Every element is pushed once and popped at most once, so the time is linear.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> &nums)
{
    int n = (int)nums.size();
    vector<int> answer(n, -1);
    stack<int> candidates;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!candidates.empty() && candidates.top() >= nums[i])
        {
            candidates.pop();
        }

        if (!candidates.empty())
        {
            answer[i] = candidates.top();
        }

        candidates.push(nums[i]);
    }

    return answer;
}

int main()
{
    vector<int> nums = {4, 8, 5, 2, 25};

    vector<int> answer = nextSmallerElements(nums);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
