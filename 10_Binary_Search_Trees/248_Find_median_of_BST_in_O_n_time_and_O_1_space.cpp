/*
QUESTION:-

Given the root of a binary search tree, find its median in O(N) time and O(1)
extra space (the recursion stack is not allowed, so the tree must be traversed
with a Morris traversal). The median is the middle value of the sorted values of
the tree. If the number of nodes is even, the median is the average of the two
middle values.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 1000000

Example 1:

Input:
root = [20,8,22,4,12,null,null,null,null,10,14]

Output:
12
(the sorted values are 4 8 10 12 14 20 22)

Example 2:

Input:
root = [2,1,3,null,null,null,4]

Output:
2.5
(the sorted values are 1 2 3 4, and (2 + 3) / 2 = 2.5)
*/

/*
APPROACH:-

-> The median depends on the position of the middle value in the sorted order, which is the inorder order of a BST. So we need an inorder traversal that uses no extra memory: the Morris traversal.
-> Morris inorder traversal: for a node with no left child, visit it and go right. Otherwise find the rightmost node of its left subtree (the inorder predecessor). If its right pointer is null, set it to the current node (a temporary thread) and go left. If it already points to the current node, remove the thread, visit the current node and go right.
-> Write a function that counts the nodes with a Morris traversal, and another function getKth(k) that returns the k-th visited value with a Morris traversal. The traversals always run to the end, so all the temporary threads are removed and the tree is restored.
-> Let n be the number of nodes. If n is odd, the median is getKth((n + 1) / 2). If n is even, the median is (getKth(n / 2) + getKth(n / 2 + 1)) / 2.0.
-> Each traversal costs N (every edge is walked at most 3 times), so the time is N.
-> Only a few pointers are used, so the space is constant.
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

int countNodes(TreeNode *root)
{
    int count = 0;
    TreeNode *current = root;

    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            count++;
            current = current->right;
        }
        else
        {
            TreeNode *predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = nullptr;
                count++;
                current = current->right;
            }
        }
    }

    return count;
}

int getKth(TreeNode *root, int k)
{
    int count = 0;
    int answer = -1;
    TreeNode *current = root;

    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            count++;
            if (count == k)
            {
                answer = current->val;
            }
            current = current->right;
        }
        else
        {
            TreeNode *predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = nullptr;
                count++;
                if (count == k)
                {
                    answer = current->val;
                }
                current = current->right;
            }
        }
    }

    return answer;
}

double findMedian(TreeNode *root)
{
    int n = countNodes(root);

    if (n % 2 == 1)
    {
        return getKth(root, (n + 1) / 2);
    }

    int first = getKth(root, n / 2);
    int second = getKth(root, n / 2 + 1);

    return (first + second) / 2.0;
}

int main()
{
    vector<int> values = {20, 8, 22, 4, 12, NO_NODE, NO_NODE, NO_NODE, NO_NODE, 10, 14};
    TreeNode *root = buildTree(values);

    cout << findMedian(root) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
