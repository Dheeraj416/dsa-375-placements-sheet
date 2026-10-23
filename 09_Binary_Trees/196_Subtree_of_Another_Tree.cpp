/*
QUESTION:-

Given the roots of two binary trees root and subRoot, return true if there is a
subtree of root that has exactly the same structure and the same node values as
subRoot, and false otherwise. A subtree of a tree is a node of the tree together
with all of its descendants. The tree itself is also a subtree of itself.

Constraints:
1 <= number of nodes in root <= 2000
1 <= number of nodes in subRoot <= 1000
0 <= Node.val <= 10000

Example 1:

Input:
root = [3,4,5,1,2]
subRoot = [4,1,2]

Output:
true

Example 2:

Input:
root = [3,4,5,1,2,null,null,null,null,0]
subRoot = [4,1,2]

Output:
false
(the node 2 has an extra child 0 in the big tree)
*/

/*
APPROACH:-

-> First write a helper isSameTree(a, b) that checks if two trees are exactly equal: both empty is true, only one empty is false, different values is false, otherwise both the left subtrees and the right subtrees must be equal.
-> The main function tries every node of root as a possible starting point of the subtree.
-> If subRoot is empty the answer is true. If root is empty (and subRoot is not), the answer is false.
-> If isSameTree(root, subRoot) is true, we found it. Otherwise look in the left subtree of root, and then in the right subtree of root.
-> Let N be the number of nodes in root and M the number of nodes in subRoot. For each of the N nodes the comparison takes at most M steps, so the time is N * M.
-> The recursion depth is at most the height of root, so the space is H where H is the height of the tree.
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

bool isSameTree(TreeNode *a, TreeNode *b)
{
    if (a == nullptr && b == nullptr)
    {
        return true;
    }

    if (a == nullptr || b == nullptr)
    {
        return false;
    }

    if (a->val != b->val)
    {
        return false;
    }

    return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (subRoot == nullptr)
    {
        return true;
    }

    if (root == nullptr)
    {
        return false;
    }

    if (isSameTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    vector<int> rootValues = {3, 4, 5, 1, 2};
    vector<int> subValues = {4, 1, 2};
    TreeNode *root = buildTree(rootValues);
    TreeNode *subRoot = buildTree(subValues);

    bool answer = isSubtree(root, subRoot);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(H)
*/
