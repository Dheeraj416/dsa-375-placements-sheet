/*
QUESTION:-

Given the root of a binary tree, check if all the leaf nodes are at the same
level (the same depth from the root). A leaf is a node without children. Return
true if they are, and false otherwise.

Constraints:
0 <= number of nodes <= 100000
0 <= Node.val <= 100000

Example 1:

Input:
root = [12,5,7,3,null,null,1]

Output:
true
(both the leaves 3 and 1 are at level 2)

Example 2:

Input:
root = [1,2,3,4]

Output:
false
(the leaf 3 is at level 1 and the leaf 4 is at level 2)
*/

/*
APPROACH:-

-> Traverse the tree with recursion and carry the current level of the node (the root is at level 0).
-> Keep a variable leafLevel, which is -1 until the first leaf is found. The level of the first leaf is stored in it.
-> At every later leaf, compare its level with leafLevel. If they are different, return false.
-> For a node that is not a leaf, both subtrees must return true. An empty node returns true, because it has no leaf.
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

bool checkLeaves(TreeNode *root, int level, int &leafLevel)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        if (leafLevel == -1)
        {
            leafLevel = level;
            return true;
        }
        return leafLevel == level;
    }

    return checkLeaves(root->left, level + 1, leafLevel) && checkLeaves(root->right, level + 1, leafLevel);
}

int main()
{
    vector<int> values = {12, 5, 7, 3, NO_NODE, NO_NODE, 1};
    TreeNode *root = buildTree(values);

    int leafLevel = -1;
    bool answer = checkLeaves(root, 0, leafLevel);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
