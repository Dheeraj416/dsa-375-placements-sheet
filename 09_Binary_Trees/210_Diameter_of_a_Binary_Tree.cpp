/*
QUESTION:-

Given the root of a binary tree, return the length of its diameter. The
diameter is the length of the longest path between any two nodes of the tree.
The path may or may not pass through the root. The length of a path is the
number of edges on it.

Constraints:
1 <= number of nodes <= 10000
-100 <= Node.val <= 100

Example 1:

Input:
root = [1,2,3,4,5]

Output:
3
Explanation: The longest path is 4 -> 2 -> 1 -> 3 (or 5 -> 2 -> 1 -> 3), which has 3 edges.

Example 2:

Input:
root = [1,2]

Output:
1
*/

/*
APPROACH:-

-> For every node, the longest path that passes through it as the highest point is (height of its left subtree) + (height of its right subtree), measured in edges.
-> The diameter is the maximum of this value over all the nodes.
-> Use one recursive function that returns the height of a subtree (the number of nodes on the longest downward path), and at the same time updates a variable diameter.
-> At each node, compute leftHeight and rightHeight recursively, update diameter = max(diameter, leftHeight + rightHeight), and return 1 + max(leftHeight, rightHeight).
-> This visits every node once. Computing the height separately for every node would take O(N^2), so combining both in one pass is important.
-> Let H be the height of the tree. The recursion goes H levels deep.
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

int computeHeight(TreeNode *node, int &diameter)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftHeight = computeHeight(node->left, diameter);
    int rightHeight = computeHeight(node->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;

    computeHeight(root, diameter);

    return diameter;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(values);

    int answer = diameterOfBinaryTree(root);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
