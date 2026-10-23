/*
QUESTION:-

Given an array of n integers, rearrange its elements in any order so that the
sum of the absolute differences of the consecutive elements, taken in a circle
(the last element is also compared with the first element), is maximum. Return
that maximum sum.

Constraints:
2 <= n <= 100000
1 <= arr[i] <= 100000

Example 1:

Input:
arr = [4,2,1,8]

Output:
18
(the arrangement 1, 8, 2, 4 gives 7 + 6 + 2 + 3 = 18)

Example 2:

Input:
arr = [10,12,15]

Output:
10
(any order of three numbers gives 2 * (15 - 10) = 10)
*/

/*
APPROACH:-

-> In the circular sum, every element appears in two differences. In each difference it is either added (when it is the bigger one) or subtracted (when it is the smaller one). So every element contributes +2, -2 or 0 times its value.
-> To make the sum as large as possible, the biggest elements should always be added twice and the smallest elements should always be subtracted twice.
-> The number of elements added must equal the number subtracted. So take the n / 2 largest elements with +2 and the n / 2 smallest elements with -2. If n is odd, the middle element contributes 0.
-> Such an arrangement exists: place the elements alternately small, big, small, big around the circle.
-> So sort the array and compute the sum of 2 * arr[n - 1 - i] - 2 * arr[i] for i from 0 to n / 2 - 1.
-> Use long long for the sum.
-> Let N be the size of the array. Sorting costs N * log N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long maxCircularSum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    long long total = 0;

    for (int i = 0; i < n / 2; i++)
    {
        total += 2LL * arr[n - 1 - i];
        total -= 2LL * arr[i];
    }

    return total;
}

int main()
{
    vector<int> arr = {4, 2, 1, 8};

    cout << maxCircularSum(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
