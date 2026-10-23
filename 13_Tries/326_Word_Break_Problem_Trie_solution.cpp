/*
QUESTION:-

Given a string s and a dictionary of words, return true if s can be split into a
sequence of one or more dictionary words, otherwise return false. A dictionary
word can be used any number of times. Solve it using a trie that stores the
dictionary.

Constraints:
1 <= s.length <= 300
1 <= dictionary.size() <= 1000
1 <= dictionary[i].length <= 20
s and all dictionary words contain only lowercase English letters.

Example 1:

Input:
s = "leetcode"
dictionary = ["leet", "code"]

Output:
true
(leetcode = leet + code)

Example 2:

Input:
s = "catsandog"
dictionary = ["cats", "dog", "sand", "and", "cat"]

Output:
false
*/

/*
APPROACH:-

-> Put all dictionary words into a trie. Every node has 26 children and a flag that says that a dictionary word ends there.
-> Let canBreak[i] be true if the first i letters of s can be split into dictionary words. canBreak[0] is true because the empty prefix is always fine.
-> For every start position where canBreak[start] is true, walk down the trie letter by letter from s[start]. If the child for the letter does not exist, stop.
-> Each time the walk reaches a node where a word ends at position end, a dictionary word covers s[start..end], so set canBreak[end + 1] = true.
-> The answer is canBreak[n]. The trie lets us check all words that start at one position in a single walk instead of comparing every word.
-> Let N be the length of s, L the length of the longest dictionary word and D the total number of letters in the dictionary. Building the trie takes D. Every start position walks at most L letters, so the walking takes N * L. The time is N * L + D.
-> The trie has at most D nodes and the canBreak array has N + 1 values, so the space is D + N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        isWord = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    TrieNode *node = root;

    for (int i = 0; i < (int)word.size(); i++)
    {
        int index = word[i] - 'a';

        if (node->child[index] == nullptr)
        {
            node->child[index] = new TrieNode();
        }

        node = node->child[index];
    }

    node->isWord = true;
}

bool wordBreak(string s, vector<string> &dictionary)
{
    TrieNode *root = new TrieNode();

    for (int i = 0; i < (int)dictionary.size(); i++)
    {
        insertWord(root, dictionary[i]);
    }

    int n = s.size();
    vector<bool> canBreak(n + 1, false);
    canBreak[0] = true;

    for (int start = 0; start < n; start++)
    {
        if (canBreak[start] == false)
        {
            continue;
        }

        TrieNode *node = root;

        for (int end = start; end < n; end++)
        {
            int index = s[end] - 'a';

            if (node->child[index] == nullptr)
            {
                break;
            }

            node = node->child[index];

            if (node->isWord)
            {
                canBreak[end + 1] = true;
            }
        }
    }

    return canBreak[n];
}

int main()
{
    string s = "leetcode";
    vector<string> dictionary = {"leet", "code"};

    cout << (wordBreak(s, dictionary) ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * L + D)
SPACE COMPLEXITY = O(D + N)
*/
