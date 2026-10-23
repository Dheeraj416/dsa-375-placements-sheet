/*
QUESTION:-

Given the root of a binary search tree and two numbers l and r (l <= r), count
the nodes whose values are in the range [l, r], both ends included.

Constraints:
0 <= number of nodes <= 100000
1 <= Node.val <= 1000000
1 <= l <= r <= 1000000

Example 1:

Input:
root = [10,5,50,1,null,40,100]
l = 5, r = 45

Output:
3
(the nodes 5, 10 and 40)

Example 2:

Input:
root = [10,5,50,1,null,40,100]
l = 1, r = 100

Output:
6
(all the nodes)
*/

/*
APPROACH:-

-> Use the BST property to skip the parts of the tree that cannot contain any value of the range.
-> If the node is empty, return 0.
-> If the node's value is smaller than l, the node and its whole left subtree are too small, so only the right subtree can have answers.
-> If the node's value is bigger than r, the node and its whole right subtree are too big, so only the left subtree can have answers.
-> Otherwise the node is in the range: count 1 for it, and add the counts of the left and the right subtrees.
-> Let N be the number of nodes. In the worst case (the range covers everything) every node is visited, so the time is N.
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

int countInRange(TreeNode *root, int l, int r)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root->val < l)
    {
        return countInRange(root->right, l, r);
    }

    if (root->val > r)
    {
        return countInRange(root->left, l, r);
    }

    return 1 + countInRange(root->left, l, r) + countInRange(root->right, l, r);
}

int main()
{
    vector<int> values = {10, 5, 50, 1, NO_NODE, 40, 100};
    TreeNode *root = buildTree(values);

    cout << countInRange(root, 5, 45) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
