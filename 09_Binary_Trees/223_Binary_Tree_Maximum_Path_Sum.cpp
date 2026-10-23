/*
QUESTION:-

A path in a binary tree is a sequence of nodes where each pair of neighbouring
nodes in the sequence has an edge between them. A node can appear in the
sequence at most once, and the path does not need to pass through the root.
The path sum is the sum of the values of the nodes in the path. Given the root
of a binary tree, return the maximum path sum of any non empty path.

Constraints:
1 <= number of nodes <= 30000
-1000 <= Node.val <= 1000 (the value -1 does not appear)

Example 1:

Input:
root = [1,2,3]

Output:
6
(the path 2 -> 1 -> 3)

Example 2:

Input:
root = [-10,9,20,null,null,15,7]

Output:
42
(the path 15 -> 20 -> 7)
*/

/*
APPROACH:-

-> Every path has a highest node (the one closest to the root). The best path with this node as its highest node is: the node value + the best downward path in the left subtree + the best downward path in the right subtree. A downward path that has a negative sum is not taken (use 0 instead).
-> Write a recursive function gain(node) that returns the best sum of a path that starts at this node and goes only downward (to one side). It is node->val + max(0, gain(left), gain(right)), where each gain is replaced by 0 if it is negative.
-> While computing it, update the global best with node->val + leftGain + rightGain, which is the best path having this node as the highest node.
-> The final best is the answer. It starts as the smallest integer, because all the values can be negative.
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

int maxGain(TreeNode *root, int &best)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftGain = max(0, maxGain(root->left, best));
    int rightGain = max(0, maxGain(root->right, best));

    best = max(best, root->val + leftGain + rightGain);

    return root->val + max(leftGain, rightGain);
}

int main()
{
    vector<int> values = {1, 2, 3};
    TreeNode *root = buildTree(values);

    int best = INT_MIN;
    maxGain(root, best);

    cout << best << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
