/*
QUESTION:-

Given an array of positive integers and a number k, check whether the array can
be divided into k non-empty subsets (every element in exactly one subset) such
that all the subsets have the same sum. Return true if it is possible,
otherwise return false.

Constraints:
1 <= k <= nums.length <= 16
1 <= nums[i] <= 10000

Example 1:

Input:
nums = [4,3,2,3,5,2,1]
k = 4

Output:
true
(the subsets {5}, {1,4}, {2,3} and {2,3} all have the sum 5)

Example 2:

Input:
nums = [1,2,3,4]
k = 3

Output:
false
(the total 10 cannot be divided into 3 equal sums)
*/

/*
APPROACH:-

-> If the total sum is not divisible by k, the answer is false. Otherwise every subset must have the sum target = total / k.
-> Think of k buckets. We place the numbers one by one into the buckets with backtracking, and a bucket may never get a sum larger than target.
-> Sort the numbers in decreasing order first. Big numbers are the most constrained, so placing them first makes the wrong paths fail early. If the biggest number is larger than target, return false.
-> For the number at position index, try every bucket b where bucketSum[b] + number <= target. Add the number to the bucket and recurse for the next index. If the recursion returns true, return true. Otherwise remove the number (backtrack).
-> Optimization: if an earlier bucket has exactly the same current sum as bucket b, trying b gives the same result, so skip it.
-> When all the numbers are placed without exceeding target, and the total is k * target, every bucket must be exactly full, so the answer is true.
-> Let N be the number of elements. Each number can go to up to K buckets, so the time is K^N in the worst case.
-> The bucket array and the recursion take K + N space, which we write as N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool placeNumbers(int index, vector<int> &nums, vector<int> &bucketSum, int target)
{
    if (index == (int)nums.size())
    {
        return true;
    }

    for (int bucket = 0; bucket < (int)bucketSum.size(); bucket++)
    {
        if (bucketSum[bucket] + nums[index] > target)
        {
            continue;
        }

        bool sameAsEarlier = false;

        for (int earlier = 0; earlier < bucket; earlier++)
        {
            if (bucketSum[earlier] == bucketSum[bucket])
            {
                sameAsEarlier = true;
                break;
            }
        }

        if (sameAsEarlier)
        {
            continue;
        }

        bucketSum[bucket] = bucketSum[bucket] + nums[index];

        if (placeNumbers(index + 1, nums, bucketSum, target))
        {
            return true;
        }

        bucketSum[bucket] = bucketSum[bucket] - nums[index];
    }

    return false;
}

bool canPartitionKSubsets(vector<int> nums, int k)
{
    int total = 0;

    for (int x : nums)
    {
        total = total + x;
    }

    if (total % k != 0)
    {
        return false;
    }

    int target = total / k;

    sort(nums.begin(), nums.end(), greater<int>());

    if (nums[0] > target)
    {
        return false;
    }

    vector<int> bucketSum(k, 0);

    return placeNumbers(0, nums, bucketSum, target);
}

int main()
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    bool answer = canPartitionKSubsets(nums, k);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(K^N)
SPACE COMPLEXITY = O(N)
*/
