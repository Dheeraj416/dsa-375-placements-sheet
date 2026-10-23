/*
QUESTION:-

Given the root of a binary tree, return the roots of all the duplicate subtrees.
Two subtrees are duplicates if they have the same structure and the same node
values (a single node is also a subtree). For every kind of duplicate subtree,
report only one of them. Print each reported subtree in level order, in the order
in which the second copy of the subtree is found by a postorder traversal (left,
right, node).

Constraints:
1 <= number of nodes <= 5000
0 <= Node.val <= 200

Example 1:

Input:
root = [1,2,3,4,null,2,4,null,null,4]

Output:
[4]
[2,4]

Example 2:

Input:
root = [2,1,1]

Output:
[1]
*/

/*
APPROACH:-

-> Convert every subtree into a string that describes it completely: "(" + serial of left + "," + value + "," + serial of right + ")", and "$" for an empty child. Two subtrees are equal exactly when their strings are equal.
-> Traverse the tree in postorder, so the strings of the children are ready before the string of the node.
-> Keep a map from the string to how many times it has been seen. Every time we make a string for a node, increase its count.
-> When the count becomes exactly 2, we have found a duplicate for the first time, so add this node to the answer. Later copies (count 3, 4, ...) are not added again, so every kind of duplicate is reported once.
-> Print every node of the answer with the level order printing of its subtree.
-> Let N be the number of nodes. The strings can be long (up to N characters), so the time is N * N in the worst case.
-> The map stores the strings, so the space is N * N in the worst case.
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

void printTreeLevelOrder(TreeNode *root)
{
    vector<string> parts;
    queue<TreeNode *> pending;
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode *node = pending.front();
        pending.pop();

        if (node == nullptr)
        {
            parts.push_back("null");
            continue;
        }

        parts.push_back(to_string(node->val));
        pending.push(node->left);
        pending.push(node->right);
    }

    while (!parts.empty() && parts.back() == "null")
    {
        parts.pop_back();
    }

    cout << "[";
    for (int i = 0; i < (int)parts.size(); i++)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << parts[i];
    }
    cout << "]\n";
}

string findDuplicates(TreeNode *root, unordered_map<string, int> &count, vector<TreeNode *> &result)
{
    if (root == nullptr)
    {
        return "$";
    }

    string left = findDuplicates(root->left, count, result);
    string right = findDuplicates(root->right, count, result);

    string current = "(" + left + "," + to_string(root->val) + "," + right + ")";

    count[current]++;
    if (count[current] == 2)
    {
        result.push_back(root);
    }

    return current;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, NO_NODE, 2, 4, NO_NODE, NO_NODE, 4};
    TreeNode *root = buildTree(values);

    unordered_map<string, int> count;
    vector<TreeNode *> result;
    findDuplicates(root, count, result);

    for (int i = 0; i < (int)result.size(); i++)
    {
        printTreeLevelOrder(result[i]);
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N * N)
*/
