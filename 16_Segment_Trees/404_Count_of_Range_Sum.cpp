/*
QUESTION:-

Given an integer array nums and two integers lower and upper, return the number of
range sums that lie in the range [lower, upper] (both ends included). The range
sum S(i, j) is the sum of the elements of nums between the indexes i and j
(inclusive), where i <= j.

Constraints:
1 <= nums.length <= 100000
-2147483648 <= nums[i] <= 2147483647
-100000 <= lower <= upper <= 100000

Example 1:

Input:
nums = [-2,5,-1], lower = -2, upper = 2

Output:
3
(the ranges [0,0], [2,2] and [0,2] have the sums -2, -1 and 2)

Example 2:

Input:
nums = [0], lower = 0, upper = 0

Output:
1
(the only range is [0,0], with the sum 0)
*/

/*
APPROACH:-

-> Let prefix[k] be the sum of the first k elements (prefix[0] = 0). The sum of the range from i to j is prefix[j + 1] - prefix[i]. So we count the pairs (a, b) with a < b and lower <= prefix[b] - prefix[a] <= upper.
-> For a fixed b, the earlier prefix sums prefix[a] that work are those in the range [prefix[b] - upper, prefix[b] - lower]. So go through the prefix sums from left to right and, for each one, count how many of the earlier prefix sums fall in this range.
-> To count quickly, use a segment tree over the prefix sums sorted without duplicates. A leaf stores how many times a value was seen. The count of values in a range of values is the sum over a range of leaves, which the tree gives in log time.
-> Turn the value range into a leaf range with binary search: the first leaf is the first sorted value that is at least prefix[b] - upper, and the last leaf is the last sorted value that is at most prefix[b] - lower.
-> Start by inserting prefix[0]. For each b from 1 to N: count the earlier values in the range, add the count to the answer, then insert prefix[b].
-> The prefix sums can be bigger than a 32-bit number and the answer can be as large as N * N / 2, so use long long for both.
-> Let N be the size of the array. Sorting takes N * log(N), and each of the N steps does two binary searches and one tree query and update, each log(N), so the time is N * log(N).
-> The prefix array, the sorted array and the tree all need about N values, so the space is N.
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

long long countRangeSum(vector<int> &nums, int lower, int upper)
{
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    vector<long long> sortedValues = prefix;
    sort(sortedValues.begin(), sortedValues.end());
    sortedValues.erase(unique(sortedValues.begin(), sortedValues.end()), sortedValues.end());

    SegmentTree tree(sortedValues.size());

    int firstPosition = lower_bound(sortedValues.begin(), sortedValues.end(), prefix[0]) - sortedValues.begin();
    tree.add(firstPosition, 1);

    long long answer = 0;

    for (int b = 1; b <= n; b++)
    {
        long long low = prefix[b] - upper;
        long long high = prefix[b] - lower;

        int leftLeaf = lower_bound(sortedValues.begin(), sortedValues.end(), low) - sortedValues.begin();
        int rightLeaf = upper_bound(sortedValues.begin(), sortedValues.end(), high) - sortedValues.begin() - 1;

        answer = answer + tree.sum(leftLeaf, rightLeaf);

        int position = lower_bound(sortedValues.begin(), sortedValues.end(), prefix[b]) - sortedValues.begin();
        tree.add(position, 1);
    }

    return answer;
}

int main()
{
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;

    cout << countRangeSum(nums, lower, upper) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log(N))
SPACE COMPLEXITY = O(N)
*/
