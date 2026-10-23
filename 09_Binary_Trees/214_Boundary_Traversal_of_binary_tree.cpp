/*
QUESTION:-

Given the root of a binary tree, print its boundary nodes in anti-clockwise
order, starting from the root. The boundary consists of: the root, the left
boundary (the nodes on the path from the root to the leftmost leaf, excluding
the leaves), all the leaf nodes from left to right, and the right boundary (the
nodes on the path from the root to the rightmost leaf, excluding the leaves)
printed in bottom to top order. A node must be printed only once.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
root = [20,8,22,4,12,null,25,null,null,10,14]

Output:
[20,8,4,10,14,25,22]

Example 2:

Input:
root = [1,2,3,4,5,6,7]

Output:
[1,2,4,5,6,7,3]
*/

/*
APPROACH:-

-> Build the answer in four parts: root, left boundary, leaves, right boundary.
-> Root: add it first, but only if it is not a leaf (a leaf root is added later with the leaves).
-> Left boundary: start from the left child of the root and keep going down. Take the left child when it exists, otherwise the right child. Add each node that is not a leaf.
-> Leaves: do a recursive traversal from the root, left subtree before right subtree, and add every leaf.
-> Right boundary: start from the right child of the root and go down, taking the right child when it exists, otherwise the left child. Collect the non-leaf nodes in a temporary list and add them to the answer in reverse order.
-> Leaves are excluded from both boundaries, so no node appears twice.
-> Let H be the height of the tree. The recursion for leaves and the temporary list for the right boundary use H space.
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

bool isLeaf(TreeNode *node)
{
    return node->left == nullptr && node->right == nullptr;
}

void addLeftBoundary(TreeNode *root, vector<int> &answer)
{
    TreeNode *current = root->left;

    while (current != nullptr)
    {
        if (!isLeaf(current))
        {
            answer.push_back(current->val);
        }

        if (current->left != nullptr)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}

void addLeaves(TreeNode *node, vector<int> &answer)
{
    if (node == nullptr)
    {
        return;
    }

    if (isLeaf(node))
    {
        answer.push_back(node->val);
        return;
    }

    addLeaves(node->left, answer);
    addLeaves(node->right, answer);
}

void addRightBoundary(TreeNode *root, vector<int> &answer)
{
    vector<int> temporary;
    TreeNode *current = root->right;

    while (current != nullptr)
    {
        if (!isLeaf(current))
        {
            temporary.push_back(current->val);
        }

        if (current->right != nullptr)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    for (int i = (int)temporary.size() - 1; i >= 0; i--)
    {
        answer.push_back(temporary[i]);
    }
}

vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> answer;

    if (root == nullptr)
    {
        return answer;
    }

    if (!isLeaf(root))
    {
        answer.push_back(root->val);
    }

    addLeftBoundary(root, answer);
    addLeaves(root, answer);
    addRightBoundary(root, answer);

    return answer;
}

int main()
{
    vector<int> values = {20, 8, 22, 4, 12, NO_NODE, 25, NO_NODE, NO_NODE, 10, 14};
    TreeNode *root = buildTree(values);

    vector<int> answer = boundaryTraversal(root);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
