/*
QUESTION:-

You are given an array nums and an integer k. A window of size k slides from
the very left of the array to the very right, moving one position at a time.
Return the maximum element of every window.

Constraints:
1 <= k <= nums.length <= 100000
-10000 <= nums[i] <= 10000

Example 1:

Input:
nums = [1,3,-1,-3,5,3,6,7], k = 3

Output:
[3,3,5,5,6,7]

Example 2:

Input:
nums = [1], k = 1

Output:
[1]
*/

/*
APPROACH:-

-> Use a deque (double ended queue) that stores indices of the array. The values at these indices are always in decreasing order from front to back.
-> For every new index i, first remove the front index if it has moved out of the window (front <= i - k).
-> Then remove indices from the back while the value at the back is less than or equal to nums[i]. Those smaller values can never be the maximum of any later window.
-> Push i at the back of the deque.
-> Once the first full window is formed (i >= k - 1), the front of the deque is the index of the maximum of the current window. Add it to the answer.
-> Each index enters and leaves the deque at most once, so the time is linear.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> indices;
    vector<int> answer;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (!indices.empty() && indices.front() <= i - k)
        {
            indices.pop_front();
        }

        while (!indices.empty() && nums[indices.back()] <= nums[i])
        {
            indices.pop_back();
        }

        indices.push_back(i);

        if (i >= k - 1)
        {
            answer.push_back(nums[indices.front()]);
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> answer = maxSlidingWindow(nums, k);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(K)
*/
