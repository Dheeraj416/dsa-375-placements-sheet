/*
QUESTION:-

Given an array of distinct integers, find the length of the longest subarray
whose elements, when sorted, form a set of contiguous integers (each element is
exactly 1 more than the previous one in the sorted order). For example the
elements 92, 94, 93, 91, 90 form the contiguous set 90, 91, 92, 93, 94.

Constraints:
1 <= n <= 5000
1 <= arr[i] <= 1000000, all values are different

Example 1:

Input:
arr = [1,56,58,57,90,92,94,93,91,45]

Output:
5
(the subarray 90 92 94 93 91)

Example 2:

Input:
arr = [10,12,11]

Output:
3
*/

/*
APPROACH:-

-> For a subarray of distinct numbers, the numbers form a contiguous set exactly when (maximum - minimum) equals (number of elements - 1), i.e. (maximum - minimum) == (j - i) for the subarray from i to j.
-> Why: k distinct integers always span at least k - 1 in value, and they span exactly k - 1 only when no value is skipped.
-> Try every starting index i. Extend the end index j from i to the right, and keep the minimum and the maximum of the subarray arr[i..j] updated.
-> Whenever max - min == j - i, the subarray has the property, so update the best length with j - i + 1.
-> Let N be the size of the array. There are about N * N / 2 subarrays and each is handled in constant time, so the time is N * N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int largestContiguous(vector<int> &arr)
{
    int n = arr.size();
    int best = 1;

    for (int i = 0; i < n; i++)
    {
        int minValue = arr[i];
        int maxValue = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            minValue = min(minValue, arr[j]);
            maxValue = max(maxValue, arr[j]);

            if (maxValue - minValue == j - i)
            {
                best = max(best, j - i + 1);
            }
        }
    }

    return best;
}

int main()
{
    vector<int> arr = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};

    cout << largestContiguous(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(1)
*/
