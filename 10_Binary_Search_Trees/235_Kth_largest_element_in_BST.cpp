/*
QUESTION:-

Given the root of a binary search tree and a number k, return the k-th largest
value in the tree. It is guaranteed that k is valid (1 <= k <= number of nodes).

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000
1 <= k <= number of nodes

Example 1:

Input:
root = [20,8,22,4,12,null,null,null,null,10,14]
k = 3

Output:
14

Example 2:

Input:
root = [5,3,6,2,4,null,null,1]
k = 1

Output:
6
*/

/*
APPROACH:-

-> The normal inorder traversal (left, node, right) gives the values in increasing order. The reverse inorder traversal (right, node, left) gives them in decreasing order, so the k-th node visited is the k-th largest.
-> Keep a counter called count, which is shared by all the recursive calls.
-> Visit the right subtree first. After it returns, if count is already k, the answer has been found, so stop. Otherwise count the current node. If count becomes k, this node is the answer.
-> Then visit the left subtree.
-> We stop early, so only the nodes on the way to the answer and the larger ones are visited.
-> Let H be the height of the tree. The time is H + k, because we walk down to the largest node and then visit k nodes.
-> The recursion depth is the height of the tree, so the space is H.
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

void findKthLargest(TreeNode *root, int k, int &count, int &answer)
{
    if (root == nullptr)
    {
        return;
    }

    findKthLargest(root->right, k, count, answer);

    if (count >= k)
    {
        return;
    }

    count++;
    if (count == k)
    {
        answer = root->val;
        return;
    }

    findKthLargest(root->left, k, count, answer);
}

int main()
{
    vector<int> values = {20, 8, 22, 4, 12, NO_NODE, NO_NODE, NO_NODE, NO_NODE, 10, 14};
    TreeNode *root = buildTree(values);

    int count = 0;
    int answer = -1;
    findKthLargest(root, 3, count, answer);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(H + K)
SPACE COMPLEXITY = O(H)
*/
