/*
QUESTION:-

Given the root of a binary tree, find the size (the number of nodes) of the
largest subtree of it that is a binary search tree. A subtree is a node with all
of its descendants.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000, all values are different

Example 1:

Input:
root = [50,30,60,5,20,45,70,null,null,null,null,null,null,65,80]

Output:
5
(the subtree rooted at 60 with the nodes 60, 45, 70, 65, 80)

Example 2:

Input:
root = [5,2,4,1,3]

Output:
3
(the subtree rooted at 2 with the nodes 2, 1, 3)
*/

/*
APPROACH:-

-> A tree is a BST if its left subtree is a BST, its right subtree is a BST, the largest value of the left subtree is smaller than the node, and the smallest value of the right subtree is larger than the node.
-> So for each node we need five facts about its subtree: whether it is a BST, its size, its minimum value, its maximum value, and the size of the largest BST found inside it.
-> Compute these facts bottom up (postorder). For an empty subtree: it is a BST of size 0, with minimum = a huge value and maximum = a tiny value, so that it never breaks the conditions.
-> If both children are BSTs and left.max < node value < right.min, this subtree is a BST: its size is left.size + right.size + 1, its minimum is min(left.min, value), its maximum is max(right.max, value), and its best is its size.
-> Otherwise the subtree is not a BST, and its best is the larger of the two children's best values.
-> Let N be the number of nodes. Each node is processed once, so the time is N.
-> The recursion depth is the height of the tree, so the space is H where H is the height.
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

struct Info
{
    bool isBst;
    int size;
    int minValue;
    int maxValue;
    int best;
};

Info largestBst(TreeNode *root)
{
    Info result;

    if (root == nullptr)
    {
        result.isBst = true;
        result.size = 0;
        result.minValue = INT_MAX;
        result.maxValue = INT_MIN;
        result.best = 0;
        return result;
    }

    Info left = largestBst(root->left);
    Info right = largestBst(root->right);

    if (left.isBst && right.isBst && left.maxValue < root->val && root->val < right.minValue)
    {
        result.isBst = true;
        result.size = left.size + right.size + 1;
        result.minValue = min(left.minValue, root->val);
        result.maxValue = max(right.maxValue, root->val);
        result.best = result.size;
    }
    else
    {
        result.isBst = false;
        result.size = 0;
        result.minValue = 0;
        result.maxValue = 0;
        result.best = max(left.best, right.best);
    }

    return result;
}

int main()
{
    vector<int> values = {50, 30, 60, 5, 20, 45, 70, NO_NODE, NO_NODE, NO_NODE, NO_NODE, NO_NODE, NO_NODE, 65, 80};
    TreeNode *root = buildTree(values);

    Info answer = largestBst(root);

    cout << answer.best << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
