/*
QUESTION:-

Given two arrays a and b of the same size n and a number k, check whether it is
possible to rearrange (permute) the arrays so that the sum a[i] + b[i] is
greater than or equal to k for every index i. Return true if it is possible,
otherwise return false.

Constraints:
1 <= n <= 100000
1 <= a[i], b[i] <= 1000000000
1 <= k <= 2000000000

Example 1:

Input:
a = [2,1,3]
b = [7,8,9]
k = 10

Output:
true
(pair 1 with 9, 2 with 8 and 3 with 7: every sum is 10)

Example 2:

Input:
a = [1,2,2,1]
b = [3,3,3,4]
k = 5

Output:
false
(the pair 1 + 3 = 4 is smaller than 5, whatever the pairing)
*/

/*
APPROACH:-

-> To make all the sums as large as possible at their weakest point, pair the smallest element of a with the largest element of b, the second smallest of a with the second largest of b, and so on.
-> Sort a in increasing order and b in decreasing order. Now a[i] is paired with b[i].
-> If some pair has a sum smaller than k, no other arrangement can fix it, because the smallest element of a already got the largest possible partner. So return false.
-> If every pair has a sum of at least k, return true.
-> Why it works: if a smaller a-value took a smaller b-partner, swapping the partners would never make the worst pair worse (an exchange argument).
-> Let N be the size of the arrays. Sorting costs N * log N and the check costs N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canPermute(vector<int> &a, vector<int> &b, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < (int)a.size(); i++)
    {
        if ((long long)a[i] + b[i] < k)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> a = {2, 1, 3};
    vector<int> b = {7, 8, 9};
    int k = 10;

    bool answer = canPermute(a, b, k);

    cout << (answer ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
