/*
QUESTION:-

A string can be shifted by replacing every letter with the next letter of the
alphabet ('z' becomes 'a'), for example "abc" becomes "bcd". Two strings belong
to the same group if one can be obtained from the other by shifting it some
number of times (so they have the same length and the differences between
their consecutive letters are the same). Given a list of lowercase strings,
group together all the strings that belong to the same shifting sequence. Print
every group on its own line, with the groups ordered by the first appearance of
their first string, and the strings in the order of the input.

Constraints:
1 <= number of strings <= 200
1 <= length of a string <= 50

Example 1:

Input:
strings = ["acd","dfg","wyz","yab","mop","bdfh","a","x","moqs"]

Output:
acd dfg wyz yab mop
bdfh moqs
a x

Example 2:

Input:
strings = ["abc","bcd","xyz","az","ba"]

Output:
abc bcd xyz
az ba
*/

/*
APPROACH:-

-> Strings of the same group look the same when each one is shifted so that its first letter becomes 'a'. So compute a key for every string: the list of differences (letter - first letter + 26) % 26 for all the letters. Strings in one group have exactly the same key.
-> Keep a hash map from the key to the index of its group, and a list of groups. For each string, compute its key. If the key is new, start a new group at the end of the list. Then add the string to its group.
-> Because groups are created when their first string is seen and strings are added in order, the output order follows the rules of the question.
-> Print every group on one line.
-> Let N be the number of strings and L the length of the longest string. Making a key costs L, so the time is N * L.
-> The map and the groups store all the strings, so the space is N * L.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string getKey(string s)
{
    string key = "";

    for (int i = 0; i < (int)s.size(); i++)
    {
        int difference = (s[i] - s[0] + 26) % 26;
        key += to_string(difference);
        key += ",";
    }

    return key;
}

vector<vector<string>> groupShifted(vector<string> &strings)
{
    unordered_map<string, int> keyToGroup;
    vector<vector<string>> groups;

    for (int i = 0; i < (int)strings.size(); i++)
    {
        string key = getKey(strings[i]);

        if (keyToGroup.count(key) == 0)
        {
            keyToGroup[key] = groups.size();
            groups.push_back(vector<string>());
        }

        groups[keyToGroup[key]].push_back(strings[i]);
    }

    return groups;
}

int main()
{
    vector<string> strings = {"acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"};

    vector<vector<string>> groups = groupShifted(strings);

    for (int i = 0; i < (int)groups.size(); i++)
    {
        for (int j = 0; j < (int)groups[i].size(); j++)
        {
            cout << groups[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * L)
SPACE COMPLEXITY = O(N * L)
*/
