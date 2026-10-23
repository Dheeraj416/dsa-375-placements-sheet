/*
QUESTION:-

You are given a string made of integers and parentheses that represents a binary
tree in this way: a node is written as its integer value, followed by zero, one
or two pairs of parentheses. The first pair holds the left child (with its own
descendants) and the second pair holds the right child. Construct the binary
tree and print it in level order.

Constraints:
1 <= length of the string <= 100000
Every value is a non negative integer. An empty pair "()" never appears, so a
node with only a right child is not given in this format.

Example 1:

Input:
s = "4(2(3)(1))(6(5))"

Output:
[4,2,6,3,1,5]

Example 2:

Input:
s = "1(2)(3(4))"

Output:
[1,2,3,null,null,4]
*/

/*
APPROACH:-

-> Use a recursive function with a shared position index into the string. It builds one node and returns it.
-> Read the digits at the current position, and make them one integer. Create the node with this value.
-> If the next character is '(' then a left child is given: move past the '(', build the left child by a recursive call, and then move past the matching ')'.
-> If the next character is '(' again, do the same for the right child.
-> Because the recursive call stops exactly at the ')' that closes its own pair, the index is always in the right place after the call.
-> Let N be the length of the string. Each character is read once, so the time is N.
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

TreeNode *buildFromString(string &s, int &index)
{
    if (index >= (int)s.size())
    {
        return nullptr;
    }

    int number = 0;
    while (index < (int)s.size() && s[index] >= '0' && s[index] <= '9')
    {
        number = number * 10 + (s[index] - '0');
        index++;
    }

    TreeNode *node = new TreeNode(number);

    if (index < (int)s.size() && s[index] == '(')
    {
        index++;
        node->left = buildFromString(s, index);
        index++;
    }

    if (index < (int)s.size() && s[index] == '(')
    {
        index++;
        node->right = buildFromString(s, index);
        index++;
    }

    return node;
}

int main()
{
    string s = "4(2(3)(1))(6(5))";
    int index = 0;

    TreeNode *root = buildFromString(s, index);

    printTreeLevelOrder(root);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(H)
*/
