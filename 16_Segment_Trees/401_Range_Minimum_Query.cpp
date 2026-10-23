/*
QUESTION:-

Given an integer array arr, answer many queries of the form rangeMin(left, right):
return the smallest element of arr between the indexes left and right
(inclusive). The array never changes. Implement it with a segment tree.

Constraints:
1 <= arr.length <= 100000
-1000000000 <= arr[i] <= 1000000000
0 <= left <= right < arr.length

Example 1:

Input:
arr = [1,3,2,7,9,11]
queries: rangeMin(1,4), rangeMin(0,5), rangeMin(3,3)

Output:
[2,1,7]

Example 2:

Input:
arr = [5,2,8,6]
queries: rangeMin(2,3), rangeMin(0,1)

Output:
[6,2]
*/

/*
APPROACH:-

-> A segment tree is a binary tree in which every node stores the answer (here, the minimum) for a range of the array. The root stores the whole array, its two children store the left half and the right half, and so on, until a leaf stores one element.
-> Keep the tree in an array: the root is node 1, and the children of node i are 2 * i and 2 * i + 1. An array of size 4 * N is always enough.
-> Build: a function with the arguments (node, left, right). If left equals right, the node is a leaf and stores arr[left]. Otherwise build the two halves around the middle and store the smaller of the two children.
-> Query for the range [ql, qr]: if the range of the node is completely outside the query, return a huge number (it will never be the minimum). If it is completely inside the query, return the stored value. Otherwise ask both children and return the smaller answer.
-> A query visits only a few nodes on every level of the tree, so it takes log(N) time.
-> Let N be the size of the array and Q the number of queries. Building visits every node once, which takes N, and the queries take Q * log(N), so the time is N + Q * log(N).
-> The tree has at most 4 * N nodes, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class MinSegmentTree
{
private:
    int n;
    vector<int> tree;

    void build(vector<int> &arr, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }

        int mid = (left + right) / 2;

        build(arr, 2 * node, left, mid);
        build(arr, 2 * node + 1, mid + 1, right);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int left, int right, int queryLeft, int queryRight)
    {
        if (queryRight < left || right < queryLeft)
        {
            return INT_MAX;
        }

        if (queryLeft <= left && right <= queryRight)
        {
            return tree[node];
        }

        int mid = (left + right) / 2;

        int leftMin = query(2 * node, left, mid, queryLeft, queryRight);
        int rightMin = query(2 * node + 1, mid + 1, right, queryLeft, queryRight);

        return min(leftMin, rightMin);
    }

public:
    MinSegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    int rangeMin(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }
};

int main()
{
    vector<int> arr = {1, 3, 2, 7, 9, 11};

    MinSegmentTree tree(arr);

    cout << tree.rangeMin(1, 4) << "\n";
    cout << tree.rangeMin(0, 5) << "\n";
    cout << tree.rangeMin(3, 3) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + Q * log(N))
SPACE COMPLEXITY = O(N)
*/
