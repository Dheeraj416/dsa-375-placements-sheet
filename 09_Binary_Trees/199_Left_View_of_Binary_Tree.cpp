/*
QUESTION:-

Given the root of a binary tree, print the left view of the tree. The left view
contains the nodes that are visible when the tree is seen from the left side,
which is the first node of every level.

Constraints:
0 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
root = [20,8,22,5,3,4,25,null,null,10,14]

Output:
[20,8,5,10]

Example 2:

Input:
root = [1,2,3,null,5,null,4]

Output:
[1,2,5]
*/

/*
APPROACH:-

-> Use level order traversal (BFS) with a queue.
-> Process the tree one full level at a time. Before processing a level, note how many nodes it contains (the current queue size).
-> The first node taken out of the queue in each level is the leftmost node of that level, so store its value.
-> Push the left child and then the right child of every node for the next level.
-> The nodes that we store are exactly the ones visible from the left side.
-> The queue holds at most one full level, so the extra space is proportional to the widest level, which is at most N.
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

vector<int> leftView(TreeNode *root)
{
    vector<int> answer;

    if (root == nullptr)
    {
        return answer;
    }

    queue<TreeNode *> pending;
    pending.push(root);

    while (!pending.empty())
    {
        int levelSize = (int)pending.size();

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = pending.front();
            pending.pop();

            if (i == 0)
            {
                answer.push_back(node->val);
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

    return answer;
}

int main()
{
    vector<int> values = {20, 8, 22, 5, 3, 4, 25, NO_NODE, NO_NODE, 10, 14};
    TreeNode *root = buildTree(values);

    vector<int> answer = leftView(root);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
