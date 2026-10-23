/*
QUESTION:-

Given the root of a binary tree, create a new binary tree which is the mirror
image of the given tree, and return the root of the new tree. The given tree
must not be changed.

Constraints:
0 <= number of nodes <= 10000
0 <= Node.val <= 100000

Example 1:

Input:
root = [1,2,3,4,5]

Output:
[1,3,2,null,null,5,4]

Example 2:

Input:
root = [1,2]

Output:
[1,null,2]
*/

/*
APPROACH:-

-> The mirror image of a tree has the same root value, and its left subtree is the mirror of the original right subtree, and its right subtree is the mirror of the original left subtree.
-> If the node is empty, return null.
-> Otherwise create a new node with the same value. Set its left child to the mirror of root->right and its right child to the mirror of root->left, both found by recursion.
-> The original tree is only read, so it is not changed.
-> Let N be the number of nodes. Each node is visited once and one new node is made for it, so the time is N.
-> The new tree takes N space (the recursion stack of height H is smaller than that).
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

void printTreeLevelOrder(TreeNode *root)
{
    vector<string> parts;
    queue<TreeNode *> pending;
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode *node = pending.front();
        pending.pop();

        if (node == nullptr)
        {
            parts.push_back("null");
            continue;
        }

        parts.push_back(to_string(node->val));
        pending.push(node->left);
        pending.push(node->right);
    }

    while (!parts.empty() && parts.back() == "null")
    {
        parts.pop_back();
    }

    cout << "[";
    for (int i = 0; i < (int)parts.size(); i++)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << parts[i];
    }
    cout << "]\n";
}

TreeNode *createMirror(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode(root->val);
    node->left = createMirror(root->right);
    node->right = createMirror(root->left);

    return node;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(values);

    TreeNode *mirror = createMirror(root);

    printTreeLevelOrder(mirror);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
