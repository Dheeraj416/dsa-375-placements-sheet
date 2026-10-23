/*
QUESTION:-

You are given a sorted list of keys and the number of times each key is searched
(its frequency). Build a binary search tree from the keys such that the total
search cost is as small as possible. The cost of searching a key is its
frequency multiplied by its level in the tree (the root is at level 1). Return
the minimum total cost. Only the frequencies matter for the answer, because the
keys are already in sorted order.

Constraints:
1 <= keys.length <= 100
1 <= freq[i] <= 1000

Example 1:

Input:
keys = [10,12,20]
freq = [34,8,50]

Output:
142
(the root is 20, its left child is 10, and the right child of 10 is 12: cost 50 + 2 * 34 + 3 * 8)

Example 2:

Input:
keys = [10,12]
freq = [34,50]

Output:
118
(the root is 12 and the left child is 10: cost 50 + 2 * 34)
*/

/*
APPROACH:-

-> Let cost[i][j] be the minimum search cost of a tree built from the keys i to j. An empty range costs 0.
-> Choose a root r between i and j. The keys i to r - 1 form the left subtree and the keys r + 1 to j form the right subtree, and we use the best trees for them: cost[i][r - 1] and cost[r + 1][j].
-> Putting the two subtrees below a new root moves every key of the range down by one level, so each key costs its frequency once more. That adds the sum of all frequencies from i to j.
-> So cost[i][j] = (sum of freq[i..j]) + the smallest value of (cost[i][r - 1] + cost[r + 1][j]) over all roots r.
-> Use prefix sums of the frequencies to get the sum of any range in constant time. Fill the table by the length of the range, from 1 up to n. The answer is cost[1][n].
-> Let N be the number of keys. There are about N * N ranges and for each we try up to N roots, so the time is N * N * N.
-> The table has about N * N cells, so the space is N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int optimalBST(vector<int> &freq)
{
    int n = freq.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + freq[i - 1];
    }

    vector<vector<int>> cost(n + 2, vector<int>(n + 2, 0));

    for (int length = 1; length <= n; length++)
    {
        for (int i = 1; i + length - 1 <= n; i++)
        {
            int j = i + length - 1;
            int rangeSum = prefix[j] - prefix[i - 1];

            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++)
            {
                int total = cost[i][r - 1] + cost[r + 1][j] + rangeSum;
                cost[i][j] = min(cost[i][j], total);
            }
        }
    }

    return cost[1][n];
}

int main()
{
    vector<int> freq = {34, 8, 50};

    cout << optimalBST(freq) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N * N)
SPACE COMPLEXITY = O(N * N)
*/
