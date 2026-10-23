/*
QUESTION:-

Given the root of a binary tree, check whether it is a valid binary search tree.
In a valid BST, the left subtree of a node contains only values strictly smaller
than the node, the right subtree contains only values strictly larger than the
node, and both subtrees are valid BSTs too.

Constraints:
1 <= number of nodes <= 10000
-2147483648 <= Node.val <= 2147483647 (the value -1 does not appear)

Example 1:

Input:
root = [2,1,3]

Output:
true

Example 2:

Input:
root = [5,1,4,null,null,3,6]

Output:
false
(the node 4 is in the right subtree of 5 but it is smaller than 5)
*/

/*
APPROACH:-

-> Checking only the children of every node is not enough: a value deep in the right subtree must still be larger than the root. So every node must be inside a range of allowed values (low, high), both ends excluded.
-> The root can have any value, so start with the range (minus infinity, plus infinity). Use long long for the bounds, because the node values can be equal to the int limits.
-> For a node, if its value is not strictly between low and high, return false.
-> The left child must be in the range (low, node value) and the right child in the range (node value, high). Check both by recursion.
-> An empty tree is a valid BST.
-> Let N be the number of nodes. Each node is visited once, so the time is N.
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

bool isValid(TreeNode *root, long long low, long long high)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->val <= low || root->val >= high)
    {
        return false;
    }

    return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
}

int main()
{
    vector<int> values = {2, 1, 3};
    TreeNode *root = buildTree(values);

    bool answer = isValid(root, LLONG_MIN, LLONG_MAX);

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
