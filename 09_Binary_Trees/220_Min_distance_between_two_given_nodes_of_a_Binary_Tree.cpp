/*
QUESTION:-

Given the root of a binary tree with distinct values and two values a and b
that exist in the tree, find the minimum distance between the nodes with these
values. The distance is the number of edges on the path between the two nodes.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000, all values are different

Example 1:

Input:
root = [1,2,3,4,5,6,7]
a = 4, b = 6

Output:
4
(the path is 4 -> 2 -> 1 -> 3 -> 6)

Example 2:

Input:
root = [1,2,3,4,5,6,7]
a = 4, b = 5

Output:
2
(the path is 4 -> 2 -> 5)
*/

/*
APPROACH:-

-> The shortest path between two nodes goes up to their lowest common ancestor (LCA) and then down. So the distance is (depth of a below the LCA) + (depth of b below the LCA).
-> Find the LCA: if the root is empty or equal to a or b, return the root. Search both subtrees. If both return a node, the root is the LCA. Otherwise return whichever subtree returned a node.
-> Then write a helper that finds the depth of a value below a given node (0 for the node itself, -1 if the value is not found).
-> The answer is depth(lca, a) + depth(lca, b).
-> Let N be the number of nodes. Finding the LCA and the two depths each visit every node at most once, so the time is N.
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

TreeNode *findLca(TreeNode *root, int a, int b)
{
    if (root == nullptr || root->val == a || root->val == b)
    {
        return root;
    }

    TreeNode *left = findLca(root->left, a, b);
    TreeNode *right = findLca(root->right, a, b);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    if (left != nullptr)
    {
        return left;
    }

    return right;
}

int depthOf(TreeNode *root, int target, int depth)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->val == target)
    {
        return depth;
    }

    int left = depthOf(root->left, target, depth + 1);
    if (left != -1)
    {
        return left;
    }

    return depthOf(root->right, target, depth + 1);
}

int minDistance(TreeNode *root, int a, int b)
{
    TreeNode *lca = findLca(root, a, b);

    return depthOf(lca, a, 0) + depthOf(lca, b, 0);
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildTree(values);

    cout << minDistance(root, 4, 6) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
