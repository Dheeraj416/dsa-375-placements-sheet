/*
QUESTION:-

Given the roots of two binary trees p and q, check whether they are the same.
Two binary trees are the same if they have the same structure and the nodes
have the same values.

Constraints:
0 <= number of nodes in each tree <= 100
-10000 <= Node.val <= 10000

Example 1:

Input:
p = [1,2,3], q = [1,2,3]

Output:
true

Example 2:

Input:
p = [1,2], q = [1,null,2]

Output:
false
*/

/*
APPROACH:-

-> Compare the two trees node by node with recursion.
-> If both nodes are null, this part of the trees is identical, so return true.
-> If only one of them is null, the structures differ, so return false.
-> If both exist but their values are different, return false.
-> Otherwise the trees are identical only if the left subtrees are identical and the right subtrees are identical.
-> Let H be the height of the smaller tree. Each pair of nodes is visited once, and the recursion goes at most H levels deep.
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

bool isSameTree(TreeNode *first, TreeNode *second)
{
    if (first == nullptr && second == nullptr)
    {
        return true;
    }

    if (first == nullptr || second == nullptr)
    {
        return false;
    }

    if (first->val != second->val)
    {
        return false;
    }

    return isSameTree(first->left, second->left) && isSameTree(first->right, second->right);
}

int main()
{
    vector<int> firstValues = {1, 2, 3};
    vector<int> secondValues = {1, 2, 3};
    TreeNode *first = buildTree(firstValues);
    TreeNode *second = buildTree(secondValues);

    bool answer = isSameTree(first, second);

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
