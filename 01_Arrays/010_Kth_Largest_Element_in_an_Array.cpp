/*
QUESTION:-

Given an integer array nums and an integer k, return the k-th largest element
in the array. It is the k-th largest in the sorted order, not the k-th distinct
element.

Constraints:
1 <= k <= nums.length <= 100000
-10000 <= nums[i] <= 10000

Example 1:

Input:
nums = [3,2,1,5,6,4], k = 2

Output:
5

Example 2:

Input:
nums = [3,2,3,1,2,4,5,5,6], k = 4

Output:
4
*/

/*
APPROACH:-

-> Keep a min heap that holds the k largest elements seen so far.
-> For every number, push it into the heap. If the heap now has more than k elements, remove the smallest one (the top of the min heap).
-> After removing, the heap contains only the k largest numbers of the part of the array that was processed.
-> When the whole array is processed, the top of the min heap is the smallest among the k largest elements, which is exactly the k-th largest element.
-> The heap never grows beyond k + 1 elements, so every operation costs log K.
-> This is better than sorting the whole array when k is much smaller than N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i <nums.size(); i++)
    {
        minHeap.push(nums[i]);

        if ((int)minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int answer = findKthLargest(nums, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(K)
*/
