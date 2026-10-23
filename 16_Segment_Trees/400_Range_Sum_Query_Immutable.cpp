/*
QUESTION:-

Given an integer array nums, answer many queries of the form sumRange(left, right):
return the sum of the elements of nums between the indexes left and right
(inclusive). The array never changes. Implement a class NumArray with this
operation.

Constraints:
1 <= nums.length <= 10000
-100000 <= nums[i] <= 100000
0 <= left <= right < nums.length
At most 10000 queries are made.

Example 1:

Input:
nums = [-2,0,3,-5,2,-1]
queries: sumRange(0,2), sumRange(2,5), sumRange(0,5)

Output:
[1,-1,-3]

Example 2:

Input:
nums = [5]
queries: sumRange(0,0)

Output:
[5]
*/

/*
APPROACH:-

-> Because the array never changes, we do not need a segment tree here. A prefix sum array is enough (a segment tree is needed in the next problems, where the array changes).
-> Let prefix[i] be the sum of the first i elements, so prefix[0] = 0 and prefix[i + 1] = prefix[i] + nums[i]. Build it once in the constructor.
-> The sum of nums[left..right] is the sum of the first right + 1 elements minus the sum of the first left elements: prefix[right + 1] - prefix[left].
-> Example: nums = [-2,0,3,-5,2,-1]. prefix = [0,-2,-2,1,-4,-2,-3]. sumRange(2,5) = prefix[6] - prefix[2] = -3 - (-2) = -1.
-> Let N be the size of the array. Building the prefix array takes N, and every query takes constant time.
-> The prefix array has N + 1 values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
    vector<int> prefix;

public:
    NumArray(vector<int> &nums)
    {
        prefix.assign(nums.size() + 1, 0);

        for (int i = 0; i < (int)nums.size(); i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];
    }
};

int main()
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << "\n";
    cout << numArray.sumRange(2, 5) << "\n";
    cout << numArray.sumRange(0, 5) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
