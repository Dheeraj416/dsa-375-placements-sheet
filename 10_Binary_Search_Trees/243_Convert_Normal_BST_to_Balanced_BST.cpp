/*
QUESTION:-

Given the root of a binary search tree, which may be very unbalanced, convert it
into a height balanced BST that has the same values. A tree is height balanced
if the depths of the two subtrees of every node never differ by more than 1.
Print the new tree in level order. When a part has an even number of values, use
the left one of the two middle values as the root.

Constraints:
1 <= number of nodes <= 10000
1 <= Node.val <= 100000, all values are different

Example 1:

Input:
root = [4,3,null,2,null,1]

Output:
[2,1,3,null,null,null,4]

Example 2:

Input:
root = [1,null,2,null,3]

Output:
[2,1,3]
*/

/*
APPROACH:-

-> The inorder traversal of a BST gives the values in sorted order. Store them in an array.
-> Build a new tree from the sorted array: the middle element becomes the root, so that half of the remaining values go to the left side and half to the right side.
-> Write a recursive function build(left, right): if left > right return null. Take mid = left + (right - left) / 2, make a node with values[mid], set its left child to build(left, mid - 1) and its right child to build(mid + 1, right).
-> Choosing the middle every time keeps the sizes of the left and the right parts almost equal, so the tree is height balanced. For an even number of values, this mid is the left one of the two middle values.
-> Let N be the number of nodes. Collecting the values and building the tree each visit every value once, so the time is N.
-> The array and the new tree take N space.
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

TreeNode *buildBalanced(vector<int> &values, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = left + (right - left) / 2;

    TreeNode *node = new TreeNode(values[mid]);
    node->left = buildBalanced(values, left, mid - 1);
    node->right = buildBalanced(values, mid + 1, right);

    return node;
}

TreeNode *balanceBst(TreeNode *root)
{
    vector<int> values;
    collectInorder(root, values);

    return buildBalanced(values, 0, (int)values.size() - 1);
}

int main()
{
    vector<int> values = {4, 3, NO_NODE, 2, NO_NODE, 1};
    TreeNode *root = buildTree(values);

    TreeNode *balanced = balanceBst(root);

    printTreeLevelOrder(balanced);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
