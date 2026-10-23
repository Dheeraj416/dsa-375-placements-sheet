/*
QUESTION:-

Given two words beginWord and endWord, and a list of words wordList, find the
length of the shortest transformation sequence from beginWord to endWord. In
one step you can change exactly one letter, and every word you get must be in
wordList (beginWord does not have to be in the list). The length of the sequence
counts all the words in it, including beginWord and endWord. If there is no such
sequence, return 0.

Constraints:
1 <= length of a word <= 10
1 <= number of words <= 5000
All the words have the same length and contain only lowercase letters.

Example 1:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
5
(hit -> hot -> dot -> dog -> cog)

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output:
0
(the word cog is not in the list)
*/

/*
APPROACH:-

-> Think of every word as a vertex, with an edge between two words that differ in exactly one letter. The shortest transformation is the shortest path, which BFS finds.
-> Put all the words of wordList in a hash set. If endWord is not in the set, return 0.
-> Start BFS with beginWord at level 1. For the word taken from the queue, try to change each of its letters to every letter from 'a' to 'z'. If the new word is in the set, it is a neighbour.
-> When a neighbour is found, remove it from the set (so it is never used twice) and push it with level + 1. If the neighbour is endWord, return its level.
-> If the queue becomes empty, there is no sequence, so return 0.
-> Let N be the number of words and L the length of a word. Every word is pushed once, and for it we try L * 26 changes, each costing L for the set look up, so the time is N * L * L * 26, which we write as N * L * L.
-> The set and the queue take N * L space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> words(wordList.begin(), wordList.end());

    if (words.count(endWord) == 0)
    {
        return 0;
    }

    queue<pair<string, int>> pending;
    pending.push({beginWord, 1});
    words.erase(beginWord);

    while (!pending.empty())
    {
        string word = pending.front().first;
        int level = pending.front().second;
        pending.pop();

        for (int i = 0; i < (int)word.size(); i++)
        {
            char original = word[i];

            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;

                if (words.count(word) > 0)
                {
                    if (word == endWord)
                    {
                        return level + 1;
                    }

                    words.erase(word);
                    pending.push({word, level + 1});
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << ladderLength(beginWord, endWord, wordList) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * L * L)
SPACE COMPLEXITY = O(N * L)
*/
