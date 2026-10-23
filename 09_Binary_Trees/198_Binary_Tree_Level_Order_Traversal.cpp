/*
QUESTION:-

Given the root of a binary tree, return the level order traversal of its
nodes' values (from left to right, level by level).

Constraints:
0 <= number of nodes <= 2000
-1000 <= Node.val <= 1000

Example 1:

Input:
root = [3,9,20,null,null,15,7]

Output:
[[3],[9,20],[15,7]]

Example 2:

Input:
root = [1]

Output:
[[1]]
*/

/*
APPROACH:-

-> Use a queue (breadth first search) and push the root first.
-> In every round, note the current size of the queue. These are exactly the nodes of one level.
-> Take that many nodes out of the queue one by one, store their values in a list for this level, and push their left and right children (if they exist) into the queue.
-> After the round the queue holds only the nodes of the next level.
-> Add the list of the level to the answer and repeat until the queue is empty.
-> Taking the queue size before the round is what separates one level from the next.
-> The queue holds at most one level, which can be up to N nodes in the worst case.
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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> answer;

    if (root == nullptr)
    {
        return answer;
    }

    queue<TreeNode *> pending;
    pending.push(root);

    while (!pending.empty())
    {
        int levelSize = (int)pending.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++)
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

        answer.push_back(level);
    }

    return answer;
}

int main()
{
    vector<int> values = {3, 9, 20, NO_NODE, NO_NODE, 15, 7};
    TreeNode *root = buildTree(values);

    vector<vector<int>> answer = levelOrder(root);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            if (j > 0)
            {
                cout << ",";
            }
            cout << answer[i][j];
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
