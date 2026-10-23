/*
QUESTION:-

Given the root of a binary tree, print the top view of the tree. Give every node
a horizontal distance: the root has 0, a left child has the distance of its
parent minus 1 and a right child has the distance of its parent plus 1. The top
view contains, for every horizontal distance, the top most node (the node that
is closest to the root). Print the nodes from the smallest to the largest
horizontal distance.

Constraints:
0 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
root = [20,8,22,5,3,4,25,null,null,10,14]

Output:
[5,8,20,22,25]

Example 2:

Input:
root = [1,2,3]

Output:
[2,1,3]
*/

/*
APPROACH:-

-> Do a level order traversal (BFS) and store the horizontal distance of every node together with the node in the queue.
-> Keep an ordered map from horizontal distance to node value.
-> When a node is taken from the queue, add its value to the map only if its distance is not in the map yet.
-> BFS visits the upper levels first, so the first node that reaches a distance is the top most node with that distance.
-> The left child goes with distance - 1 and the right child goes with distance + 1.
-> At the end, read the map from the smallest distance to the largest. The map keeps its keys sorted.
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

vector<int> topView(TreeNode *root)
{
    vector<int> answer;

    if (root == nullptr)
    {
        return answer;
    }

    map<int, int> topNodeAt;
    queue<pair<TreeNode *, int>> pending;
    pending.push({root, 0});

    while (!pending.empty())
    {
        TreeNode *node = pending.front().first;
        int distance = pending.front().second;
        pending.pop();

        if (topNodeAt.find(distance) == topNodeAt.end())
        {
            topNodeAt[distance] = node->val;
        }

        if (node->left != nullptr)
        {
            pending.push({node->left, distance - 1});
        }

        if (node->right != nullptr)
        {
            pending.push({node->right, distance + 1});
        }
    }

    for (map<int, int>::iterator it = topNodeAt.begin(); it != topNodeAt.end(); ++it)
    {
        answer.push_back(it->second);
    }

    return answer;
}

int main()
{
    vector<int> values = {20, 8, 22, 5, 3, 4, 25, NO_NODE, NO_NODE, 10, 14};
    TreeNode *root = buildTree(values);

    vector<int> answer = topView(root);

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
