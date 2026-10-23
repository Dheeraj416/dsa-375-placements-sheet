/*
QUESTION:-

Given a binary search tree (BST) with unique values and two values p and q that
exist in the tree, find the lowest common ancestor (LCA) of the two nodes. The
lowest common ancestor is the lowest node that has both p and q as its
descendants, where a node is allowed to be a descendant of itself.

Constraints:
2 <= number of nodes <= 100000
All the node values are unique, and p != q

Example 1:

Input:
root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8

Output:
6

Example 2:

Input:
root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4

Output:
2
*/

/*
APPROACH:-

-> Use the BST property: smaller values are on the left and larger values are on the right.
-> Start at the root. If both p and q are smaller than the current node, both are in the left subtree, so move left.
-> If both are larger than the current node, both are in the right subtree, so move right.
-> Otherwise the two values are on different sides of the current node (or one of them equals it), so this node is the first point where their paths split. It is the LCA.
-> No recursion or extra memory is needed, just one pointer that walks down the tree.
-> Let H be the height of the tree. The walk goes down at most H levels.
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
    TreeNode *current = root;

    while (current != nullptr)
    {
        if (firstValue < current->val && secondValue < current->val)
        {
            current = current->left;
        }
        else if (firstValue > current->val && secondValue > current->val)
        {
            current = current->right;
        }
        else
        {
            return current;
        }
    }

    return nullptr;
}

int main()
{
    vector<int> values = {6, 2, 8, 0, 4, 7, 9, NO_NODE, NO_NODE, 3, 5};
    TreeNode *root = buildTree(values);

    TreeNode *answer = lowestCommonAncestor(root, 2, 8);

    cout << answer->val << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(H)
SPACE COMPLEXITY = O(1)
*/
