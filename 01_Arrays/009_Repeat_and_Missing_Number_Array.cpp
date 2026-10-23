/*
QUESTION:-

You are given an array nums of size n containing numbers from 1 to n. Exactly
one number appears twice and exactly one number from 1 to n is missing. Find
the repeating number and the missing number.

Constraints:
2 <= n <= 100000
1 <= nums[i] <= n

Example 1:

Input:
nums = [3,1,2,5,3]

Output:
Repeating = 3, Missing = 4

Example 2:

Input:
nums = [4,3,6,2,1,1]

Output:
Repeating = 1, Missing = 5
*/

/*
APPROACH:-

-> Let X be the repeating number and Y be the missing number.
-> Compare the actual sum with the expected sum 1 + 2 + ... + n. The difference is X - Y.
-> Compare the actual sum of squares with the expected sum of squares. The difference is X^2 - Y^2.
-> Since X^2 - Y^2 = (X - Y) * (X + Y), divide the square difference by the sum difference to get X + Y.
-> Now X = ((X - Y) + (X + Y)) / 2 and Y = (X + Y) - X.
-> Use long long because the sums of squares can be large.
-> The array is never modified and only a few variables are used.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findRepeatAndMissing(vector<int> &nums)
{
    long long n = (long long)nums.size();
    long long expectedSum = n * (n + 1) / 2;
    long long expectedSquareSum = n * (n + 1) * (2 * n + 1) / 6;
    long long actualSum = 0;
    long long actualSquareSum = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        actualSum += nums[i];
        actualSquareSum += (long long)nums[i] * nums[i];
    }

    long long sumDifference = actualSum - expectedSum;
    long long squareDifference = actualSquareSum - expectedSquareSum;
    long long sumOfBoth = squareDifference / sumDifference;
    long long repeating = (sumDifference + sumOfBoth) / 2;
    long long missing = sumOfBoth - repeating;

    return {(int)repeating, (int)missing};
}

int main()
{
    vector<int> nums = {3, 1, 2, 5, 3};

    vector<int> answer = findRepeatAndMissing(nums);

    cout << "Repeating = " << answer[0] << ", Missing = " << answer[1] << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
