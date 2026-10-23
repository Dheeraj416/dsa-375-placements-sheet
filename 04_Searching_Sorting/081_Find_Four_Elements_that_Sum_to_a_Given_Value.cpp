/*
QUESTION:-

Given an array nums of n integers and an integer target, return all the unique
quadruplets [nums[a], nums[b], nums[c], nums[d]] such that a, b, c and d are
different indices and nums[a] + nums[b] + nums[c] + nums[d] == target.

Constraints:
1 <= nums.length <= 200
-1000000000 <= nums[i], target <= 1000000000

Example 1:

Input:
nums = [1,0,-1,0,-2,2], target = 0

Output:
[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input:
nums = [2,2,2,2,2], target = 8

Output:
[[2,2,2,2]]
*/

/*
APPROACH:-

-> Sort the array first. Sorting makes it easy to skip duplicates and to use two pointers.
-> Fix the first number with index i and the second number with index j using two loops.
-> For the remaining two numbers, use two pointers: left = j + 1 and right = n - 1.
-> If the sum is smaller than the target, move left forward. If it is larger, move right backward.
-> If the sum equals the target, store the quadruplet and move both pointers, skipping equal values.
-> Also skip duplicate values for i and j so the same quadruplet is not added twice.
-> Use long long for the sum, because four large numbers can overflow int.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> answer;
    int n = (int)nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {
                    answer.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> answer = fourSum(nums, target);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << "[" << answer[i][0] << "," << answer[i][1] << "," << answer[i][2] << "," << answer[i][3] << "] ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N^3)
SPACE COMPLEXITY = O(1)
*/
