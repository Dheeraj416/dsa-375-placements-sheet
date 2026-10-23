/*
QUESTION:-

Given the root of a binary tree with distinct values, convert it into a binary
search tree without changing its structure (the shape of the tree stays the
same, only the values of the nodes are moved around). Print the converted tree
in level order.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000, all values are different

Example 1:

Input:
root = [10,2,7,8,4]

Output:
[8,4,10,2,7]

Example 2:

Input:
root = [1,2,3]

Output:
[2,1,3]
*/

/*
APPROACH:-

-> The inorder traversal of a BST is sorted. So if we keep the shape of the tree and put the values in sorted order along the inorder traversal of that shape, we get a BST.
-> Step 1: do an inorder traversal of the binary tree and collect all the values in an array.
-> Step 2: sort the array.
-> Step 3: do the inorder traversal again, and this time overwrite the value of every visited node with the next value from the sorted array.
-> The shape is not changed, and the inorder traversal now reads the sorted values, so the tree is a BST.
-> Let N be the number of nodes. Sorting costs N * log N and the traversals cost N, so the time is N * log N.
-> The array takes N space.
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

void collectInorder(TreeNode *root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    collectInorder(root->left, values);
    values.push_back(root->val);
    collectInorder(root->right, values);
}

void fillInorder(TreeNode *root, vector<int> &values, int &index)
{
    if (root == nullptr)
    {
        return;
    }

    fillInorder(root->left, values, index);
    root->val = values[index];
    index++;
    fillInorder(root->right, values, index);
}

void binaryTreeToBst(TreeNode *root)
{
    vector<int> values;
    collectInorder(root, values);

    sort(values.begin(), values.end());

    int index = 0;
    fillInorder(root, values, index);
}

int main()
{
    vector<int> values = {10, 2, 7, 8, 4};
    TreeNode *root = buildTree(values);

    binaryTreeToBst(root);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
