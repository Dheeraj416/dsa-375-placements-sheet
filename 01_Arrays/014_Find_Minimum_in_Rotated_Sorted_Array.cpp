/*
QUESTION:-

A sorted array of distinct integers was rotated between 1 and n times. For
example [0,1,2,4,5,6,7] rotated 4 times becomes [4,5,6,7,0,1,2]. Given the
rotated array, return its minimum element. Your solution must run in O(log N)
time.

Constraints:
1 <= nums.length <= 5000
-5000 <= nums[i] <= 5000
All the integers are unique.

Example 1:

Input:
nums = [3,4,5,1,2]

Output:
1

Example 2:

Input:
nums = [4,5,6,7,0,1,2]

Output:
0
*/

/*
APPROACH:-

-> Use binary search with two pointers low and high.
-> Compare the middle element with the last element of the current range. If nums[mid] is bigger than nums[high], the drop (where the minimum is) happens on the right side, so the minimum is in mid + 1 to high.
-> Otherwise nums[mid] is smaller than nums[high], so the right part is sorted and the minimum is mid itself or on its left, so we move high to mid.
-> Continue until low and high meet. That index holds the minimum.
-> Edge case: if the array is not rotated (or has one element), nums[mid] is never bigger than nums[high], so high keeps moving left and we end at index 0, which is the minimum.
-> Let N be the size of the array. The search range halves every step, so the time is log N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findMinimum(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return nums[low];
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};

    int answer = findMinimum(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log N)
SPACE COMPLEXITY = O(1)
*/
