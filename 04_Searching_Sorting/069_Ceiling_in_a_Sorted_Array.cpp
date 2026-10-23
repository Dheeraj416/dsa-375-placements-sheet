/*
QUESTION:-

Given a sorted array of non-negative integers and a value x, find the ceiling
of x: the smallest element in the array that is greater than or equal to x. If
there is no such element, return -1.

Constraints:
1 <= arr.length <= 100000
0 <= arr[i], x <= 1000000000
The array is sorted in increasing order.

Example 1:

Input:
arr = [1,2,8,10,10,12,19]
x = 3

Output:
8

Example 2:

Input:
arr = [1,2,8,10,10,12,19]
x = 20

Output:
-1
*/

/*
APPROACH:-

-> The array is sorted, so use binary search to find the first element that is greater than or equal to x.
-> Keep low and high. Look at the middle element. If arr[mid] >= x, it is a candidate for the ceiling, so remember it and search for a smaller candidate on the left (high = mid - 1).
-> If arr[mid] < x, the ceiling must be on the right, so low = mid + 1.
-> When the search ends, the last remembered candidate is the smallest element that is at least x. If we never remembered one, all the elements are smaller than x, so the answer is -1.
-> Let N be the size of the array. The range halves every step, so the time is log N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int ceilingInSortedArray(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int answer = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            answer = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 3;

    int answer = ceilingInSortedArray(arr, x);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log N)
SPACE COMPLEXITY = O(1)
*/
