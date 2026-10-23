/*
QUESTION:-

You are given an integer array instructions. Start with an empty container nums,
and insert the elements of instructions into nums one by one from left to right.
The cost of inserting an element x is the smaller of these two numbers: the
number of elements already in nums that are strictly less than x, and the number
of elements already in nums that are strictly greater than x. Return the total
cost of inserting all the elements, modulo 1000000007.

Constraints:
1 <= instructions.length <= 100000
1 <= instructions[i] <= 100000

Example 1:

Input:
instructions = [1,5,6,2]

Output:
1
(inserting 2 costs min(1, 2) = 1 because 1 is smaller and 5, 6 are greater; all other insertions cost 0)

Example 2:

Input:
instructions = [1,2,3,6,5,4]

Output:
3
(inserting 5 costs min(3, 1) = 1, inserting 4 costs min(3, 2) = 2)
*/

/*
APPROACH:-

-> We need two counts for every x: how many already inserted values are smaller than x, and how many are greater. A segment tree over the values (not over the positions) can give both counts.
-> Let the tree have one leaf for every possible value from 0 to the biggest value, and let a leaf store how many times that value was inserted. A node stores the sum of its two children, so a query for a range of values returns how many inserted elements have a value in that range.
-> For an instruction x: smaller = the count of values in [0, x - 1], and greater = the count of values in [x + 1, biggest value]. The cost is min(smaller, greater). Add it to the total, then insert x by adding 1 at the leaf of x.
-> The total can be bigger than a 32-bit number, so use a long long, and take the remainder with 1000000007 at the end.
-> Let N be the number of instructions and M the biggest value. Each instruction makes two queries and one update on the tree, which take log(M) each, so the time is N * log(M).
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

int createSortedArray(vector<int> &instructions)
{
    int biggest = 0;

    for (int i = 0; i < (int)instructions.size(); i++)
    {
        biggest = max(biggest, instructions[i]);
    }

    SegmentTree tree(biggest + 1);
    long long totalCost = 0;

    for (int i = 0; i < (int)instructions.size(); i++)
    {
        int x = instructions[i];

        int smaller = tree.sum(0, x - 1);
        int greater = tree.sum(x + 1, biggest);

        totalCost = totalCost + min(smaller, greater);
        tree.add(x, 1);
    }

    return (int)(totalCost % 1000000007);
}

int main()
{
    vector<int> instructions = {1, 5, 6, 2};

    cout << createSortedArray(instructions) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log(M))
SPACE COMPLEXITY = O(M)
*/
