/*
QUESTION:-

You are given two strings A and B of the same length. In one operation you can
pick any character of A and move it to the front of A. Find the minimum number
of operations needed to transform A into B. If it is not possible, return -1.

Constraints:
1 <= A.length == B.length <= 100000
A and B contain uppercase English letters.

Example 1:

Input:
A = "EACBD"
B = "EABCD"

Output:
3
(move B to the front: BEACD, move A to the front: ABECD, move E to the front: EABCD)

Example 2:

Input:
A = "ABC"
B = "CBA"

Output:
2
(move B to the front: BAC, move C to the front: CBA)
*/

/*
APPROACH:-

-> The transformation is possible only if A and B have the same letters with the same counts. Sort copies of both and compare them. If they differ, return -1.
-> Characters that are never moved keep their relative order, and all the moved characters end up in front of them. So we want to keep as many characters as possible unmoved: the longest suffix of B that appears as a subsequence of A, read from the end.
-> Scan both strings from the end with two pointers: i on A and j on B. If A[i] equals B[j], this character can stay, so move both pointers backward. Otherwise A[i] must be moved to the front, so count one operation and move only i backward.
-> When i goes below 0, every character of A was either matched or moved. The count is the minimum number of operations.
-> Example 1: D matches D, B cannot match C so it is moved, C matches C, then A and E cannot match B so both are moved. That is 3 operations.
-> Let N be the length of the strings. Sorting costs N * log N and the scan costs N, so the time is N * log N.
-> The sorted copies take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int minOperationsToTransform(string a, string b)
{
    int n = a.size();

    string sortedA = a;
    string sortedB = b;
    sort(sortedA.begin(), sortedA.end());
    sort(sortedB.begin(), sortedB.end());

    if (sortedA != sortedB)
    {
        return -1;
    }

    int operations = 0;
    int i = n - 1;
    int j = n - 1;

    while (i >= 0)
    {
        if (a[i] == b[j])
        {
            i--;
            j--;
        }
        else
        {
            operations++;
            i--;
        }
    }

    return operations;
}

int main()
{
    string a = "EACBD";
    string b = "EABCD";

    int answer = minOperationsToTransform(a, b);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
