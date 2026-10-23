/*
QUESTION:-

Every node of a binary search tree has an extra pointer called next. Fill the
next pointer of every node so that it points to the inorder successor of the
node, which is the node with the next larger value. The next pointer of the
largest node stays null. Insert the given values one by one into an empty BST,
fill the next pointers, and then print every node in inorder order as "value
successor" on its own line (-1 if there is no successor).

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000, all values are different

Example 1:

Input:
values = [10,8,12,3]

Output:
3 8
8 10
10 12
12 -1

Example 2:

Input:
values = [5]

Output:
5 -1
*/

/*
APPROACH:-

-> The successor of a node is the node that comes right after it in the inorder traversal. If we traverse in the REVERSE inorder (right, node, left), then the node visited just before the current node is its successor.
-> Keep a pointer called nextNode, which holds the last visited node (null at the start, because the largest node has no successor).
-> Visit the right subtree first. Then set root->next = nextNode, and update nextNode = root. Then visit the left subtree.
-> After this, every node points to the node with the next larger value.
-> To print, do a normal inorder traversal and print each node's value and the value of its next node (or -1).
-> Let N be the number of nodes. Each node is visited once, so the time is N.
-> The recursion depth is the height of the tree, so the space is H where H is the height.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

Node *insertNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }

    if (key < root->val)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = insertNode(root->right, key);
    }

    return root;
}

void populateNext(Node *root, Node *&nextNode)
{
    if (root == nullptr)
    {
        return;
    }

    populateNext(root->right, nextNode);

    root->next = nextNode;
    nextNode = root;

    populateNext(root->left, nextNode);
}

void printSuccessors(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    printSuccessors(root->left);

    cout << root->val << " ";
    if (root->next != nullptr)
    {
        cout << root->next->val;
    }
    else
    {
        cout << -1;
    }
    cout << "\n";

    printSuccessors(root->right);
}

int main()
{
    vector<int> values = {10, 8, 12, 3};
    Node *root = nullptr;

    for (int i = 0; i < (int)values.size(); i++)
    {
        root = insertNode(root, values[i]);
    }

    Node *nextNode = nullptr;
    populateNext(root, nextNode);

    printSuccessors(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
