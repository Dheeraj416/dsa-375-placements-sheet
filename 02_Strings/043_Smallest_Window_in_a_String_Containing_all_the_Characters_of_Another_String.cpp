/*
QUESTION:-

Given two strings s and t, return the smallest substring of s that contains
every character of t (including duplicates). If there is no such substring,
return an empty string "".

Constraints:
1 <= s.length, t.length <= 100000
s and t contain uppercase and lowercase English letters.

Example 1:

Input:
s = "ADOBECODEBANC"
t = "ABC"

Output:
BANC

Example 2:

Input:
s = "a"
t = "aa"

Output:
""
(there is only one 'a' in s, but two are needed)
*/

/*
APPROACH:-

-> Use a sliding window [left, right] on s and an array need[] where need[c] is how many more copies of the character c the window still requires (it can become negative when the window has extra copies).
-> Start with need[c] = the count of c in t, and missing = the total length of t (how many required characters are still not covered).
-> Move right forward. If need[s[right]] is positive, this character covers one required character, so decrease missing. Always decrease need[s[right]].
-> While missing is 0, the window contains everything. Save it if it is the shortest so far, then try to shrink it from the left: increase need[s[left]] (we give that character back), and if it becomes positive we lost a required character, so increase missing. Move left forward.
-> Repeat until right reaches the end. The best saved window is the answer, or "" if none was found.
-> Let N be the length of s. Both pointers only move forward, so the time is N.
-> The need array has 128 cells, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    vector<int> need(128, 0);

    for (char c : t)
    {
        need[c]++;
    }

    int missing = t.size();
    int left = 0;
    int bestStart = 0;
    int bestLength = INT_MAX;

    for (int right = 0; right < (int)s.size(); right++)
    {
        if (need[s[right]] > 0)
        {
            missing--;
        }
        need[s[right]]--;

        while (missing == 0)
        {
            if (right - left + 1 < bestLength)
            {
                bestLength = right - left + 1;
                bestStart = left;
            }

            need[s[left]]++;
            if (need[s[left]] > 0)
            {
                missing++;
            }
            left++;
        }
    }

    if (bestLength == INT_MAX)
    {
        return "";
    }

    return s.substr(bestStart, bestLength);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string answer = minWindow(s, t);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
