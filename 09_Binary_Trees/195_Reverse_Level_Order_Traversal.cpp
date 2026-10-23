/*
QUESTION:-

Given the root of a binary tree, print its nodes level by level from the bottom
level up to the root. Inside every level, the nodes are printed from left to
right.

Constraints:
0 <= number of nodes <= 10000
0 <= Node.val <= 100000

Example 1:

Input:
root = [1,2,3,4,5]

Output:
4 5 2 3 1

Example 2:

Input:
root = [1,2,null,3]

Output:
3 2 1
*/

/*
APPROACH:-

-> Do a normal level order traversal (BFS) with a queue, and store every level as a separate list of values.
-> For each level, take the number of nodes currently in the queue, remove exactly that many nodes, record their values from left to right, and push their children.
-> After the traversal we have all the levels from the top to the bottom.
-> Print the levels in the opposite order: start from the last level and finish with the root level. The order inside a level stays left to right.
-> Let N be the number of nodes. Every node is visited once, so the time is N.
-> The queue and the stored levels take N space.
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

vector<int> reverseLevelOrder(TreeNode *root)
{
    vector<vector<int>> levels;
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    queue<TreeNode *> pending;
    pending.push(root);

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

        levels.push_back(level);
    }

    for (int i = (int)levels.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < (int)levels[i].size(); j++)
        {
            result.push_back(levels[i][j]);
        }
    }

    return result;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(values);

    vector<int> answer = reverseLevelOrder(root);

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
