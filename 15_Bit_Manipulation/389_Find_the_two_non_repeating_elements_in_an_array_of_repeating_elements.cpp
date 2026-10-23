/*
QUESTION:-

You are given an array of integers in which exactly two numbers appear once and
all the other numbers appear exactly twice. Find the two numbers that appear
once and return them in increasing order.

Constraints:
2 <= nums.length <= 100000
1 <= nums[i] <= 5000000
Exactly two numbers appear once, every other number appears twice.

Example 1:

Input:
nums = [1,2,3,2,1,4]

Output:
[3,4]

Example 2:

Input:
nums = [2,1,3,2]

Output:
[1,3]
*/

/*
APPROACH:-

-> XOR has two useful properties: a ^ a = 0 and a ^ 0 = a. So the XOR of the whole array cancels all the numbers that appear twice and leaves x ^ y, where x and y are the two numbers we want.
-> Because x and y are different, x ^ y is not 0, so it has at least one set bit. At that bit position, x and y have different values (one has 0 and the other has 1).
-> Find the position of any set bit in x ^ y (we take the lowest one).
-> Split all the numbers into two groups: the numbers that have this bit set and the numbers that do not.
-> x and y fall into different groups. Every other number appears twice and both copies fall into the same group, so they cancel out in the XOR.
-> So the XOR of the first group is one answer and the XOR of the second group is the other answer.
-> Return the two numbers in increasing order.
-> Let N be the size of the array. We make two passes, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoNonRepeatingNumbers(vector<int> &nums)
{
    int xorOfAll = 0;

    for (int x : nums)
    {
        xorOfAll = xorOfAll ^ x;
    }

    int bitPosition = 0;

    while (((xorOfAll >> bitPosition) & 1) == 0)
    {
        bitPosition++;
    }

    int groupWithBit = 0;
    int groupWithoutBit = 0;

    for (int x : nums)
    {
        if (((x >> bitPosition) & 1) == 1)
        {
            groupWithBit = groupWithBit ^ x;
        }
        else
        {
            groupWithoutBit = groupWithoutBit ^ x;
        }
    }

    return {min(groupWithBit, groupWithoutBit), max(groupWithBit, groupWithoutBit)};
}

int main()
{
    vector<int> nums = {1, 2, 3, 2, 1, 4};

    vector<int> answer = twoNonRepeatingNumbers(nums);

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
