/*
QUESTION:-

Given an array of distinct integers, check whether the array can be sorted in
increasing order by reversing exactly one contiguous subarray (an array that is
already sorted also counts as true). Return true if it is possible, otherwise
return false.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000
All the values are distinct.

Example 1:

Input:
arr = [1,2,5,4,3]

Output:
true
(reverse the subarray [5,4,3] to get [1,2,3,4,5])

Example 2:

Input:
arr = [1,5,3,4,2]

Output:
false
*/

/*
APPROACH:-

-> Make a sorted copy of the array. The elements that are already in the right place do not need to move, so the part to reverse must start at the first position where the array differs from the sorted copy and end at the last such position.
-> Find first = the first index where arr[i] != sorted[i], and last = the last such index. If there is no such index, the array is already sorted, so return true.
-> Reverse the subarray from first to last in the original array.
-> If the array now equals the sorted copy, one reversal is enough, so return true. Otherwise no single reversal can sort it, so return false.
-> Let N be the size of the array. Sorting costs N * log N and the other steps cost N, so the time is N * log N.
-> The sorted copy takes N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canSortByOneReversal(vector<int> arr)
{
    int n = arr.size();

    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    int first = 0;

    while (first < n && arr[first] == sortedArr[first])
    {
        first++;
    }

    if (first == n)
    {
        return true;
    }

    int last = n - 1;

    while (arr[last] == sortedArr[last])
    {
        last--;
    }

    reverse(arr.begin() + first, arr.begin() + last + 1);

    return arr == sortedArr;
}

int main()
{
    vector<int> arr = {1, 2, 5, 4, 3};

    bool answer = canSortByOneReversal(arr);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
