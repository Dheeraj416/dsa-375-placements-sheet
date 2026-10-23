/*
QUESTION:-

Implement a Trie (prefix tree) that stores lowercase English words, with these
operations:
- insert(word): adds the word to the trie.
- search(word): returns true if the word was inserted before, otherwise false.
- startsWith(prefix): returns true if some inserted word starts with the given
  prefix, otherwise false.

Constraints:
1 <= word.length, prefix.length <= 2000
word and prefix contain only lowercase English letters.
At most 30000 operations are made.

Example 1:

Input:
["insert","search","search","startsWith","insert","search"]
[["apple"],["apple"],["app"],["app"],["app"],["app"]]

Output:
[null,true,false,true,null,true]
(after inserting only "apple", "app" is a prefix but not a stored word; after inserting "app" it becomes a word)

Example 2:

Input:
["insert","insert","search","startsWith","search"]
[["cat"],["car"],["ca"],["ca"],["cab"]]

Output:
[null,null,false,true,false]
*/

/*
APPROACH:-

-> A trie stores words letter by letter. Every node has 26 children, one for every letter, and a flag that says whether a word ends at this node.
-> The root represents the empty string. The path from the root to a node spells a prefix, and words with a common prefix share the same path.
-> insert: start at the root. For each letter, go to the child of that letter; if the child does not exist, create it. After the last letter, mark the node as the end of a word.
-> search: follow the letters from the root. If a child is missing, return false. At the end, return true only if the node is marked as the end of a word (so "app" is not found when only "apple" was inserted).
-> startsWith: follow the letters in the same way, but at the end return true as long as the whole path exists, whether or not a word ends there.
-> Both search and startsWith use a helper that follows a string and returns the final node (or nullptr if the path breaks).
-> Let L be the length of the word or prefix. Every operation visits one node per letter, so the time is L.
-> Let N be the number of inserted words. They create at most N * L nodes, and each node has 26 pointers (a fixed size), so the space is N * L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;

    TrieNode *findNode(string text)
    {
        TrieNode *node = root;

        for (char letter : text)
        {
            int index = letter - 'a';

            if (node->children[index] == nullptr)
            {
                return nullptr;
            }

            node = node->children[index];
        }

        return node;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;

        for (char letter : word)
        {
            int index = letter - 'a';

            if (node->children[index] == nullptr)
            {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *node = findNode(word);

        return node != nullptr && node->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        return findNode(prefix) != nullptr;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    cout << (trie.search("apple") ? "true" : "false") << "\n";
    cout << (trie.search("app") ? "true" : "false") << "\n";
    cout << (trie.startsWith("app") ? "true" : "false") << "\n";
    trie.insert("app");
    cout << (trie.search("app") ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(L)
SPACE COMPLEXITY = O(N * L)
*/
