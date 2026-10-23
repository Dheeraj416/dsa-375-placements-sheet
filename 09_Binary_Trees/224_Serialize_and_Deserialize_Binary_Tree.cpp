/*
QUESTION:-

Design an algorithm to serialize and deserialize a binary tree. Serialization
converts a tree into a string, and deserialization converts that string back
into the same tree. The format of the string is up to you, but deserialize must
rebuild exactly the tree that serialize received. This solution writes the
nodes in preorder, uses # for a missing child, and separates the items with
spaces.

Constraints:
0 <= number of nodes <= 10000
0 <= Node.val <= 10000

Example 1:

Input:
root = [1,2,3,null,null,4,5]

Output:
Serialized string: "1 2 # # 3 4 # # 5 # #"
The deserialized tree is the same as the original tree.

Example 2:

Input:
root = []

Output:
Serialized string: "#"
*/

/*
APPROACH:-

-> Serialize with a preorder traversal: write the value of the node, then serialize the left subtree, then the right subtree.
-> A null child is written as the marker #, so the shape of the tree is stored along with the values.
-> Deserialize by reading the tokens in the same order with a shared index that moves forward.
-> If the current token is #, return null. Otherwise create a node with that value, build its left subtree from the next tokens and then its right subtree.
-> Because preorder with null markers describes the tree uniquely, the same structure is rebuilt.
-> In main, the tree is serialized, deserialized and serialized again. Both strings must match.
-> Both directions visit every node once and use space for the string plus the recursion.
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

void serializeHelper(TreeNode *node, string &result)
{
    if (node == nullptr)
    {
        result = result + "# ";
        return;
    }

    result = result + to_string(node->val) + " ";
    serializeHelper(node->left, result);
    serializeHelper(node->right, result);
}

string serialize(TreeNode *root)
{
    string result = "";

    serializeHelper(root, result);

    return result;
}

TreeNode *deserializeHelper(vector<string> &tokens, int &index)
{
    string token = tokens[index];
    index++;

    if (token == "#")
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode(stoi(token));
    node->left = deserializeHelper(tokens, index);
    node->right = deserializeHelper(tokens, index);

    return node;
}

TreeNode *deserialize(string &data)
{
    vector<string> tokens;
    stringstream stream(data);
    string token;

    while (stream >> token)
    {
        tokens.push_back(token);
    }

    int index = 0;

    return deserializeHelper(tokens, index);
}

int main()
{
    vector<int> values = {1, 2, 3, NO_NODE, NO_NODE, 4, 5};
    TreeNode *root = buildTree(values);

    string data = serialize(root);
    cout << data << "\n";

    TreeNode *rebuilt = deserialize(data);
    string again = serialize(rebuilt);

    if (again == data)
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
SPACE COMPLEXITY = O(N)
*/
