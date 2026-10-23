/*
QUESTION:-

Given the root of a binary tree, check whether it contains a duplicate subtree
of size 2 or more. Two subtrees are duplicates if they have the same structure
and the same node values. A subtree of size 1 (a single leaf) is not counted, so
two equal leaves are not duplicates here. Return true if such a duplicate exists
and false otherwise.

Constraints:
1 <= number of nodes <= 1000
1 <= Node.val <= 1000

Example 1:

Input:
root = [1,2,3,4,5,null,2,null,null,null,null,4,5]

Output:
true
(the subtree 2 -> (4, 5) appears twice)

Example 2:

Input:
root = [1,2,3]

Output:
false
*/

/*
APPROACH:-

-> Convert every subtree into a string that describes it completely: "(" + serial of left + "," + value + "," + serial of right + ")", and "$" for an empty child. Two subtrees are equal exactly when their strings are equal.
-> Traverse the tree in postorder (left, right, node), so the strings of the children are ready before the string of the node.
-> Keep a set of the strings of the subtrees seen so far. For every node that is not a leaf, check if its string is already in the set. If yes, a duplicate of size 2 or more exists.
-> Otherwise insert the string into the set. Leaves are skipped, because single node subtrees are not counted.
-> Let N be the number of nodes. Building the strings can take up to N characters per node in the worst case (for example a long chain), so the time is N * N.
-> The strings stored in the set can take N * N space in the worst case.
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

string findDuplicate(TreeNode *root, unordered_set<string> &seen, bool &found)
{
    if (root == nullptr)
    {
        return "$";
    }

    string left = findDuplicate(root->left, seen, found);
    string right = findDuplicate(root->right, seen, found);

    string current = "(" + left + "," + to_string(root->val) + "," + right + ")";

    if (root->left != nullptr || root->right != nullptr)
    {
        if (seen.count(current) > 0)
        {
            found = true;
        }
        else
        {
            seen.insert(current);
        }
    }

    return current;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5, NO_NODE, 2, NO_NODE, NO_NODE, NO_NODE, NO_NODE, 4, 5};
    TreeNode *root = buildTree(values);

    unordered_set<string> seen;
    bool found = false;
    findDuplicate(root, seen, found);

    if (found)
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
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
