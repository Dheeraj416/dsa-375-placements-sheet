/*
QUESTION:-

Given an array of integers, you can increase or decrease any element by 1 in
one step. Find the minimum number of steps needed to make all the elements of
the array equal.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [1,10,2,9]

Output:
16
(make all elements 5, for example: 4 + 5 + 3 + 4 = 16)

Example 2:

Input:
arr = [1,2,3]

Output:
2
(make all elements 2)
*/

/*
APPROACH:-

-> If we choose a target value t, the number of steps is the sum of |arr[i] - t| over all elements. We want the t that makes this sum smallest.
-> The sum of absolute differences is smallest when t is the median of the array. Think of the smallest and the largest element: any t between them costs the same for that pair (their distance), so the best t must lie between every such outer pair, which is the median.
-> Sort the array and take the middle element as the target. Add up |arr[i] - median| for every element.
-> The sum can be as big as 10^14, so use long long.
-> Let N be the size of the array. Sorting costs N * log N and the sum costs N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minStepsToMakeEqual(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int median = arr[n / 2];
    long long steps = 0;

    for (int x : arr)
    {
        steps = steps + abs((long long)x - median);
    }

    return steps;
}

int main()
{
    vector<int> arr = {1, 10, 2, 9};

    long long answer = minStepsToMakeEqual(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
