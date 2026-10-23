/*
QUESTION:-

Given the root of a binary tree, print the bottom view of the tree. Give every
node a horizontal distance: the root has 0, a left child has the distance of
its parent minus 1 and a right child has the distance of its parent plus 1. The
bottom view contains, for every horizontal distance, the bottom most node (the
node that is lowest in the tree; if two nodes are at the same height, the one
that comes later in the level order is taken). Print the nodes from the
smallest to the largest horizontal distance.

Constraints:
0 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
root = [20,8,22,5,3,4,25,null,null,10,14]

Output:
[5,10,4,14,25]

Example 2:

Input:
root = [1,2,3]

Output:
[2,1,3]
*/

/*
APPROACH:-

-> Do a level order traversal (BFS) and carry the horizontal distance of every node in the queue, as a pair of node and distance.
-> Keep an ordered map from horizontal distance to node value.
-> Every time a node is taken from the queue, overwrite the map entry of its distance with this node.
-> Because BFS visits the upper levels first, the last node written for a distance is the bottom most node with that distance.
-> The left child goes with distance - 1 and the right child goes with distance + 1.
-> At the end, read the map from the smallest distance to the largest one. A map keeps its keys sorted, so no extra sorting is needed.
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

vector<int> bottomView(TreeNode *root)
{
    vector<int> answer;

    if (root == nullptr)
    {
        return answer;
    }

    map<int, int> bottomNodeAt;
    queue<pair<TreeNode *, int>> pending;
    pending.push({root, 0});

    while (!pending.empty())
    {
        TreeNode *node = pending.front().first;
        int distance = pending.front().second;
        pending.pop();

        bottomNodeAt[distance] = node->val;

        if (node->left != nullptr)
        {
            pending.push({node->left, distance - 1});
        }

        if (node->right != nullptr)
        {
            pending.push({node->right, distance + 1});
        }
    }

    for (map<int, int>::iterator it = bottomNodeAt.begin(); it != bottomNodeAt.end(); ++it)
    {
        answer.push_back(it->second);
    }

    return answer;
}

int main()
{
    vector<int> values = {20, 8, 22, 5, 3, 4, 25, NO_NODE, NO_NODE, 10, 14};
    TreeNode *root = buildTree(values);

    vector<int> answer = bottomView(root);

    for (int x : answer)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
