/*
QUESTION:-

Given an array nums, find the next greater element for every element. The next
greater element of x is the first element to the right of x that is strictly
greater than x. If no such element exists, the answer for x is -1.

Constraints:
1 <= nums.length <= 100000
-1000000000 <= nums[i] <= 1000000000

Example 1:

Input:
nums = [1,3,2,4]

Output:
[3,4,4,-1]

Example 2:

Input:
nums = [6,0,8,1,3]

Output:
[8,8,-1,3,-1]
*/

/*
APPROACH:-

-> Traverse the array from right to left and keep a stack that holds the candidates for the next greater element.
-> For the current element, pop from the stack every value that is less than or equal to it. Those values can never be the next greater element of this or any element to the left.
-> After popping, if the stack is not empty its top is the next greater element. If it is empty, the answer is -1.
-> Push the current element on the stack so it can serve the elements on its left.
-> The stack always stays in decreasing order from bottom to top.
-> Every element is pushed once and popped at most once, so the total work is linear.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = (int)nums.size();
    vector<int> answer(n, -1);
    stack<int> candidates;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!candidates.empty() && candidates.top() <= nums[i])
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
    vector<int> nums = {1, 3, 2, 4};

    vector<int> answer = nextGreaterElements(nums);

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
