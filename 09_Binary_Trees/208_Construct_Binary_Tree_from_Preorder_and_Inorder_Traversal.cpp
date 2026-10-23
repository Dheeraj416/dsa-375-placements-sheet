/*
QUESTION:-

Given two integer arrays preorder and inorder, where preorder is the preorder
traversal of a binary tree and inorder is the inorder traversal of the same
tree, construct and return the binary tree. All the values are unique. The tree
is printed in level order, with null for the missing children.

Constraints:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
All the values are unique.

Example 1:

Input:
preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

Output:
[3,9,20,null,null,15,7]

Example 2:

Input:
preorder = [-1], inorder = [-1]

Output:
[-1]
*/

/*
APPROACH:-

-> The first element of the preorder range is always the root of the (sub)tree.
-> Find the root in the inorder array. Everything to its left in inorder belongs to the left subtree and everything to its right belongs to the right subtree.
-> The size of the left subtree is (root position - inorder start). Use it to split the preorder range: the next leftSize elements are the left subtree and the rest are the right subtree.
-> Recursively build the left subtree and the right subtree from their ranges.
-> Store the position of every value of inorder in a hash map before starting, so finding the root takes O(1) instead of O(N).
-> The recursion stops when a range is empty.
-> Every node is created once, so the time is O(N). The map and the recursion need O(N) space.
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

TreeNode *buildFromRanges(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inorderIndex)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[preStart]);
    int rootIndex = inorderIndex[root->val];
    int leftSize = rootIndex - inStart;

    root->left = buildFromRanges(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1, inorderIndex);
    root->right = buildFromRanges(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderIndex);

    return root;
}

TreeNode *buildTreeFromPreIn(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inorderIndex;

    for (int i = 0; i < (int)inorder.size(); i++)
    {
        inorderIndex[inorder[i]] = i;
    }

    return buildFromRanges(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1, inorderIndex);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTreeFromPreIn(preorder, inorder);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
