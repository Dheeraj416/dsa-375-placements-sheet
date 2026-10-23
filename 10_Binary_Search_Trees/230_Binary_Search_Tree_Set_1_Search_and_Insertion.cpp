/*
QUESTION:-

Implement the two basic operations of a binary search tree (BST): insert(key),
which adds a new key to the tree (a key that already exists is ignored), and
search(key), which tells whether a key is present in the tree. In a BST every
key in the left subtree of a node is smaller than the node, and every key in the
right subtree is larger. Insert the given keys one by one into an empty BST,
print the inorder traversal of the tree, and then answer the search queries.

Constraints:
1 <= number of keys <= 100000
1 <= key <= 1000000

Example 1:

Input:
keys = [50,30,20,40,70,60,80]
search(60), search(25)

Output:
20 30 40 50 60 70 80
true
false

Example 2:

Input:
keys = [5,3,8,3]
search(3), search(9)

Output:
3 5 8
true
false
*/

/*
APPROACH:-

-> Insert: if the tree (or subtree) is empty, create a new node and return it. If the key is smaller than the node's value, the new key belongs to the left subtree, so set node->left = insert(node->left, key). If it is larger, do the same on the right. If it is equal, do nothing.
-> Search: if the node is empty, the key is not present. If the key equals the node's value, it is present. Otherwise go to the left subtree when the key is smaller and to the right subtree when it is larger.
-> Each step discards one whole subtree, so we only follow one path from the root down.
-> The inorder traversal (left, node, right) of a BST gives the keys in sorted order.
-> Let H be the height of the tree. Insert and search each take H steps. For a balanced tree H is about log N, and for a skewed tree H is N, where N is the number of keys.
-> The recursion goes as deep as the height of the tree, so the space is H.
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

TreeNode *insertNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return new TreeNode(key);
    }

    if (key < root->val)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = insertNode(root->right, key);
    }

    return root;
}

bool searchNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->val == key)
    {
        return true;
    }

    if (key < root->val)
    {
        return searchNode(root->left, key);
    }

    return searchNode(root->right, key);
}

void printInorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printBool(bool value)
{
    if (value)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
}

int main()
{
    vector<int> keys = {50, 30, 20, 40, 70, 60, 80};
    TreeNode *root = nullptr;

    for (int i = 0; i < (int)keys.size(); i++)
    {
        root = insertNode(root, keys[i]);
    }

    printInorder(root);
    cout << "\n";

    printBool(searchNode(root, 60));
    printBool(searchNode(root, 25));

    return 0;
}

/*
TIME COMPLEXITY = O(H)
SPACE COMPLEXITY = O(H)
*/
