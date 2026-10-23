/*
QUESTION:-

This is the "Alien Dictionary" problem. An alien language uses the same letters as
English, but in an unknown order. You are given a list of words that are sorted
in the dictionary order of that language. Find an order of the letters (the ones
that appear in the words) that is consistent with the given list. If there are
several valid orders, use the one produced by the method in the approach below.
If no valid order exists, return "-1".

Constraints:
1 <= number of words <= 100
1 <= length of a word <= 20
All the words contain only lowercase letters.

Example 1:

Input:
words = ["baa","abcd","abca","cab","cad"]

Output:
bdac

Example 2:

Input:
words = ["z","x","z"]

Output:
-1
(z must be before x, and x must be before z)
*/

/*
APPROACH:-

-> Compare every two neighbouring words. Find the first position where their letters differ: the letter from the first word comes before the letter from the second word in the alien order. This gives a directed edge between two letters. Only the first difference counts.
-> If the second word is a proper prefix of the first word (for example "abc" followed by "ab"), the list cannot be sorted in any order, so return "-1".
-> Now the problem is to find a topological order of the letters in this graph. Use Kahn's algorithm: count the indegree of every letter that appears, put the letters with indegree 0 in a queue in alphabetical order, and repeatedly take a letter, add it to the answer, and reduce the indegree of its neighbours (in alphabetical order). Push a neighbour when its indegree becomes 0.
-> If the answer has fewer letters than the number of different letters, there is a cycle, so no valid order exists. Return "-1".
-> Let N be the number of words, L the length of the longest word, and 26 the alphabet size. Comparing the words costs N * L, and Kahn's algorithm costs 26 * 26, so the time is N * L.
-> The graph takes 26 * 26 space, which is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string> &words)
{
    bool present[26];
    bool edge[26][26];
    int indegree[26];

    for (int i = 0; i < 26; i++)
    {
        present[i] = false;
        indegree[i] = 0;
        for (int j = 0; j < 26; j++)
        {
            edge[i][j] = false;
        }
    }

    for (int i = 0; i < (int)words.size(); i++)
    {
        for (int j = 0; j < (int)words[i].size(); j++)
        {
            present[words[i][j] - 'a'] = true;
        }
    }

    for (int i = 0; i + 1 < (int)words.size(); i++)
    {
        string first = words[i];
        string second = words[i + 1];
        int length = min(first.size(), second.size());
        int j = 0;

        while (j < length && first[j] == second[j])
        {
            j++;
        }

        if (j == length)
        {
            if (first.size() > second.size())
            {
                return "-1";
            }
        }
        else
        {
            int from = first[j] - 'a';
            int to = second[j] - 'a';

            if (!edge[from][to])
            {
                edge[from][to] = true;
                indegree[to]++;
            }
        }
    }

    int totalLetters = 0;
    queue<int> pending;
    for (int i = 0; i < 26; i++)
    {
        if (present[i])
        {
            totalLetters++;
            if (indegree[i] == 0)
            {
                pending.push(i);
            }
        }
    }

    string order = "";

    while (!pending.empty())
    {
        int u = pending.front();
        pending.pop();
        order += (char)('a' + u);

        for (int v = 0; v < 26; v++)
        {
            if (edge[u][v])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    pending.push(v);
                }
            }
        }
    }

    if ((int)order.size() != totalLetters)
    {
        return "-1";
    }

    return order;
}

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    cout << alienOrder(words) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * L)
SPACE COMPLEXITY = O(1)
*/
