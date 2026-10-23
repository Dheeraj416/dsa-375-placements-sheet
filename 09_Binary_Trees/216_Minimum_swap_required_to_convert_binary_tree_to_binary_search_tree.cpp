/*
QUESTION:-

Given the root of a binary tree with distinct values, find the minimum number of
swaps needed to convert it into a binary search tree. In one swap you can
exchange the values of any two nodes of the tree (the shape of the tree stays
the same).

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000, all values are different

Example 1:

Input:
root = [5,6,7,8,9,10,11]

Output:
3
(the inorder is 8 6 9 5 10 7 11, which needs 3 swaps to become sorted)

Example 2:

Input:
root = [1,2,3]

Output:
1
(the inorder is 2 1 3, swap 2 and 1)
*/

/*
APPROACH:-

-> A tree is a binary search tree exactly when its inorder traversal is sorted in increasing order. The shape stays the same, so we only need to fix the values.
-> Take the inorder traversal of the tree into an array. Now the problem is the minimum number of swaps to sort an array of distinct numbers.
-> Make pairs (value, original index) and sort them by value. The pair at sorted position i tells us that the element currently at index sorted[i].second should go to position i.
-> These moves form cycles. A cycle of length L can be fixed with L - 1 swaps. Elements already in their place form cycles of length 1 and need no swaps.
-> Walk through the positions, follow every unvisited cycle by jumping i -> sorted[i].second, count its length, and add length - 1 to the answer.
-> Let N be the number of nodes. Sorting costs N * log N, so the time is N * log N.
-> The arrays take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

const int NO_NODE = -1;

TreeNode *buildTree(vector<int> &values)
{
    if (values.empty() || values[0] == NO_NODE)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> pending;
    pending.push(root);
    int index = 1;

    while (!pending.empty() && index < (int)values.size())
    {
        TreeNode *current = pending.front();
        pending.pop();

        if (index < (int)values.size() && values[index] != NO_NODE)
        {
            current->left = new TreeNode(values[index]);
            pending.push(current->left);
        }
        index++;

        if (index < (int)values.size() && values[index] != NO_NODE)
        {
            current->right = new TreeNode(values[index]);
            pending.push(current->right);
        }
        index++;
    }

    return root;
}

void inorder(TreeNode *root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

int minimumSwaps(TreeNode *root)
{
    vector<int> values;
    inorder(root, values);

    int n = values.size();
    vector<pair<int, int>> sorted;
    for (int i = 0; i < n; i++)
    {
        sorted.push_back({values[i], i});
    }
    sort(sorted.begin(), sorted.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] || sorted[i].second == i)
        {
            continue;
        }

        int cycleSize = 0;
        int j = i;
        while (!visited[j])
        {
            visited[j] = true;
            j = sorted[j].second;
            cycleSize++;
        }

        swaps += cycleSize - 1;
    }

    return swaps;
}

int main()
{
    vector<int> values = {5, 6, 7, 8, 9, 10, 11};
    TreeNode *root = buildTree(values);

    cout << minimumSwaps(root) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
