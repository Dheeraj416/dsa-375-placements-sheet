/*
QUESTION:-

Given the root of a binary tree, imagine yourself standing on the right side of
it. Return the values of the nodes you can see, ordered from top to bottom.

Constraints:
0 <= number of nodes <= 100
0 <= Node.val <= 100

Example 1:

Input:
root = [1,2,3,null,5,null,4]

Output:
[1,3,4]

Example 2:

Input:
root = [1,null,3]

Output:
[1,3]
*/

/*
APPROACH:-

-> From the right side, you see the rightmost node of every level. Nodes of the same level that are more to the left are hidden.
-> Do a level order traversal with a queue. For each level, take the number of nodes currently in the queue and process exactly that many.
-> While processing the level, the last node taken from the queue is the rightmost node. When i == size - 1, add the value of the node to the answer.
-> Push the left child first and then the right child for every node, so the nodes of a level stay ordered from left to right.
-> Let N be the number of nodes. Every node is visited once, so the time is N.
-> The queue can hold a whole level, which is at most N nodes, so the space is N.
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

vector<int> rightView(TreeNode *root)
{
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

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = pending.front();
            pending.pop();

            if (i == size - 1)
            {
                result.push_back(node->val);
            }

            if (node->left != nullptr)
            {
                pending.push(node->left);
            }
            if (node->right != nullptr)
            {
                pending.push(node->right);
            }
        }
    }

    return result;
}

int main()
{
    vector<int> values = {1, 2, 3, NO_NODE, 5, NO_NODE, 4};
    TreeNode *root = buildTree(values);

    vector<int> answer = rightView(root);

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
