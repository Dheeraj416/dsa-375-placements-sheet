/*
QUESTION:-

Given the root of a binary tree and a number k, print all the paths whose
nodes add up to k. A path may start at any node and ends at any node below it
(it only goes downward from a node to its descendants), and it does not need to
end at a leaf. Print every path on a separate line, with its values from the
upper node to the lower node. The paths are printed in the order in which their
last node is met by a preorder traversal (node, left, right). Paths that end at
the same node are printed from the shortest to the longest.

Constraints:
1 <= number of nodes <= 10000
-1000 <= Node.val <= 1000 (the value -1 does not appear)

Example 1:

Input:
root = [1,3,-2,2,1,4,5]
k = 5

Output:
3 2
1 3 1
5

Example 2:

Input:
root = [1,2,3]
k = 3

Output:
1 2
3
*/

/*
APPROACH:-

-> Traverse the tree in preorder and keep the current root-to-node path in a vector called path.
-> When a node is visited, add its value to path. Then look at all the paths that END at this node: they are the parts of path that start at some earlier position j and finish at the end.
-> Walk j from the end of path back to its start, adding up the values. Whenever the running sum equals k, print the values of path from j to the end.
-> Going from the end backwards means the shorter paths (starting at a lower node) are printed before the longer ones.
-> After both children are done, remove the value of the node from path (backtracking).
-> Let N be the number of nodes and H the height. For each node we look back over at most H values, so the time is N * H.
-> The path vector holds at most H values, so the space is H.
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

void findPaths(TreeNode *root, int k, vector<int> &path)
{
    if (root == nullptr)
    {
        return;
    }

    path.push_back(root->val);

    int sum = 0;
    for (int j = (int)path.size() - 1; j >= 0; j--)
    {
        sum += path[j];

        if (sum == k)
        {
            for (int i = j; i < (int)path.size(); i++)
            {
                cout << path[i];
                if (i + 1 < (int)path.size())
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    findPaths(root->left, k, path);
    findPaths(root->right, k, path);

    path.pop_back();
}

int main()
{
    vector<int> values = {1, 3, -2, 2, 1, 4, 5};
    TreeNode *root = buildTree(values);

    vector<int> path;
    findPaths(root, 5, path);

    return 0;
}

/*
TIME COMPLEXITY = O(N * H)
SPACE COMPLEXITY = O(H)
*/
