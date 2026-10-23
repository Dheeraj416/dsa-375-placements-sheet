/*
QUESTION:-

Given a binary search tree that contains only positive integers, check whether
it has a dead end. A dead end is a leaf node x such that no new value can be
inserted below it without breaking the BST rule. This happens when both x - 1
(or the value 0 if x is 1) and x + 1 are already present around it, so nothing
else fits. Return true if the tree contains a dead end, and false otherwise.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000000

Example 1:

Input:
root = [8,5,9,2,7,null,null,1]

Output:
true
(the leaf 1 is a dead end: only the values between 0 and 2 could go below it, and 1 is already used)

Example 2:

Input:
root = [8,5,9,2,7]

Output:
false
*/

/*
APPROACH:-

-> A leaf x can still get a child only if some value strictly between its neighbouring values in sorted order is free. The neighbouring values of a leaf are x - 1 and x + 1 (or 0 and x + 1 when x is 1, since the values are positive).
-> So a leaf x is a dead end exactly when x + 1 is present in the tree and x - 1 is present in the tree (or x == 1, which means 0 is the boundary).
-> Collect all the node values in a set called allNodes and the values of all the leaves in a list called leaves, by one traversal.
-> For each leaf x, check if allNodes contains x + 1 and (x == 1 or allNodes contains x - 1). If so, return true.
-> If no leaf satisfies the condition, return false.
-> Let N be the number of nodes. One traversal and one pass over the leaves cost N, so the time is N.
-> The set and the list take N space.
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

void collectNodes(TreeNode *root, unordered_set<int> &allNodes, vector<int> &leaves)
{
    if (root == nullptr)
    {
        return;
    }

    allNodes.insert(root->val);

    if (root->left == nullptr && root->right == nullptr)
    {
        leaves.push_back(root->val);
    }

    collectNodes(root->left, allNodes, leaves);
    collectNodes(root->right, allNodes, leaves);
}

bool hasDeadEnd(TreeNode *root)
{
    unordered_set<int> allNodes;
    vector<int> leaves;
    collectNodes(root, allNodes, leaves);

    for (int i = 0; i < (int)leaves.size(); i++)
    {
        int x = leaves[i];

        bool lowerBlocked = (x == 1) || (allNodes.count(x - 1) > 0);
        bool upperBlocked = allNodes.count(x + 1) > 0;

        if (lowerBlocked && upperBlocked)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> values = {8, 5, 9, 2, 7, NO_NODE, NO_NODE, 1};
    TreeNode *root = buildTree(values);

    bool answer = hasDeadEnd(root);

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
SPACE COMPLEXITY = O(N)
*/
