/*
QUESTION:-

Given an integer array nums, return all the unique triplets
[nums[i], nums[j], nums[k]] such that i, j and k are different indices and
nums[i] + nums[j] + nums[k] == 0. The answer must not contain duplicate
triplets.

Constraints:
3 <= nums.length <= 3000
-100000 <= nums[i] <= 100000

Example 1:

Input:
nums = [-1,0,1,2,-1,-4]

Output:
[[-1,-1,2],[-1,0,1]]

Example 2:

Input:
nums = [0,0,0]

Output:
[[0,0,0]]
*/

/*
APPROACH:-

-> Sort the array so that duplicates are next to each other and two pointers can be used.
-> Fix the first number at index i. Skip it if it is equal to the previous number.
-> Use two pointers left = i + 1 and right = n - 1 to find two numbers whose sum is -nums[i].
-> If the total is less than 0, move left forward. If it is greater than 0, move right backward.
-> If the total is 0, store the triplet, move both pointers and skip repeated values on both sides.
-> Skipping duplicates for all three positions guarantees that every triplet is unique.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
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

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int total = nums[i] + nums[left] + nums[right];

            if (total == 0)
            {
                answer.push_back({nums[i], nums[left], nums[right]});
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
            else if (total < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> answer = threeSum(nums);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << "[" << answer[i][0] << "," << answer[i][1] << "," << answer[i][2] << "] ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N^2)
SPACE COMPLEXITY = O(1)
*/
