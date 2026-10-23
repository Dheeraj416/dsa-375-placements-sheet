/*
QUESTION:-

Given an integer array nums, support these two operations:
- update(index, val): change nums[index] to val.
- sumRange(left, right): return the sum of the elements of nums between the
  indexes left and right (inclusive).
Implement a class NumArray with these operations.

Constraints:
1 <= nums.length <= 30000
-100 <= nums[i], val <= 100
0 <= index < nums.length
0 <= left <= right < nums.length
At most 30000 calls are made to update and sumRange.

Example 1:

Input:
nums = [1,3,5]
sumRange(0,2), update(1,2), sumRange(0,2)

Output:
[9,null,8]

Example 2:

Input:
nums = [7]
sumRange(0,0), update(0,-3), sumRange(0,0)

Output:
[7,null,-3]
*/

/*
APPROACH:-

-> A prefix sum array answers a query fast but is slow to update (one change affects many prefix sums). A segment tree makes both operations take log(N).
-> A segment tree is a binary tree where every node stores the sum of a range of the array: the root stores the whole array, the children store the two halves, and the leaves store single elements. Keep it in an array: the root is node 1 and the children of node i are 2 * i and 2 * i + 1.
-> Our tree has one operation to change a value: add(index, delta). Go down from the root to the leaf of that index (left child if the index is in the left half, right child otherwise), add delta at the leaf, and on the way back recompute every node as the sum of its two children.
-> A query sum(ql, qr): if the range of the node is outside the query, return 0. If it is completely inside the query, return the stored sum. Otherwise add the answers of both children.
-> Start with an empty tree (all zeros) and add every element once. To update an index, add the difference between the new value and the old value (and remember the new value in the array).
-> Let N be the size of the array and Q the number of operations. Building by N adds and every operation take log(N), so the time is (N + Q) * log(N).
-> The tree has at most 4 * N nodes, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    int n;
    vector<int> tree;

    void update(int node, int left, int right, int index, int delta)
    {
        if (left == right)
        {
            tree[node] = tree[node] + delta;
            return;
        }

        int mid = (left + right) / 2;

        if (index <= mid)
        {
            update(2 * node, left, mid, index, delta);
        }
        else
        {
            update(2 * node + 1, mid + 1, right, index, delta);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int left, int right, int queryLeft, int queryRight)
    {
        if (queryRight < left || right < queryLeft)
        {
            return 0;
        }

        if (queryLeft <= left && right <= queryRight)
        {
            return tree[node];
        }

        int mid = (left + right) / 2;

        return query(2 * node, left, mid, queryLeft, queryRight) + query(2 * node + 1, mid + 1, right, queryLeft, queryRight);
    }

public:
    SegmentTree(int size)
    {
        n = size;
        tree.assign(4 * size, 0);
    }

    void add(int index, int delta)
    {
        update(1, 0, n - 1, index, delta);
    }

    int sum(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }
};

class NumArray
{
private:
    vector<int> values;
    SegmentTree *tree;

public:
    NumArray(vector<int> &nums)
    {
        values = nums;
        tree = new SegmentTree(nums.size());

        for (int i = 0; i < (int)nums.size(); i++)
        {
            tree->add(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        tree->add(index, val - values[index]);
        values[index] = val;
    }

    int sumRange(int left, int right)
    {
        return tree->sum(left, right);
    }
};

int main()
{
    vector<int> nums = {1, 3, 5};

    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << "\n";
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O((N + Q) * log(N))
SPACE COMPLEXITY = O(N)
*/
