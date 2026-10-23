/*
QUESTION:-

A permutation of an array is one of the ways to arrange its elements. The next
permutation is the next lexicographically greater arrangement. If no greater
arrangement exists, the array must be rearranged into the lowest possible
order (sorted in ascending order). The change must be done in place.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100

Example 1:

Input:
nums = [1,2,3]

Output:
[1,3,2]

Example 2:

Input:
nums = [3,2,1]

Output:
[1,2,3]
*/

/*
APPROACH:-

-> Scan from the right and find the first index pivot where nums[pivot] < nums[pivot + 1].
-> If no such index exists, the array is the largest permutation, so just reverse the whole array.
-> Otherwise scan from the right again and find the first element greater than nums[pivot].
-> Swap these two elements.
-> Reverse the part of the array after the pivot so that it becomes the smallest possible order.
-> The suffix after the pivot was in descending order, so reversing it gives ascending order.
-> This changes the array by the smallest possible amount, which is exactly the next permutation.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = (int)nums.size();
    int pivot = n - 2;

    while (pivot >= 0 && nums[pivot] >= nums[pivot + 1])
    {
        pivot--;
    }

    if (pivot >= 0)
    {
        int swapIndex = n - 1;

        while (nums[swapIndex] <= nums[pivot])
        {
            swapIndex--;
        }

        swap(nums[pivot], nums[swapIndex]);
    }

    reverse(nums.begin() + pivot + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
