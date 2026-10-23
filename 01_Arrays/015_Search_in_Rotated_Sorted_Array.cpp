/*
QUESTION:-

An integer array sorted in ascending order with distinct values was rotated at
an unknown pivot. For example [0,1,2,4,5,6,7] may become [4,5,6,7,0,1,2].
Given the rotated array nums and an integer target, return the index of target
in nums, or -1 if it is not present. The solution must run in O(log N) time.

Constraints:
1 <= nums.length <= 5000
-10000 <= nums[i], target <= 10000
All the values of nums are distinct.

Example 1:

Input:
nums = [4,5,6,7,0,1,2], target = 0

Output:
4

Example 2:

Input:
nums = [4,5,6,7,0,1,2], target = 3

Output:
-1
*/

/*
APPROACH:-

-> Use binary search. In a rotated sorted array, at least one half around mid is always sorted.
-> If nums[mid] equals the target, return mid.
-> If nums[low] <= nums[mid], the left half is sorted. If the target lies between nums[low] and nums[mid], search the left half, otherwise search the right half.
-> Otherwise the right half is sorted. If the target lies between nums[mid] and nums[high], search the right half, otherwise search the left half.
-> Checking which half is sorted lets us throw away half of the array in every step.
-> If the loop ends, the target is not in the array, so return -1.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int searchRotated(vector<int> &nums, int target)
{
    int low = 0;
    int high = (int)nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int answer = searchRotated(nums, target);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log N)
SPACE COMPLEXITY = O(1)
*/
