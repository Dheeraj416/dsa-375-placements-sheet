/*
QUESTION:-

Given an array of strings, group the anagrams together. Two strings are anagrams
if one can be made from the other by rearranging its letters. The groups can be
returned in any order. (In the example output below every group is printed on
its own line, in alphabetical order of the sorted letters of the group.)

Constraints:
1 <= strs.length <= 10000
0 <= strs[i].length <= 100
strs[i] contains lowercase English letters.

Example 1:

Input:
strs = ["eat","tea","tan","ate","nat","bat"]

Output:
bat
eat tea ate
tan nat

Example 2:

Input:
strs = ["a"]

Output:
a
*/

/*
APPROACH:-

-> Two words are anagrams exactly when they have the same letters, so their sorted letters are the same. For "eat", "tea" and "ate" the sorted word is "aet".
-> Use a map from this sorted word (the key) to the list of original words that have this key.
-> Go through the words. For each word, make a copy, sort its letters, and push the original word into the list of that key.
-> At the end, every list in the map is one group of anagrams. A std::map keeps the keys sorted, so the groups come out in a fixed order.
-> Edge case: an empty string has the key "" and forms its own group.
-> Let N be the number of words and L the maximum length of a word. Sorting one word costs L * log L, so the time is N * L * log L.
-> The map stores all the words, so the space is N * L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<string, vector<string>> groups;

    for (string word : strs)
    {
        string key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    vector<vector<string>> result;

    for (pair<string, vector<string>> entry : groups)
    {
        result.push_back(entry.second);
    }

    return result;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> answer = groupAnagrams(strs);

    for (vector<string> &group : answer)
    {
        for (string &word : group)
        {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * L * log L)
SPACE COMPLEXITY = O(N * L)
*/
