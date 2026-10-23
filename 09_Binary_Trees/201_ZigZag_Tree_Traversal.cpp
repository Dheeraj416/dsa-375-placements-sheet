/*
QUESTION:-

Given the root of a binary tree, return the zigzag level order traversal of its
nodes. The first level is traversed from left to right, the second level from
right to left, the third level from left to right again, and so on.

Constraints:
0 <= number of nodes <= 2000
-100 <= Node.val <= 100

Example 1:

Input:
root = [1,2,3,4,5,6,7]

Output:
1 3 2 4 5 6 7

Example 2:

Input:
root = [3,9,20,null,null,15,7]

Output:
3 20 9 15 7
*/

/*
APPROACH:-

-> Do a normal level order traversal with a queue, and collect the values of one level at a time in the list called level (always from left to right).
-> Keep a flag leftToRight which is true for the first level.
-> After a level is collected, if the flag is false, reverse the list level. Then add it to the answer.
-> Flip the flag before starting the next level.
-> Let N be the number of nodes. Every node is visited once and reversed at most once, so the time is N.
-> The queue holds at most one level (up to N nodes), so the space is N.
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

vector<int> zigzagTraversal(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> pending;
    pending.push(root);
    bool leftToRight = true;

    while (!pending.empty())
    {
        int size = pending.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = pending.front();
            pending.pop();
            level.push_back(node->val);

            if (node->left != nullptr)
            {
                pending.push(node->left);
            }
            if (node->right != nullptr)
            {
                pending.push(node->right);
            }
        }

        if (!leftToRight)
        {
            reverse(level.begin(), level.end());
        }

        for (int i = 0; i < (int)level.size(); i++)
        {
            result.push_back(level[i]);
        }

        leftToRight = !leftToRight;
    }

    return result;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildTree(values);

    vector<int> answer = zigzagTraversal(root);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
