/*
QUESTION:-

The Catalan numbers are the sequence 1, 1, 2, 5, 14, 42, ... Given n, return the
n-th Catalan number (counting from n = 0). The Catalan number C(n) is the number
of different binary search trees with n nodes, and it is defined by C(0) = 1
and C(n) = C(0) * C(n - 1) + C(1) * C(n - 2) + ... + C(n - 1) * C(0).

Constraints:
0 <= n <= 30
The answer fits in a 64-bit signed integer.

Example 1:

Input:
n = 5

Output:
42

Example 2:

Input:
n = 3

Output:
5
*/

/*
APPROACH:-

-> Use the rule C(n) = sum of C(j) * C(n - 1 - j) for j from 0 to n - 1. Think of a binary search tree with n nodes: one node is the root, j nodes go to the left subtree and n - 1 - j go to the right subtree, and the two sides are chosen independently.
-> Keep a table c[0..n]. Set c[0] = 1.
-> For every i from 1 to n, add up c[j] * c[i - 1 - j] for j from 0 to i - 1 and store it in c[i]. All the smaller values are already in the table.
-> The answer is c[n].
-> For each i we add up i terms, so the total work is about n * n / 2 and the time is n * n.
-> The table has n + 1 values, so the space is n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long catalan(int n)
{
    vector<long long> c(n + 1, 0);
    c[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            c[i] = c[i] + c[j] * c[i - 1 - j];
        }
    }

    return c[n];
}

int main()
{
    int n = 5;

    cout << catalan(n) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(n * n)
SPACE COMPLEXITY = O(n)
*/
