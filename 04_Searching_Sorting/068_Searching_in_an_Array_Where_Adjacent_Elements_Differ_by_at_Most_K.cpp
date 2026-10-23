/*
QUESTION:-

You are given an array in which the absolute difference between any two
adjacent elements is at most k, and a value x. Find the index of the first
occurrence of x in the array, or return -1 if x is not present.

Constraints:
1 <= arr.length <= 100000
1 <= k <= 1000000
-1000000000 <= arr[i], x <= 1000000000
|arr[i] - arr[i + 1]| <= k

Example 1:

Input:
arr = [20,40,50,70,70,60]
k = 20
x = 60

Output:
5

Example 2:

Input:
arr = [4,5,6,7,6]
k = 1
x = 6

Output:
2
*/

/*
APPROACH:-

-> Normal binary search does not work because the array is not sorted. But because neighbors differ by at most k, the values change slowly, and we can jump over positions that cannot contain x.
-> Start at index 0. If arr[i] equals x, return i.
-> Otherwise the gap between arr[i] and x is |arr[i] - x|. Each step to a neighbor changes the value by at most k, so we need at least |arr[i] - x| / k steps before we can reach the value x. So we can safely jump ahead by max(1, |arr[i] - x| / k) positions without missing the first x.
-> Repeat until we reach the end of the array. If x was never found, return -1.
-> The jumps are always safe, so the first occurrence is found and nothing before it is skipped.
-> Let N be the size of the array. In the worst case every jump is 1 step, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int searchWithJumps(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    int i = 0;

    while (i < n)
    {
        if (arr[i] == x)
        {
            return i;
        }

        int difference = abs(arr[i] - x);
        i = i + max(1, difference / k);
    }

    return -1;
}

int main()
{
    vector<int> arr = {20, 40, 50, 70, 70, 60};
    int k = 20;
    int x = 60;

    int answer = searchWithJumps(arr, k, x);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
