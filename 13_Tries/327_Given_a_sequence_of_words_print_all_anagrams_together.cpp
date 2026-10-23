/*
QUESTION:-

Given a sequence of words, print all anagrams together. Two words are anagrams
if one can be formed by rearranging the letters of the other. Print every group
of anagrams on its own line. Groups are printed in the order in which their
first word appears, and the words of a group keep their original order.

Constraints:
1 <= words.size() <= 1000
1 <= words[i].length <= 100
words[i] contains only lowercase English letters.

Example 1:

Input:
words = ["act", "god", "cat", "dog", "tac"]

Output:
act cat tac
god dog

Example 2:

Input:
words = ["listen", "silent", "enlist", "google", "gogole"]

Output:
listen silent enlist
google gogole
*/

/*
APPROACH:-

-> Two words are anagrams exactly when their letters are the same after sorting. So the sorted word is a "key" that is the same for all words of one group.
-> Keep a map from a key to the index of its group, and a list of groups.
-> For each word, copy it, sort the copy to get the key. If the key is new, create a new empty group and remember its index.
-> Add the original word to the group of its key. Because we go through the words from left to right, the groups and the words inside them stay in the order of first appearance.
-> At the end, print the groups one per line.
-> Let N be the number of words and L the length of the longest word. Sorting one word takes L * log(L), and it is done for N words, and map lookups compare strings of length L, so the time is N * L * log(L).
-> All words are stored in the groups, so the space is N * L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &words)
{
    map<string, int> groupIndex;
    vector<vector<string>> groups;

    for (int i = 0; i < (int)words.size(); i++)
    {
        string key = words[i];
        sort(key.begin(), key.end());

        if (groupIndex.count(key) == 0)
        {
            groupIndex[key] = groups.size();
            groups.push_back(vector<string>());
        }

        groups[groupIndex[key]].push_back(words[i]);
    }

    return groups;
}

int main()
{
    vector<string> words = {"act", "god", "cat", "dog", "tac"};

    vector<vector<string>> groups = groupAnagrams(words);

    for (int g = 0; g < (int)groups.size(); g++)
    {
        for (int i = 0; i < (int)groups[g].size(); i++)
        {
            cout << groups[g][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * L * log(L))
SPACE COMPLEXITY = O(N * L)
*/
