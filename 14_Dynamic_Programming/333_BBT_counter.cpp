/*
QUESTION:-

A binary tree is balanced if, for every node, the heights of its left and right
subtrees differ by at most 1. Given the height h of a tree (the number of
levels, so a single node has height 1 and an empty tree has height 0), count
how many different balanced binary trees of height h exist. Return the count
modulo 1000000007.

Constraints:
1 <= h <= 1000

Example 1:

Input:
h = 3

Output:
15

Example 2:

Input:
h = 4

Output:
315
*/

/*
APPROACH:-

-> Let ways[h] be the number of balanced trees of height h. An empty tree (height 0) and a single node (height 1) can be made in exactly 1 way each, so ways[0] = 1 and ways[1] = 1.
-> A tree of height h has a root, and its two subtrees have heights that differ by at most 1, and at least one of them has height h - 1.
-> Case 1: both subtrees have height h - 1. This gives ways[h - 1] * ways[h - 1] trees.
-> Case 2: the left subtree has height h - 1 and the right has height h - 2, or the other way round. These are two different situations, so they give 2 * ways[h - 1] * ways[h - 2] trees.
-> So ways[h] = ways[h - 1] * (ways[h - 1] + 2 * ways[h - 2]). Take the remainder after every step so that the numbers stay small.
-> Check: ways[2] = 1 * (1 + 2 * 1) = 3 and ways[3] = 3 * (3 + 2 * 1) = 15.
-> We fill the table from 2 up to h, so the time is h, and the table has h + 2 values, so the space is h.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long countBalancedTrees(int height)
{
    const long long MOD = 1000000007;

    vector<long long> ways(height + 2, 0);
    ways[0] = 1;
    ways[1] = 1;

    for (int h = 2; h <= height; h++)
    {
        long long sum = (ways[h - 1] + 2 * ways[h - 2]) % MOD;
        ways[h] = ways[h - 1] * sum % MOD;
    }

    return ways[height];
}

int main()
{
    int h = 3;

    cout << countBalancedTrees(h) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(h)
SPACE COMPLEXITY = O(h)
*/
