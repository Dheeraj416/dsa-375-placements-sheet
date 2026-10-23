/*
QUESTION:-

You have the natural numbers 1, 2, 3, ... and a list of distinct integers that
are removed from them. Find the k-th smallest natural number that is still
present (not removed).

Constraints:
1 <= number of removed integers <= 100000
1 <= removed[i] <= 1000000000
1 <= k <= 1000000000

Example 1:

Input:
removed = [1,3]
k = 4

Output:
6
(the remaining numbers are 2, 4, 5, 6, ...)

Example 2:

Input:
removed = [1]
k = 1

Output:
2
*/

/*
APPROACH:-

-> If nothing was removed, the answer would be k. Every removed number that is not larger than the answer pushes the answer one step to the right.
-> Sort the removed numbers in increasing order and start with answer = k.
-> Go through the sorted removed numbers. If the removed number is less than or equal to the current answer, then it takes one of the places before the answer, so the answer becomes answer + 1.
-> If a removed number is greater than the current answer, it (and all the later, larger ones) cannot change the answer, so stop.
-> Let N be the number of removed integers. Sorting costs N * log N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long kthRemaining(vector<int> &removed, long long k)
{
    sort(removed.begin(), removed.end());

    long long answer = k;

    for (int i = 0; i < (int)removed.size(); i++)
    {
        if (removed[i] <= answer)
        {
            answer++;
        }
        else
        {
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> removed = {1, 3};
    long long k = 4;

    cout << kthRemaining(removed, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
