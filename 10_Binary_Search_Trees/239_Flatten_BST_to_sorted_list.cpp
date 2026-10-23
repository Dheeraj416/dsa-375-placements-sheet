/*
QUESTION:-

Given the root of a binary search tree, flatten it into a sorted linked list in
place, using the tree nodes. After flattening, the left pointer of every node
must be null, and the right pointer must point to the next larger node. The
first node of the list is the smallest node. Print the values of the list from
its first node.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000

Example 1:

Input:
root = [5,3,6,2,4,null,8,1,null,null,null,7,9]

Output:
1 2 3 4 5 6 7 8 9

Example 2:

Input:
root = [5,1,7]

Output:
1 5 7
*/

/*
APPROACH:-

-> The inorder traversal of a BST visits the nodes in sorted order, which is exactly the order of the list we want.
-> Make a dummy node and keep a pointer called tail, which points to the last node added to the list. At the start tail is the dummy node.
-> Do an inorder traversal. When a node is visited: set its left pointer to null, link it after the tail with tail->right = node, and move tail to this node.
-> The right subtree is read before the node's own right pointer can be changed (the pointer is only changed when the next node is attached), so the traversal stays correct.
-> The first node of the list is dummy->right.
-> Let N be the number of nodes. Each node is visited once, so the time is N.
-> The recursion depth is the height of the tree, so the space is H where H is the height.
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

void flattenInorder(TreeNode *root, TreeNode *&tail)
{
    if (root == nullptr)
    {
        return;
    }

    flattenInorder(root->left, tail);

    root->left = nullptr;
    tail->right = root;
    tail = root;

    flattenInorder(root->right, tail);
}

TreeNode *flattenBst(TreeNode *root)
{
    TreeNode *dummy = new TreeNode(0);
    TreeNode *tail = dummy;

    flattenInorder(root, tail);

    TreeNode *head = dummy->right;
    delete dummy;
    return head;
}

int main()
{
    vector<int> values = {5, 3, 6, 2, 4, NO_NODE, 8, 1, NO_NODE, NO_NODE, NO_NODE, 7, 9};
    TreeNode *root = buildTree(values);

    TreeNode *head = flattenBst(root);

    TreeNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->right;
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
