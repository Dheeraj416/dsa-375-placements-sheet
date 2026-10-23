/*
QUESTION:-

Given an array of size n in which every element is in the range 0 to k - 1,
find the element that
appears the maximum number of times, using O(n) time and O(1) extra space. If
two numbers appear the same maximum number of times, return the smaller one. The
array must have its original values when your function finishes.

Constraints:
1 <= n <= 10000
1 <= k <= 10000
0 <= arr[i] < k

Example 1:

Input:
arr = [2,3,3,5,3,4,1,7]
k = 8

Output:
3

Example 2:

Input:
arr = [1,2,2,2,0,2,0,2,3]
k = 4

Output:
2
*/

/*
APPROACH:-

-> We cannot use a count array (that would need k extra space), so we store the counts inside the input array itself.
-> Every value in the array is less than k, so we can store more information in one cell by adding multiples of k: a cell holds (original value) + k * (count). The original value is still arr[i] % k, because the original value is less than k.
-> For every index i, read the original value v = arr[i] % k and add k to arr[v]. After this pass, arr[v] / k is the number of times the value v appeared.
-> Find the index with the largest stored number (use the first index on a tie, which is the smaller value). That index is the answer.
-> Finally restore the array by replacing every cell with arr[i] % k.
-> Let N be the size of the array. We make three passes, so the time is N.
-> No extra memory is used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxRepeating(vector<int> &arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int value = arr[i] % k;
        arr[value] += k;
    }

    int maxValue = arr[0];
    int result = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
            result = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] % k;
    }

    return result;
}

int main()
{
    vector<int> arr = {2, 3, 3, 5, 3, 4, 1, 7};
    int k = 8;

    cout << maxRepeating(arr, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
