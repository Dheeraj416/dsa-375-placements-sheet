/*
QUESTION:-

Given a binary tree with unique node values and the values of two nodes p and
q that exist in the tree, find their lowest common ancestor (LCA). The lowest
common ancestor is the lowest node in the tree that has both p and q as its
descendants, where a node is allowed to be a descendant of itself.

Constraints:
2 <= number of nodes <= 100000
All the node values are unique, and p != q

Example 1:

Input:
root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1

Output:
3

Example 2:

Input:
root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4

Output:
5
Explanation: A node can be an ancestor of itself, and 5 is an ancestor of 4.
*/

/*
APPROACH:-

-> Use recursion that returns a node pointer for every subtree.
-> If the current node is null, return null. If the current node is p or q, return the current node.
-> Otherwise search the left subtree and the right subtree.
-> If both searches return a non-null node, then p is in one subtree and q is in the other, so the current node is the LCA.
-> If only one search returns a non-null node, both p and q are in that subtree (or only one was found there), so return that result upwards.
-> The first node where the two searches meet is the lowest common ancestor.
-> Let H be the height of the tree. Every node is visited once and the recursion goes H levels deep.
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

TreeNode *lowestCommonAncestor(TreeNode *root, int firstValue, int secondValue)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == firstValue || root->val == secondValue)
    {
        return root;
    }

    TreeNode *leftResult = lowestCommonAncestor(root->left, firstValue, secondValue);
    TreeNode *rightResult = lowestCommonAncestor(root->right, firstValue, secondValue);

    if (leftResult != nullptr && rightResult != nullptr)
    {
        return root;
    }

    if (leftResult != nullptr)
    {
        return leftResult;
    }

    return rightResult;
}

int main()
{
    vector<int> values = {3, 5, 1, 6, 2, 0, 8, NO_NODE, NO_NODE, 7, 4};
    TreeNode *root = buildTree(values);

    TreeNode *answer = lowestCommonAncestor(root, 5, 1);

    cout << answer->val << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
