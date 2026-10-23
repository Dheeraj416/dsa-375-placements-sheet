/*
QUESTION:-

Given an array nums of distinct integers, return all possible subsets (the power
set). The answer must not contain duplicate subsets. The subsets can be returned
in any order.

Constraints:
1 <= nums.length <= 16
-10 <= nums[i] <= 10
All the numbers of nums are distinct.

Example 1:

Input:
nums = [1,2,3]

Output:
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input:
nums = [0]

Output:
[[],[0]]
*/

/*
APPROACH:-

-> An array with N elements has exactly 2^N subsets, because every element is either in a subset or not in it.
-> Every number from 0 to 2^N - 1 written in binary has N bits. Let bit i of the number mean "take nums[i]".
-> So we count mask from 0 to (1 << N) - 1, and for each mask we build one subset: for every index i, if bit i of the mask is 1, add nums[i] to the subset.
-> Different masks give different subsets, and all the possible choices are covered, so there are no duplicates and nothing is missing.
-> Example: for nums = [1,2,3], mask 5 is 101 in binary, so it takes nums[0] and nums[2], which gives [1,3].
-> Mask 0 gives the empty subset.
-> Let N be the size of the array. There are 2^N masks and building a subset checks N bits, so the time is N * 2^N.
-> The answer itself stores up to N * 2^N numbers, so the space is N * 2^N (the extra space apart from the answer is only N).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums)
{
    int n = nums.size();
    int totalSubsets = 1 << n;

    vector<vector<int>> allSubsets;

    for (int mask = 0; mask < totalSubsets; mask++)
    {
        vector<int> subset;

        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                subset.push_back(nums[i]);
            }
        }

        allSubsets.push_back(subset);
    }

    return allSubsets;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> answer = powerSet(nums);

    for (vector<int> &subset : answer)
    {
        cout << "[";
        for (int i = 0; i < (int)subset.size(); i++)
        {
            if (i > 0)
            {
                cout << ",";
            }
            cout << subset[i];
        }
        cout << "]\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * 2^N)
SPACE COMPLEXITY = O(N * 2^N)
*/
