/*
QUESTION:-

Given a binary tree, determine whether it is height balanced. A binary tree is
height balanced if, for every node, the heights of its left and right subtrees
differ by at most 1.

Constraints:
0 <= number of nodes <= 5000
-10000 <= Node.val <= 10000

Example 1:

Input:
root = [3,9,20,null,null,15,7]

Output:
true

Example 2:

Input:
root = [1,2,2,3,3,null,null,4,4]

Output:
false
*/

/*
APPROACH:-

-> Use one recursive function that returns the height of a subtree, or -1 if that subtree is not balanced.
-> For a null node return 0.
-> Compute the height of the left subtree. If it is -1, the tree is already unbalanced, so return -1 immediately.
-> Do the same for the right subtree.
-> If the two heights differ by more than 1, return -1. Otherwise return 1 + max(leftHeight, rightHeight).
-> The tree is balanced if the final result is not -1.
-> Every node is visited once, so the time is O(N). Calling a separate height function at every node would cost O(N^2).
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

int checkHeight(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = checkHeight(node->left);

    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = checkHeight(node->right);

    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode *root)
{
    return checkHeight(root) != -1;
}

int main()
{
    vector<int> values = {3, 9, 20, NO_NODE, NO_NODE, 15, 7};
    TreeNode *root = buildTree(values);

    bool answer = isBalanced(root);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
