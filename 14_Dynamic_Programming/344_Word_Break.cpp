/*
QUESTION:-

Given a string s and a dictionary of words, return true if s can be split into a
sequence of one or more dictionary words, otherwise return false. A dictionary
word may be used more than once.

Constraints:
1 <= s.length <= 300
1 <= dictionary.size() <= 1000
1 <= dictionary[i].length <= 20
s and all dictionary words contain only lowercase English letters.

Example 1:

Input:
s = "applepenapple"
dictionary = ["apple", "pen"]

Output:
true
(apple + pen + apple)

Example 2:

Input:
s = "catsandog"
dictionary = ["cats", "dog", "sand", "and", "cat"]

Output:
false
*/

/*
APPROACH:-

-> Put the dictionary words in an unordered_set so that we can check quickly whether a piece of the string is a word.
-> Let canBreak[i] be true if the first i letters of s can be split into dictionary words. canBreak[0] is true, because the empty string needs no words.
-> For every end position i from 1 to n, try every start position j before it. If canBreak[j] is true (the first j letters are fine) and the piece s[j..i-1] is in the dictionary, then the first i letters are fine too. Set canBreak[i] to true and stop looking.
-> The answer is canBreak[n].
-> Let N be the length of s. There are about N * N pairs (j, i), and for each pair, building the piece and looking it up takes up to N steps, so the time is N * N * N.
-> The canBreak array has N + 1 values and the set holds the dictionary, with D letters in total, so the space is N + D.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &dictionary)
{
    unordered_set<string> words(dictionary.begin(), dictionary.end());

    int n = s.size();
    vector<bool> canBreak(n + 1, false);
    canBreak[0] = true;

    for (int end = 1; end <= n; end++)
    {
        for (int start = 0; start < end; start++)
        {
            if (canBreak[start] && words.count(s.substr(start, end - start)) == 1)
            {
                canBreak[end] = true;
                break;
            }
        }
    }

    return canBreak[n];
}

int main()
{
    string s = "applepenapple";
    vector<string> dictionary = {"apple", "pen"};

    cout << (wordBreak(s, dictionary) ? "true" : "false") << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N * N)
SPACE COMPLEXITY = O(N + D)
*/
