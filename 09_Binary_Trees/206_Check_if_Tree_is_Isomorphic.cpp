/*
QUESTION:-

Two binary trees are called isomorphic if one of them can be obtained from the
other by swapping the left and right children of any number of nodes (the swap
can be done at many nodes, and the children are swapped together with their
subtrees). Given the roots of two binary trees, check if they are isomorphic.
Return true if they are, and false otherwise.

Constraints:
0 <= number of nodes <= 10000
0 <= Node.val <= 100000, and all the values inside one tree are different

Example 1:

Input:
root1 = [1,2,3,4,5,null,6]
root2 = [1,3,2,6,null,5,4]

Output:
true

Example 2:

Input:
root1 = [1,2,3,4,5,null,6]
root2 = [1,3,2,6,null,5,7]

Output:
false
(the value 7 does not exist in the first tree)
*/

/*
APPROACH:-

-> Two empty trees are isomorphic. If only one of them is empty, they are not.
-> If the root values are different, they are not isomorphic.
-> If the roots have the same value, the trees are isomorphic in one of two ways: without swapping the children, which needs left1 ~ left2 and right1 ~ right2, or with swapping the children, which needs left1 ~ right2 and right1 ~ left2.
-> Return true if any of these two ways works. Both ways are checked by recursion with the same function.
-> The values are distinct, so a node of the first tree can only match the node with the same value in the second tree. So every node takes part in a constant number of comparisons.
-> Let N be the number of nodes. The time is N.
-> The recursion depth is at most the height of the trees, so the space is H where H is the height.
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

bool isIsomorphic(TreeNode *a, TreeNode *b)
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

    bool withoutSwap = isIsomorphic(a->left, b->left) && isIsomorphic(a->right, b->right);
    bool withSwap = isIsomorphic(a->left, b->right) && isIsomorphic(a->right, b->left);

    return withoutSwap || withSwap;
}

int main()
{
    vector<int> values1 = {1, 2, 3, 4, 5, NO_NODE, 6};
    vector<int> values2 = {1, 3, 2, 6, NO_NODE, 5, 4};
    TreeNode *root1 = buildTree(values1);
    TreeNode *root2 = buildTree(values2);

    bool answer = isIsomorphic(root1, root2);

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
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
