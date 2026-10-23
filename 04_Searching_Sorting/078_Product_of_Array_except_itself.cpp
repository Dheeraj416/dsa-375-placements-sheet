/*
QUESTION:-

Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i]. Do not use the
division operator.

Constraints:
2 <= nums.length <= 100000
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums fits in a 32-bit integer.

Example 1:

Input:
nums = [1,2,3,4]

Output:
[24,12,8,6]

Example 2:

Input:
nums = [-1,1,0,-3,3]

Output:
[0,0,9,0,0]
*/

/*
APPROACH:-

-> The product except nums[i] is (product of everything to the left of i) * (product of everything to the right of i).
-> First pass (left to right): answer[i] stores the product of all elements before i. For i = 0 there is nothing before it, so it is 1.
-> Second pass (right to left): keep a running variable rightProduct that holds the product of all elements after i. Multiply answer[i] by rightProduct, then include nums[i] into rightProduct.
-> Division is not needed, so zeros in the array are handled correctly.
-> Let N be the size of the array. We make two passes, so the time is N.
-> The answer array is the required output, and only one extra variable is used, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n, 1);

    for (int i = 1; i < n; i++)
    {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int rightProduct = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * rightProduct;
        rightProduct = rightProduct * nums[i];
    }

    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> answer = productExceptSelf(nums);

    for (int x : answer)
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
