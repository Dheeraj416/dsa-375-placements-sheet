/*
QUESTION:-

Implement a phone directory. You are given a list of contacts and a query string.
For every prefix of the query string (the first letter, the first two letters,
and so on), show all contacts that start with that prefix, in alphabetical
order. If no contact starts with the prefix, show 0 for it.

Constraints:
1 <= contacts.size() <= 500
1 <= contacts[i].length <= 50
1 <= query.length <= 50
All strings contain only lowercase English letters.

Example 1:

Input:
contacts = ["geeikistest", "geeksforgeeks", "geeksfortest"]
query = "geeips"

Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

Example 2:

Input:
contacts = ["cat", "car", "dog"]
query = "cab"

Output:
car cat
car cat
0
*/

/*
APPROACH:-

-> Insert all contacts in a trie. A node has 26 children (one per letter, in alphabetical order) and a flag that says a contact ends there.
-> Walk down the trie with the letters of the query. After each letter, the current node represents the current prefix. If the child does not exist, the node becomes null and stays null for all longer prefixes, so they all show 0.
-> To list the contacts of a prefix, run a DFS from its node. At each node, if a contact ends there, add the string built so far, then visit the children from 'a' to 'z'. Visiting the children in this order gives the contacts in alphabetical order.
-> Print the list for each prefix, or 0 if the list is empty.
-> Let D be the total number of letters in all contacts and Q the length of the query. Building the trie takes D. Each of the Q prefixes may list all contacts, which is at most D letters, so the time is D + Q * D.
-> The trie has at most D nodes, so the space is D.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        isEnd = false;
    }
};

void insertContact(TrieNode *root, string contact)
{
    TrieNode *node = root;

    for (int i = 0; i < (int)contact.size(); i++)
    {
        int index = contact[i] - 'a';

        if (node->child[index] == nullptr)
        {
            node->child[index] = new TrieNode();
        }

        node = node->child[index];
    }

    node->isEnd = true;
}

void collect(TrieNode *node, string current, vector<string> &found)
{
    if (node->isEnd)
    {
        found.push_back(current);
    }

    for (int i = 0; i < 26; i++)
    {
        if (node->child[i] != nullptr)
        {
            collect(node->child[i], current + (char)('a' + i), found);
        }
    }
}

vector<vector<string>> suggestions(vector<string> &contacts, string query)
{
    TrieNode *root = new TrieNode();

    for (int i = 0; i < (int)contacts.size(); i++)
    {
        insertContact(root, contacts[i]);
    }

    vector<vector<string>> answer;
    TrieNode *node = root;
    string prefix = "";

    for (int i = 0; i < (int)query.size(); i++)
    {
        prefix = prefix + query[i];

        if (node != nullptr)
        {
            node = node->child[query[i] - 'a'];
        }

        vector<string> found;

        if (node != nullptr)
        {
            collect(node, prefix, found);
        }

        answer.push_back(found);
    }

    return answer;
}

int main()
{
    vector<string> contacts = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string query = "geeips";

    vector<vector<string>> answer = suggestions(contacts, query);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        if (answer[i].empty())
        {
            cout << "0";
        }

        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(D + Q * D)
SPACE COMPLEXITY = O(D)
*/
