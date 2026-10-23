/*
QUESTION:-

Given an array of distinct integers, replace every element with the least
element on its right side that is greater than it. If there is no such element,
replace it with -1. Return the new array.

Constraints:
1 <= n <= 100000
1 <= arr[i] <= 1000000, all values are different

Example 1:

Input:
arr = [8,58,71,18,31,32,63,92,43,3,91,93,25,80,28]

Output:
[18,63,80,25,32,43,80,93,80,25,93,-1,28,-1,-1]

Example 2:

Input:
arr = [4,2,1,3]

Output:
[-1,3,3,-1]
*/

/*
APPROACH:-

-> Go through the array from right to left, and keep all the elements already seen (the elements on the right side of the current position) in an ordered set. An ordered set is a balanced BST, so it keeps the values sorted.
-> For the current element x, ask the set for the first value that is strictly greater than x (upper_bound). That is the least greater element on its right side.
-> If the set has no such value, the answer for this position is -1. Otherwise it is the value found.
-> Then insert x into the set, so it is available for the elements on its left.
-> Let N be the size of the array. Each upper_bound and insert costs log N, so the time is N * log N.
-> The set holds up to N values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    set<int> seen;

    for (int i = n - 1; i >= 0; i--)
    {
        set<int>::iterator it = seen.upper_bound(arr[i]);

        if (it == seen.end())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = *it;
        }

        seen.insert(arr[i]);
    }

    return result;
}

int main()
{
    vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};

    vector<int> answer = replaceElements(arr);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
