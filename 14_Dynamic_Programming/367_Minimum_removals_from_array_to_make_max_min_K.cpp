/*
QUESTION:-

Given an array of integers and a number K, find the minimum number of elements to
remove from the array so that, in the remaining array, the difference between the
maximum and the minimum element is at most K.

Constraints:
1 <= arr.length <= 100000
1 <= arr[i] <= 1000000000
0 <= K <= 1000000000

Example 1:

Input:
arr = [1,3,4,9,10,11,12,17,20], K = 4

Output:
5
(keep 9, 10, 11, 12 and remove the other 5 elements)

Example 2:

Input:
arr = [1,5,6,2,8], K = 2

Output:
3
(keep 5 and 6, or 1 and 2, or 6 and 8)
*/

/*
APPROACH:-

-> The elements that stay form a group whose largest and smallest values differ by at most K. If we sort the array, such a group can always be taken as a block of neighbours in the sorted array, because adding the elements between the smallest and the largest never makes the difference bigger.
-> So we look for the longest block in the sorted array where the last element minus the first element is at most K. The answer is the array size minus the length of that block.
-> Use two pointers, left and right. Move right one step at a time. While arr[right] - arr[left] is more than K, move left forward.
-> After this, the window from left to right is valid. Remember the longest window.
-> Let N be the size of the array. Sorting takes N * log(N) and each pointer moves at most N steps, so the time is N * log(N).
-> Sorting a copy of the array needs N extra values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minRemovals(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int longest = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        while (arr[right] - arr[left] > k)
        {
            left++;
        }

        longest = max(longest, right - left + 1);
    }

    return n - longest;
}

int main()
{
    vector<int> arr = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int k = 4;

    cout << minRemovals(arr, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log(N))
SPACE COMPLEXITY = O(N)
*/
