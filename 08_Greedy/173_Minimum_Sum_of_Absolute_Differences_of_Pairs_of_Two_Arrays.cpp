/*
QUESTION:-

Given two arrays a and b of the same size n, pair every element of a with exactly
one element of b (each element is used in exactly one pair). The cost of a pair
is the absolute difference of its two elements. Find the minimum possible sum of
the costs of all the pairs.

Constraints:
1 <= n <= 100000
-100000 <= a[i], b[i] <= 100000

Example 1:

Input:
a = [4,1,8,7]
b = [2,3,6,5]

Output:
6
(sorted pairs: |1-2| + |4-3| + |7-5| + |8-6| = 1 + 1 + 2 + 2)

Example 2:

Input:
a = [4,1,2]
b = [2,4,1]

Output:
0
(sorted pairs: |1-1| + |2-2| + |4-4| = 0)
*/

/*
APPROACH:-

-> The best way to make the total difference small is to pair the smallest element of a with the smallest element of b, the second smallest with the second smallest, and so on.
-> Why: if two pairs were crossed (a larger a-value with a smaller b-value, and a smaller a-value with a larger b-value), uncrossing them never increases the sum of the differences.
-> So sort both arrays in increasing order and add |a[i] - b[i]| for every index i.
-> Use long long for the sum because it can reach about 2 * 10^10.
-> Let N be the size of the arrays. Sorting costs N * log N and the sum costs N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minimumDifferenceSum(vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long total = 0;

    for (int i = 0; i < (int)a.size(); i++)
    {
        total += abs(a[i] - b[i]);
    }

    return total;
}

int main()
{
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};

    cout << minimumDifferenceSum(a, b) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
