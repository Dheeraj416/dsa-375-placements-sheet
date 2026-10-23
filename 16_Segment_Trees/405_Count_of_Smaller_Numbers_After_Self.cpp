/*
QUESTION:-

Given an integer array nums, return an array counts where counts[i] is the number
of elements to the right of nums[i] that are strictly smaller than nums[i].

Constraints:
1 <= nums.length <= 100000
-10000 <= nums[i] <= 10000

Example 1:

Input:
nums = [5,2,6,1]

Output:
[2,1,1,0]
(5 has two smaller numbers on its right: 2 and 1; 2 has one: 1; 6 has one: 1; 1 has none)

Example 2:

Input:
nums = [-1,-1]

Output:
[0,0]
(equal numbers are not smaller)
*/

/*
APPROACH:-

-> Go through the array from right to left. When we are at nums[i], the elements to its right are exactly the elements that we have already inserted into a data structure.
-> Use a segment tree over the values. A leaf stores how many times a value was inserted, and a node stores the sum of its two children, so the sum over a range of leaves is the number of inserted values in that range of values.
-> The values can be negative, so shift them by 10000 to get leaf indexes from 0 to 20000.
-> For each nums[i] from the right: counts[i] is the number of inserted values that are strictly smaller, which is the sum over the leaves [0, shifted value - 1]. Then insert nums[i] by adding 1 at its leaf.
-> Equal values are not counted, because the query stops just before the leaf of nums[i].
-> Let N be the size of the array and M the size of the value range (here 20001). Each element makes one query and one update, each taking log(M), so the time is N * log(M).
-> The tree has at most 4 * M nodes, so the space is M.
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
        if (left > right)
        {
            return 0;
        }

        return query(1, 0, n - 1, left, right);
    }
};

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    int shift = 10000;

    SegmentTree tree(20001);
    vector<int> counts(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int leaf = nums[i] + shift;

        counts[i] = tree.sum(0, leaf - 1);
        tree.add(leaf, 1);
    }

    return counts;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1};

    vector<int> counts = countSmaller(nums);

    for (int i = 0; i < (int)counts.size(); i++)
    {
        cout << counts[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log(M))
SPACE COMPLEXITY = O(M)
*/
