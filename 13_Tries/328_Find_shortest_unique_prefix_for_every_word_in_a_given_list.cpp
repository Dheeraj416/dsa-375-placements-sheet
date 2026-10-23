/*
QUESTION:-

Given a list of words where no word is a prefix of another word, find the
shortest unique prefix of every word. The shortest unique prefix of a word is the
shortest prefix of it that is not a prefix of any other word in the list.

Constraints:
1 <= words.size() <= 1000
1 <= words[i].length <= 100
words[i] contains only lowercase English letters.
All words are different and no word is a prefix of another word.

Example 1:

Input:
words = ["zebra", "dog", "duck", "dove"]

Output:
z dog du dov

Example 2:

Input:
words = ["apple", "ape", "bat"]

Output:
app ape b
*/

/*
APPROACH:-

-> Insert all words in a trie. Every node stores a count: how many words pass through this node (how many words have this prefix).
-> While inserting a word, increase the count of every node on its path.
-> For a word, walk down the trie from the root and build the prefix letter by letter. The first node whose count is 1 means that only this word has this prefix, so the prefix built so far is the shortest unique prefix. Stop there.
-> Because no word is a prefix of another word, such a node always exists on the path of every word.
-> Let N be the number of words and L the length of the longest word. Inserting and searching every word takes at most L steps, so the time is N * L.
-> The trie has at most N * L nodes, so the space is N * L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    int count;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        count = 0;
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
        node->count++;
    }
}

vector<string> shortestPrefixes(vector<string> &words)
{
    TrieNode *root = new TrieNode();

    for (int i = 0; i < (int)words.size(); i++)
    {
        insertWord(root, words[i]);
    }

    vector<string> answer;

    for (int i = 0; i < (int)words.size(); i++)
    {
        TrieNode *node = root;
        string prefix = "";

        for (int j = 0; j < (int)words[i].size(); j++)
        {
            int index = words[i][j] - 'a';

            node = node->child[index];
            prefix = prefix + words[i][j];

            if (node->count == 1)
            {
                break;
            }
        }

        answer.push_back(prefix);
    }

    return answer;
}

int main()
{
    vector<string> words = {"zebra", "dog", "duck", "dove"};

    vector<string> answer = shortestPrefixes(words);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * L)
SPACE COMPLEXITY = O(N * L)
*/
