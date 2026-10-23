/*
QUESTION:-

Given the root of a binary tree, return its maximum depth. The maximum depth is
the number of nodes along the longest path from the root node down to the
farthest leaf node.

Constraints:
0 <= number of nodes <= 10000
-100 <= Node.val <= 100

Example 1:

Input:
root = [3,9,20,null,null,15,7]

Output:
3

Example 2:

Input:
root = [1,null,2]

Output:
2
*/

/*
APPROACH:-

-> The depth of an empty tree is 0.
-> The depth of any other tree is 1 (for the root) plus the larger of the depths of its left and right subtrees.
-> Use recursion that follows exactly this definition.
-> Every node is visited exactly once.
-> Let H be the height of the tree. The recursion goes as deep as the tree itself, so the extra space is H.
-> For a skewed tree H equals N, and for a balanced tree H is about log N.
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

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int main()
{
    vector<int> values = {3, 9, 20, NO_NODE, NO_NODE, 15, 7};
    TreeNode *root = buildTree(values);

    int answer = maxDepth(root);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
