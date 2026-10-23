/*
QUESTION:-

Given an array of integers and a target sum, check whether there are two
different elements in the array (at two different positions) whose sum is equal
to the target. Return true if such a pair exists, otherwise return false.

Constraints:
2 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000
-1000000000 <= target <= 1000000000

Example 1:

Input:
arr = [1,4,45,6,10,8]
target = 16

Output:
true
(6 + 10 = 16)

Example 2:

Input:
arr = [1,2,3,9]
target = 8

Output:
false
*/

/*
APPROACH:-

-> For every number x, the partner we need is target - x. A hash set can tell us in constant time whether that partner was already seen.
-> Go through the array from left to right. For the current number x, check if target - x is in the set. If yes, the pair exists, so return true.
-> Otherwise insert x into the set and continue.
-> We insert x only after checking, so a number is never paired with itself unless the same value really appears twice.
-> If we reach the end, no pair has the required sum, so return false.
-> Let N be the size of the array. Every number is processed once with constant time set operations, so the time is N.
-> The set can hold up to N numbers, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(vector<int> &arr, int target)
{
    unordered_set<long long> seen;

    for (int x : arr)
    {
        long long partner = (long long)target - x;

        if (seen.find(partner) != seen.end())
        {
            return true;
        }

        seen.insert(x);
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;

    bool answer = hasPairWithSum(arr, target);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
