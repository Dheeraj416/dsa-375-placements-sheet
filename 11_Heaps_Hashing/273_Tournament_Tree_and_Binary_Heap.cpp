/*
QUESTION:-

A tournament tree (winner tree) is a binary tree in which the leaves are the
players (here, the numbers of an array). Every internal node stores the winner of
its two children, where the winner is the smaller number. So the root stores the
smallest number. Build a tournament tree over an array of numbers, and use it to
find the smallest and the second smallest number of the array. Print them
separated by a space.

Constraints:
2 <= n <= 100000
1 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [61,6,100,9,10,12,17]

Output:
6 9

Example 2:

Input:
arr = [4,2,8,1]

Output:
1 2
*/

/*
APPROACH:-

-> Store the tree in an array called tree of size 2 * n, in the same way as a binary heap: the node i has the children 2 * i and 2 * i + 1. The leaves are the positions n to 2 * n - 1, and leaf n + j belongs to arr[j]. Every cell of the tree stores the INDEX in arr of the winner below it.
-> Build: the leaf n + j stores j. Then for i from n - 1 down to 1, tree[i] is the better (smaller) one of the winners tree[2 * i] and tree[2 * i + 1]. After this, tree[1] is the index of the smallest number.
-> The smallest number is arr[tree[1]]. To find the second smallest, take the winner out of the game: set its value in arr to a huge number and replay only its matches, from its leaf up to the root (recompute tree[i] for the parents i / 2, i / 4, ... down to 1).
-> The new winner at the root is the second smallest number.
-> Let N be the size of the array. Building costs N, and replaying one path costs log N, so the time is N + log N, which is N.
-> The tree has 2 * N cells, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int betterOf(vector<int> &arr, int a, int b)
{
    if (arr[a] <= arr[b])
    {
        return a;
    }
    return b;
}

void findTwoSmallest(vector<int> &arr)
{
    int n = arr.size();
    vector<int> tree(2 * n, 0);

    for (int j = 0; j < n; j++)
    {
        tree[n + j] = j;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        tree[i] = betterOf(arr, tree[2 * i], tree[2 * i + 1]);
    }

    int winner = tree[1];
    int smallest = arr[winner];

    arr[winner] = INT_MAX;

    int i = (n + winner) / 2;
    while (i >= 1)
    {
        tree[i] = betterOf(arr, tree[2 * i], tree[2 * i + 1]);
        i = i / 2;
    }

    int secondSmallest = arr[tree[1]];

    cout << smallest << " " << secondSmallest << "\n";
}

int main()
{
    vector<int> arr = {61, 6, 100, 9, 10, 12, 17};

    findTwoSmallest(arr);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
