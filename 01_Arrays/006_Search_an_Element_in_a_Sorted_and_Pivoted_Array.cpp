/*
QUESTION:-

A sorted array of distinct integers was rotated at an unknown pivot, for
example [1,2,3,4,5,6,7] became [4,5,6,7,1,2,3]. Given such an array and a value
key, return the index of key in the array, or -1 if it is not present.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000
All the values are distinct.

Example 1:

Input:
arr = [5,6,7,8,9,10,1,2,3]
key = 3

Output:
8

Example 2:

Input:
arr = [5,6,7,8,9,10,1,2,3]
key = 30

Output:
-1
*/

/*
APPROACH:-

-> The array is two sorted parts glued together: the part before the pivot and the part after it. The smallest element is the start of the second part.
-> Step 1: find the index of the smallest element (the pivot position) with binary search. If arr[mid] is bigger than the last element, the smallest element is on the right of mid, otherwise it is at mid or on its left.
-> Step 2: now we know the two sorted parts: [0, pivot - 1] and [pivot, n - 1]. If the key is between arr[pivot] and arr[n - 1], search the right part, otherwise search the left part.
-> Each search is a normal binary search on a sorted range.
-> Edge cases: if the array is not rotated, the pivot is index 0 and the whole array is searched. If the key is not found, return -1.
-> Let N be the size of the array. We run two binary searches, so the time is log N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int binarySearch(vector<int> &arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int searchInPivotedArray(vector<int> &arr, int key)
{
    int n = arr.size();
    int pivot = findPivot(arr);

    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, key);
    }

    return binarySearch(arr, 0, pivot - 1, key);
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;

    int answer = searchInPivotedArray(arr, key);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log N)
SPACE COMPLEXITY = O(1)
*/
