/*
QUESTION:-

Given an array of integers, reverse the array in place, so that the first
element becomes the last, the second element becomes the second last, and so on.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [1,2,3,4,5]

Output:
[5,4,3,2,1]

Example 2:

Input:
arr = [4,5,1,2]

Output:
[2,1,5,4]
*/

/*
APPROACH:-

-> Use two pointers: left starts at the first index and right starts at the last index.
-> Swap the elements at left and right, then move left one step forward and right one step backward.
-> Continue while left is smaller than right. When they meet or cross, every pair has been swapped.
-> The middle element of an odd sized array stays where it is, which is correct.
-> Let N be the size of the array. We do N / 2 swaps, so the time is N.
-> The array is changed in place and only two index variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    reverseArray(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
