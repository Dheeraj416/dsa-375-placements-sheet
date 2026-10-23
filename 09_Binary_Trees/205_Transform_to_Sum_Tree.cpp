/*
QUESTION:-

Given the root of a binary tree, convert it into a sum tree. In a sum tree, the
value of every node is equal to the sum of the values of the nodes in its left
subtree and in its right subtree in the original tree. The value of a leaf node
becomes 0. Change the tree in place and print it.

Constraints:
1 <= number of nodes <= 10000
-1000 <= Node.val <= 1000 (the value -1 does not appear)

Example 1:

Input:
root = [10,-2,6,8,-4,7,5]

Output:
[20,4,12,0,0,0,0]

Example 2:

Input:
root = [1,2,3]

Output:
[5,0,0]
*/

/*
APPROACH:-

-> Write a recursive function that changes the subtree of a node and returns the sum of the ORIGINAL values of that whole subtree.
-> For an empty node return 0.
-> For other nodes: remember the old value of the node, then call the function on the left child and on the right child. They return the original sums of the left and right subtrees.
-> Set the new value of the node to leftSum + rightSum. A leaf gets 0 + 0 = 0.
-> Return oldValue + leftSum + rightSum, which is the original sum of this subtree, so that the parent can use it.
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

int toSumTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int oldValue = root->val;
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    root->val = leftSum + rightSum;

    return oldValue + leftSum + rightSum;
}

int main()
{
    vector<int> values = {10, -2, 6, 8, -4, 7, 5};
    TreeNode *root = buildTree(values);

    toSumTree(root);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
