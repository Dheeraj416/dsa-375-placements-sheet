/*
QUESTION:-

Given the roots of two binary search trees, print all the values of both trees
in increasing order (the values of the two trees together, with repeated values
kept).

Constraints:
0 <= number of nodes in each tree <= 100000
1 <= Node.val <= 1000000

Example 1:

Input:
root1 = [3,1,5]
root2 = [4,2,6]

Output:
1 2 3 4 5 6

Example 2:

Input:
root1 = [8,2,10,1]
root2 = [5,3,null,0]

Output:
0 1 2 3 5 8 10
*/

/*
APPROACH:-

-> The inorder traversal of a BST gives its values in sorted order. So take the inorder traversal of both trees into two sorted arrays.
-> Merge the two sorted arrays like in the merge step of merge sort: use two pointers i and j, and always take the smaller one of a[i] and b[j] into the answer. When one array is finished, copy the rest of the other.
-> The merged array is sorted and holds all the values.
-> Let N and M be the number of nodes of the two trees. The traversals cost N + M and the merge costs N + M, so the time is N + M.
-> The arrays take N + M space.
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

void collectInorder(TreeNode *root, vector<int> &values)
{
    if (root == nullptr)
    {
        return;
    }

    collectInorder(root->left, values);
    values.push_back(root->val);
    collectInorder(root->right, values);
}

vector<int> mergeBsts(TreeNode *root1, TreeNode *root2)
{
    vector<int> first;
    vector<int> second;
    collectInorder(root1, first);
    collectInorder(root2, second);

    vector<int> merged;
    int i = 0;
    int j = 0;

    while (i < (int)first.size() && j < (int)second.size())
    {
        if (first[i] <= second[j])
        {
            merged.push_back(first[i]);
            i++;
        }
        else
        {
            merged.push_back(second[j]);
            j++;
        }
    }

    while (i < (int)first.size())
    {
        merged.push_back(first[i]);
        i++;
    }

    while (j < (int)second.size())
    {
        merged.push_back(second[j]);
        j++;
    }

    return merged;
}

int main()
{
    vector<int> values1 = {3, 1, 5};
    vector<int> values2 = {4, 2, 6};
    TreeNode *root1 = buildTree(values1);
    TreeNode *root2 = buildTree(values2);

    vector<int> answer = mergeBsts(root1, root2);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(N + M)
*/
