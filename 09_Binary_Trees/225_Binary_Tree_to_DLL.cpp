/*
QUESTION:-

Given the root of a binary tree, convert it into a doubly linked list in place.
The left pointer of a node must become its previous pointer and the right pointer
must become its next pointer. The order of the nodes in the list must be the
same as the inorder traversal of the tree. Print the list from its head.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
root = [10,12,15,25,30,36]

Output:
25 12 30 10 36 15

Example 2:

Input:
root = [1,2,3]

Output:
2 1 3
*/

/*
APPROACH:-

-> The inorder traversal visits the nodes in the order that the list needs. So do an inorder traversal and link every visited node with the node visited just before it.
-> Keep a pointer prev to the previously visited node (null at the start) and a pointer head to the first visited node.
-> When a node is visited: if prev is null, this node is the head of the list. Otherwise set root->left = prev and prev->right = root. Then set prev = root.
-> The left child is processed before the node is changed, and the right child pointer is still the original one when we go to the right subtree, so the traversal is not damaged by the changes.
-> After the traversal, head is the first node of the list. Print the list by following the right pointers.
-> Let N be the number of nodes. Each node is visited once, so the time is N.
-> The recursion depth is the height of the tree, so the space is H where H is the height of the tree.
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

void convert(TreeNode *root, TreeNode *&prev, TreeNode *&head)
{
    if (root == nullptr)
    {
        return;
    }

    convert(root->left, prev, head);

    if (prev == nullptr)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    convert(root->right, prev, head);
}

int main()
{
    vector<int> values = {10, 12, 15, 25, 30, 36};
    TreeNode *root = buildTree(values);

    TreeNode *prev = nullptr;
    TreeNode *head = nullptr;
    convert(root, prev, head);

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
