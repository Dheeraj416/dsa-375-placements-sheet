/*
QUESTION:-

Consider lines of slope -1 that pass through the nodes of a binary tree. All the
nodes that lie on the same line belong to the same diagonal. The root is on the
diagonal 0, the right child of a node is on the same diagonal as the node, and
the left child of a node is on the next diagonal (the diagonal number plus 1).
Print the diagonal traversal of the tree: all the nodes of diagonal 0, then all
the nodes of diagonal 1, and so on. Inside a diagonal the nodes are in the order
in which a preorder traversal (node, left, right) meets them.

Constraints:
0 <= number of nodes <= 100000
0 <= Node.val <= 100000

Example 1:

Input:
root = [8,3,10,1,6,null,14,null,null,4,7,13]

Output:
8 10 14 3 6 7 13 1 4

Example 2:

Input:
root = [1,2,3,4,5,6,7]

Output:
1 3 7 2 5 6 4
*/

/*
APPROACH:-

-> Give every node a diagonal number d. The root has d = 0. Going to the right child keeps d, going to the left child makes it d + 1.
-> Use a map from the diagonal number to the list of values on this diagonal. A map keeps its keys sorted, so we can print diagonal 0 first, then 1, and so on.
-> Traverse the tree recursively in preorder: add the value of the node to map[d], then visit the left child with d + 1, and the right child with d.
-> At the end, go through the map in key order and print every list.
-> Let N be the number of nodes and D the number of diagonals. Each node is added once and the map has D keys, so the time is N + D * log D, which is at most N * log N.
-> The map stores all N values, so the space is N.
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

void collectDiagonals(TreeNode *root, int d, map<int, vector<int>> &diagonals)
{
    if (root == nullptr)
    {
        return;
    }

    diagonals[d].push_back(root->val);

    collectDiagonals(root->left, d + 1, diagonals);
    collectDiagonals(root->right, d, diagonals);
}

vector<int> diagonalTraversal(TreeNode *root)
{
    map<int, vector<int>> diagonals;
    collectDiagonals(root, 0, diagonals);

    vector<int> result;

    for (map<int, vector<int>>::iterator it = diagonals.begin(); it != diagonals.end(); it++)
    {
        for (int i = 0; i < (int)it->second.size(); i++)
        {
            result.push_back(it->second[i]);
        }
    }

    return result;
}

int main()
{
    vector<int> values = {8, 3, 10, 1, 6, NO_NODE, 14, NO_NODE, NO_NODE, 4, 7, 13};
    TreeNode *root = buildTree(values);

    vector<int> answer = diagonalTraversal(root);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
