/*
QUESTION:-

Given a sorted array, a number k and a value x, find the k elements of the array
that are closest to x. The distance of an element a from x is |a - x|. If two
elements have the same distance, the smaller element is preferred. Return the k
elements in increasing order.

Constraints:
1 <= k <= n <= 100000
-10000 <= arr[i], x <= 10000

Example 1:

Input:
arr = [1,2,3,4,5]
k = 4
x = 3

Output:
1 2 3 4

Example 2:

Input:
arr = [1,1,2,3,4,5]
k = 4
x = -1

Output:
1 1 2 3
*/

/*
APPROACH:-

-> Because the array is sorted, the k closest elements always form one block of k consecutive elements. We only need to find where the block starts.
-> The start can be any index from 0 to n - k. Use binary search on this start index with left = 0 and right = n - k.
-> Look at mid and the element just after the block, mid + k. If x is farther from arr[mid] than from arr[mid + k] (that is, x - arr[mid] > arr[mid + k] - x), then the block starting at mid is worse than the block starting at mid + 1, so set left = mid + 1.
-> Otherwise the block at mid is at least as good, so set right = mid (a tie keeps the smaller elements).
-> When left meets right, the block starts at left. Return the k elements from there.
-> Let N be the size of the array. The binary search costs log N and copying the answer costs K, so the time is log N + K.
-> The answer takes K space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findClosest(vector<int> &arr, int k, int x)
{
    int left = 0;
    int right = (int)arr.size() - k;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (x - arr[mid] > arr[mid + k] - x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    vector<int> result;
    for (int i = left; i < left + k; i++)
    {
        result.push_back(arr[i]);
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> answer = findClosest(arr, k, x);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log N + K)
SPACE COMPLEXITY = O(K)
*/
