/*
QUESTION:-

Given the root of a binary tree, invert the tree (swap the left and the right
child of every node) and return its root.

Constraints:
0 <= number of nodes <= 100
-100 <= Node.val <= 100

Example 1:

Input:
root = [4,2,7,1,3,6,9]

Output:
[4,7,2,9,6,3,1]

Example 2:

Input:
root = [2,1,3]

Output:
[2,3,1]
*/

/*
APPROACH:-

-> Inverting a tree means that every node has its two children swapped. The children themselves are inverted too.
-> If the node is empty, return. Otherwise swap root->left and root->right, then invert the left subtree and the right subtree by recursion.
-> The swap does not depend on the order, so the swap can be done before or after the recursive calls.
-> Let N be the number of nodes. Each node is visited once, so the time is N.
-> The recursion goes as deep as the height of the tree, so the space is H where H is the height of the tree.
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

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main()
{
    vector<int> values = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *root = buildTree(values);

    root = invertTree(root);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
