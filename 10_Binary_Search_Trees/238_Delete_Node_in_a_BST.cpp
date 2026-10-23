/*
QUESTION:-

Given the root of a binary search tree and a key, delete the node with this key
from the BST and return the root of the updated BST. If the key is not in the
tree, leave the tree as it is.

Constraints:
0 <= number of nodes <= 10000
0 <= Node.val <= 100000, all values are different
0 <= key <= 100000

Example 1:

Input:
root = [5,3,6,2,4,null,7]
key = 3

Output:
[5,4,6,2,null,null,7]

Example 2:

Input:
root = [5,3,6,2,4,null,7]
key = 0

Output:
[5,3,6,2,4,null,7]
(the key does not exist)
*/

/*
APPROACH:-

-> First find the node by moving left when the key is smaller than the node value and right when it is larger. The recursive call returns the new root of that subtree, so the parent can link to it.
-> When the node is found, there are three cases.
-> Case 1: the node has no left child. Then the right child (maybe null) takes its place. Return it.
-> Case 2: the node has no right child. Then the left child takes its place. Return it.
-> Case 3: the node has two children. Find its inorder successor (the smallest node of the right subtree, found by going left as far as possible). Copy the successor's value into this node, and then delete the successor from the right subtree by a recursive call.
-> Let H be the height of the tree. We go down one path (and then another one for the successor), so the time is H.
-> The recursion depth is the height, so the space is H.
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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *rightChild = root->right;
            delete root;
            return rightChild;
        }

        if (root->right == nullptr)
        {
            TreeNode *leftChild = root->left;
            delete root;
            return leftChild;
        }

        TreeNode *successor = root->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }

        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
    }

    return root;
}

int main()
{
    vector<int> values = {5, 3, 6, 2, 4, NO_NODE, 7};
    TreeNode *root = buildTree(values);

    root = deleteNode(root, 3);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(H)
SPACE COMPLEXITY = O(H)
*/
