/*
QUESTION:-

Given the root of a binary tree with distinct values, a node value and a number
k, find the k-th ancestor of the node. The first ancestor is the parent, the
second ancestor is the parent of the parent, and so on. If the node does not
have a k-th ancestor, return -1.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000, all values are different
1 <= k <= number of nodes

Example 1:

Input:
root = [1,2,3,4,5]
node = 5, k = 1

Output:
2

Example 2:

Input:
root = [1,2,3,4,5]
node = 5, k = 3

Output:
-1
(the node 5 has only two ancestors: 2 and 1)
*/

/*
APPROACH:-

-> Search for the node with recursion. The function returns true if the node was found in the subtree of the current root.
-> If the current root is the node itself, return true. The ancestors are found while coming back from the recursion.
-> For other roots: search the left subtree, and if it was not found there, search the right subtree.
-> If the node was found below the current root, then this root is one more ancestor on the way up. Decrease k by 1. When k becomes exactly 0, the current root is the k-th ancestor, so store its value in answer.
-> The answer starts as -1, so if the root is passed before k becomes 0, -1 stays.
-> Let N be the number of nodes. Each node is visited once, so the time is N.
-> The recursion depth is the height of the tree, so the space is H where H is the height of the tree.
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

bool findAncestor(TreeNode *root, int node, int &k, int &answer)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == node)
    {
        return true;
    }

    bool found = findAncestor(root->left, node, k, answer) || findAncestor(root->right, node, k, answer);

    if (found)
    {
        k--;
        if (k == 0)
        {
            answer = root->val;
        }
    }

    return found;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(values);

    int k = 1;
    int answer = -1;
    findAncestor(root, 5, k, answer);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
