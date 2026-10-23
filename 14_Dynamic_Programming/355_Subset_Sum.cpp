/*
QUESTION:-

Given an array of positive integers and a target number K, check whether there
is a subset of the array (any elements, in any positions) whose sum is exactly
K. Return true if such a subset exists, otherwise return false.

Constraints:
1 <= arr.length <= 200
1 <= arr[i] <= 1000
1 <= K <= 10000

Example 1:

Input:
arr = [1,2,7,3]
K = 6

Output:
true
(1 + 2 + 3 = 6)

Example 2:

Input:
arr = [2,3,5]
K = 4

Output:
false
(the possible sums are 2, 3, 5, 5, 7, 8 and 10, so 4 is not possible)
*/

/*
APPROACH:-

-> Use a boolean array can[s] that says whether some subset of the elements seen so far has the sum s.
-> Start with can[0] = true, because the empty subset has sum 0. Everything else is false.
-> Take the elements one by one. With an element x, a sum s becomes possible if s was already possible, or if s - x was possible (then we add x to that subset).
-> So for every s from K down to x, set can[s] = can[s] OR can[s - x].
-> We go from K down to x so that the same element is not used twice: when we update s, the smaller index s - x still has its old value from before this element.
-> The answer is can[K] after all elements are processed.
-> Let N be the number of elements. For every element we go through up to K sums, so the time is N * K.
-> The boolean array has K + 1 cells, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool subsetSumExists(vector<int> &arr, int target)
{
    vector<bool> can(target + 1, false);
    can[0] = true;

    for (int x : arr)
    {
        for (int sum = target; sum >= x; sum--)
        {
            if (can[sum - x])
            {
                can[sum] = true;
            }
        }
    }

    return can[target];
}

int main()
{
    vector<int> arr = {1, 2, 7, 3};
    int target = 6;

    bool answer = subsetSumExists(arr, target);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * K)
SPACE COMPLEXITY = O(K)
*/
