/*
QUESTION:-

Given an array of integers preorder, which represents the preorder traversal of
a binary search tree (BST) with unique values, construct the tree and return
its root. The tree is printed in level order, with null for the missing
children.

Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 1000 and all the values are unique

Example 1:

Input:
preorder = [8,5,1,7,10,12]

Output:
[8,5,10,1,7,null,12]

Example 2:

Input:
preorder = [1,3]

Output:
[1,null,3]
*/

/*
APPROACH:-

-> The first element of a preorder traversal is the root. Elements that follow and are smaller than it belong to the left subtree, and larger elements belong to the right subtree.
-> Use recursion with an upper bound. The function builds a subtree from the next elements of the array as long as they are smaller than the bound.
-> For a new root, take the element at the shared index and move the index forward.
-> Build its left subtree with the bound equal to the root value, and then build its right subtree with the bound inherited from the parent.
-> If the index is at the end of the array, or the next element is larger than the bound, it belongs to some ancestor, so return null.
-> The index only moves forward, so each element is used once, which gives O(N) instead of the O(N^2) of searching for the split point each time.
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

TreeNode *buildFromPreorder(vector<int> &preorder, int &index, int upperBound)
{
    if (index == (int)preorder.size() || preorder[index] > upperBound)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[index]);
    index++;

    root->left = buildFromPreorder(preorder, index, root->val);
    root->right = buildFromPreorder(preorder, index, upperBound);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;

    return buildFromPreorder(preorder, index, INT_MAX);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *root = bstFromPreorder(preorder);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
