/*
QUESTION:-

Given an array of integers, count the number of inversions. An inversion is a
pair of indices (i, j) such that i < j and arr[i] > arr[j].

Constraints:
1 <= arr.length <= 100000
1 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [5,3,2,4,1]

Output:
8
Explanation: The inversions are (5,3), (5,2), (5,4), (5,1), (3,2), (3,1), (2,1), (4,1).

Example 2:

Input:
arr = [2,4,1,3,5]

Output:
3
*/

/*
APPROACH:-

-> Use merge sort and count inversions while merging.
-> Split the array into two halves, count the inversions in each half recursively, and then count the cross inversions.
-> While merging two sorted halves, if left[i] > right[j], then every element from i to the end of the left half is greater than right[j].
-> So add (mid - i + 1) to the count and take right[j] first.
-> Each pair is counted exactly once, either inside a half or while merging across the halves.
-> The count can exceed the range of int, so it is stored in a long long.
-> Merge sort gives O(N log N) instead of the O(N^2) brute force.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int> &arr, int low, int mid, int high)
{
    vector<int> merged;
    int left = low;
    int right = mid + 1;
    long long count = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            merged.push_back(arr[left]);
            left++;
        }
        else
        {
            merged.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        merged.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        merged.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = merged[i - low];
    }

    return count;
}

long long mergeSortAndCount(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = (low + high) / 2;
    long long count = 0;

    count += mergeSortAndCount(arr, low, mid);
    count += mergeSortAndCount(arr, mid + 1, high);
    count += mergeAndCount(arr, low, mid, high);

    return count;
}

long long countInversions(vector<int> &arr)
{
    return mergeSortAndCount(arr, 0, (int)arr.size() - 1);
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};

    long long answer = countInversions(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N log N)
SPACE COMPLEXITY = O(N)
*/
