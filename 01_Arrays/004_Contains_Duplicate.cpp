/*
QUESTION:-

Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.

Constraints:
1 <= nums.length <= 100000
-1000000000 <= nums[i] <= 1000000000

Example 1:

Input:
nums = [1,2,3,1]

Output:
true

Example 2:

Input:
nums = [1,2,3,4]

Output:
false
*/

/*
APPROACH:-

-> Use a hash set to remember the numbers we have already seen.
-> Go through the array. For each number, check if it is already in the set. If yes, we found a duplicate, so return true.
-> If it is not in the set, insert it and continue.
-> If we reach the end without finding a repeated number, all the elements are distinct, so return false.
-> Sorting the array and comparing neighbors also works, but the hash set avoids the sorting cost.
-> Let N be the size of the array. Each lookup and insert takes constant time on average, so the time is N.
-> The set can hold all N numbers, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> seen;

    for (int x : nums)
    {
        if (seen.find(x) != seen.end())
        {
            return true;
        }
        seen.insert(x);
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    bool answer = containsDuplicate(nums);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
