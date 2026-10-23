/*
QUESTION:-

Given the root of a binary search tree, find the minimum value in it. If the
tree is empty, return -1.

Constraints:
0 <= number of nodes <= 100000
1 <= Node.val <= 1000000

Example 1:

Input:
root = [5,4,6,3,null,null,7,1]

Output:
1

Example 2:

Input:
root = [9]

Output:
9
*/

/*
APPROACH:-

-> In a BST every value in the left subtree of a node is smaller than the node. So the smallest value is in the leftmost node.
-> If the tree is empty, return -1.
-> Otherwise start at the root and keep moving to the left child while there is one. The node where we stop (it has no left child) holds the minimum.
-> Let H be the height of the tree. We follow one path, so the time is H.
-> Only a pointer is used, so the space is constant.
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

int findMinimum(TreeNode *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    TreeNode *current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }

    return current->val;
}

int main()
{
    vector<int> values = {5, 4, 6, 3, NO_NODE, NO_NODE, 7, 1};
    TreeNode *root = buildTree(values);

    cout << findMinimum(root) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(H)
SPACE COMPLEXITY = O(1)
*/
