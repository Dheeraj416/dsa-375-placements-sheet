/*
QUESTION:-

Given the root of a binary search tree (BST) and an integer k, return the k-th
smallest value (1 indexed) among all the values of the nodes in the tree.

Constraints:
1 <= k <= number of nodes <= 10000
0 <= Node.val <= 10000

Example 1:

Input:
root = [3,1,4,null,2], k = 1

Output:
1

Example 2:

Input:
root = [5,3,6,2,4,null,null,1], k = 3

Output:
3
*/

/*
APPROACH:-

-> An inorder traversal of a BST visits the values in increasing order, so the k-th visited node is the k-th smallest.
-> Do an iterative inorder traversal with a stack: push the current node and go left as far as possible.
-> Pop a node, count it as visited, and if the count equals k, return its value immediately.
-> Otherwise continue with the right child of the popped node.
-> The traversal stops as soon as the k-th value is reached, so the rest of the tree is never visited.
-> Let H be the height of the tree. The time is O(H + K) and the stack holds at most H nodes.
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

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> pending;
    TreeNode *current = root;
    int visited = 0;

    while (current != nullptr || !pending.empty())
    {
        while (current != nullptr)
        {
            pending.push(current);
            current = current->left;
        }

        current = pending.top();
        pending.pop();
        visited++;

        if (visited == k)
        {
            return current->val;
        }

        current = current->right;
    }

    return -1;
}

int main()
{
    vector<int> values = {5, 3, 6, 2, 4, NO_NODE, NO_NODE, 1};
    TreeNode *root = buildTree(values);
    int k = 3;

    int answer = kthSmallest(root, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(H + K)
SPACE COMPLEXITY = O(H)
*/
