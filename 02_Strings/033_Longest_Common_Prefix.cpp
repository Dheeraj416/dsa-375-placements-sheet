/*
QUESTION:-

Write a function to find the longest common prefix string among an array of
strings. If there is no common prefix, return an empty string.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of lowercase English letters.

Example 1:

Input:
strs = ["flower","flow","flight"]

Output:
"fl"

Example 2:

Input:
strs = ["dog","racecar","car"]

Output:
""
Explanation: There is no common prefix among the input strings.
*/

/*
APPROACH:-

-> Start by assuming the whole first string is the common prefix.
-> For every other string, compare it with the current prefix character by character and keep only the matching part.
-> To do this, find the first position where the prefix and the string differ (or where either one ends) and cut the prefix at that position.
-> If the prefix becomes empty at any time, there is no common prefix, so stop early.
-> After all the strings are processed, what is left of the prefix is common to all of them.
-> The prefix can only shrink, so the total work is bounded by S, the total number of characters in all the strings.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string prefix = strs[0];

    for (int i = 1; i < (int)strs.size(); i++)
    {
        int j = 0;

        while (j < (int)prefix.size() && j < (int)strs[i].size() && prefix[j] == strs[i][j])
        {
            j++;
        }

        prefix = prefix.substr(0, j);

        if (prefix.empty())
        {
            break;
        }
    }

    return prefix;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    string answer = longestCommonPrefix(strs);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(S)
SPACE COMPLEXITY = O(1)
*/
