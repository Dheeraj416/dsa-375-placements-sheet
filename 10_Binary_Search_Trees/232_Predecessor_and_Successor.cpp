/*
QUESTION:-

Given the root of a binary search tree and a key, find the inorder predecessor
and the inorder successor of the key. The predecessor is the largest value in
the tree that is smaller than the key. The successor is the smallest value in
the tree that is larger than the key. The key may or may not be present in the
tree. If the predecessor or the successor does not exist, it is -1.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val, key <= 1000000

Example 1:

Input:
root = [50,30,70,20,40,60,80]
key = 65

Output:
60 70

Example 2:

Input:
root = [50,30,70,20,40,60,80]
key = 20

Output:
-1 30
(there is no value smaller than 20 in the tree)
*/

/*
APPROACH:-

-> Walk down from the root, as if we were searching for the key.
-> If the current node's value is smaller than the key, this node is a possible predecessor: remember it in pre, and go to the right child to look for a bigger one that is still smaller than the key.
-> If the current node's value is bigger than the key, this node is a possible successor: remember it in suc, and go to the left child to look for a smaller one that is still bigger than the key.
-> If the value equals the key, the predecessor is the rightmost node of its left subtree (if the left subtree exists) and the successor is the leftmost node of its right subtree (if the right subtree exists). Then stop.
-> The values saved in pre and suc while walking down are used when these subtrees are missing.
-> Let H be the height of the tree. We follow one path, so the time is H.
-> Only a few variables are used, so the space is constant.
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

void findPreSuc(TreeNode *root, int key, int &pre, int &suc)
{
    pre = -1;
    suc = -1;
    TreeNode *current = root;

    while (current != nullptr)
    {
        if (current->val < key)
        {
            pre = current->val;
            current = current->right;
        }
        else if (current->val > key)
        {
            suc = current->val;
            current = current->left;
        }
        else
        {
            if (current->left != nullptr)
            {
                TreeNode *temp = current->left;
                while (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                pre = temp->val;
            }

            if (current->right != nullptr)
            {
                TreeNode *temp = current->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                suc = temp->val;
            }

            break;
        }
    }
}

int main()
{
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    TreeNode *root = buildTree(values);

    int pre = -1;
    int suc = -1;
    findPreSuc(root, 65, pre, suc);

    cout << pre << " " << suc << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(H)
SPACE COMPLEXITY = O(1)
*/
